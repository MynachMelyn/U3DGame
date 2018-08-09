function compute_dof()
{
	var f = document.dof_calculator;
	var dist = f.dist.value;
	var chart_start, chart_end;

	if (f.units.value.search(/meters/i) != -1)
		dist = dist * 1000 * mm_2_feet;

	var coc_mm = f.coc.value;
	var coc = coc_mm * mm_2_feet;

	var flen_mm = f.flen.value;
	var flen = flen_mm * mm_2_feet;

	var aperture = f.aperture.value;

	if (isNaN(flen_mm) || isNaN(coc_mm) || isNaN(dist) || isNaN(aperture))
		{
		alert("Error: At least one of the input fields contains non-numeric characters");
		return;
		}

	// Depth of field formula from:
	// "Focal Encylopedia of Photography", Macmillan Company, New York, 1960
	var tmp = (aperture*coc*(dist-flen))/(flen*flen);
	var dist_far = (tmp>=1) ? "inf" : dist / (1 - tmp);
	var dist_near = dist  / (1 + tmp);
	var depth_of_field = (tmp<1) ? (dist_far - dist_near) : "inf";
	var hyper_focal = (flen*flen)/(aperture*coc);

	var depth_of_focus = (flen*flen*dist)/(hyper_focal*(dist-flen));
	//airy_disk_diam = 2.43932 x light_wave_length x fnum
	var airy_disk_diam = 2.43932 * (510 * .000001) * aperture;

	if (f.units.value.search(/feet/i) != -1)
	{
		f.near_dist.value = feet_inches(dist_near);
		f.far_dist.value = feet_inches(dist_far);
		f.depth_of_field.value = feet_inches(depth_of_field);
		f.depth_of_focus.value = dec4(depth_of_focus*12) + "\"";
		f.hyper_dist.value = feet_inches(hyper_focal);
	}
	else
	{
		f.near_dist.value = meters(dist_near);
		f.far_dist.value = meters(dist_far);
		f.depth_of_field.value = meters(depth_of_field);
		f.depth_of_focus.value = dec4((feet_2_mm * depth_of_focus)/10) + "cm";
		f.hyper_dist.value = meters(hyper_focal);
	}

	f.airy_disk_diameter.value = dec3(airy_disk_diam);


	if (depth_of_field == "inf")
	{
		chart_start = Math.max(0, (+dist) * 0.25);
		chart_end   = (+dist) * 4;
	}
	else
	{
		chart_start = Math.max(0, (+dist) - depth_of_field);
		chart_end   = (+dist) + depth_of_field;
	}

	var show_in_meters = 0;
	if (f.units.value.search(/meters/i)!=-1) show_in_meters = 1;

	show_blur_chart(f.aperture.value, f.coc.value, f.flen.value, dist, dist_near, dist_far, chart_start, chart_end, f.chkAddDiffraction.checked, show_in_meters);


}



//All input distance data is in feet
function show_blur_chart(aperture, coc, flen, focus_distance, focus_near, focus_far, chart_distance_start, chart_distance_end, add_diffraction, show_in_meters)
{
	var url="http://chart.apis.google.com/chart?cht=lxy&chs=400x300&chco=3072F3,ff0000,00aaaa&chls=2&chm=s,FF0000,0,-1,5|s,0000ff,1,-1,5|s,00aa00,2,-1,5&chma=20,20,20,20"
	var x_axis = "", y_axis = "";

	var blur, factor, i, d;
	var max_coc_chart = dec2(coc*2);


	var focus_distance_mm = focus_distance * feet_2_mm;
	var chart_distance_start_mm = feet_2_mm*chart_distance_start;
	var chart_distance_end_mm = feet_2_mm*chart_distance_end;
	var total_dist = chart_distance_end_mm - chart_distance_start_mm;
	var increment = total_dist / 40;
	var rayleigh_dist = 1.22 * (510 * .000001) * aperture;

	for (d=chart_distance_start_mm; d<=chart_distance_end_mm; d+=increment)
	{
		//Calculate blur at distance of "d"
		blur = Math.abs(
		(flen * flen * (1-focus_distance_mm/d))/
		(aperture * (focus_distance_mm-flen))
		);

		if (blur <= max_coc_chart)
		{
			x_axis += (x_axis.length>0 ? "," : "") + dec5(d * mm_2_feet);
			y_axis += (y_axis.length>0 ? "," : "") + dec5(blur + (add_diffraction ? rayleigh_dist : 0) );

			//Insert exact focus point
			if (d < focus_distance_mm && d + increment > focus_distance_mm)
			{
				x_axis += (x_axis.length>0 ? "," : "") + dec5(focus_distance);
				y_axis += (y_axis.length>0 ? "," : "") + (add_diffraction ? rayleigh_dist : 0);
			}
		}
	}

	//Chart title
	url += "&chtt=Focus%20vs%20Distance|(Distance=";
	url += show_in_meters ? dec1(focus_distance * feet_2_mm/1000) + "%20meters" : dec1(focus_distance) + "%20feet";
	url += ",%20f" + aperture + ",%20" + flen + "mm)";

	//Specify which axes should be printed
	url += "&chxt=x,y,x,y";

	//Show tick marks along bottom axis (axis 0)
	url += "&chxs=0,,12,0,lt,";

	//Chart data
	url += "&chd=t:" + x_axis + "|" + y_axis;

	//Data scale (used by Google Charts API to give context (i.e. position) to data points)
	url += "&chds=" + chart_distance_start + "," + chart_distance_end + ",0," + max_coc_chart;

	//Data range ("in focus zone") marker
	url += "&chm=R,E5ECF9,0," +  (focus_near * feet_2_mm - chart_distance_start_mm) / total_dist + "," + (focus_far == "inf" ? 1 : (focus_far  * feet_2_mm - chart_distance_start_mm) / total_dist);

	//Data range ("coc") marker
	url += "|r,F98888,0," + coc/max_coc_chart + "," + (.005 + coc/max_coc_chart);

	//Data range ("rayleigh") marker
	url += "|r,66d988,0," + rayleigh_dist/max_coc_chart + "," + (.005 +rayleigh_dist/max_coc_chart);

	 //Data point labels
	//url += "&chm=N,0000FF,0,-5,10";

	//X Axis labels
	url += "&chxl=0:|";
	increment = (chart_distance_end_mm - chart_distance_start_mm) / 8;
	for (i=0; i<=8; i++)
	{
		d = chart_distance_start_mm + (i * increment);
		factor = show_in_meters>0 ? .001 : mm_2_feet;
		url += (d>4500 ? dec0(d * factor) : d>610 ? dec1(d * factor) : dec2(d * factor)) + "|";

	}

	//Y Axis labels
	url += "1:|";
	increment = (max_coc_chart / 8);
	for (i=0; i<=8; i++)
	{
		url += dec4(i * increment) + "|";
	}

	//Use "axes 2 and 3" to show series labels
	url += "2:|Distance" + (show_in_meters ? "%20(meters)" : "%20(feet)") + "|3:|Blur%20(mm)";

	//Position the series labels in the center of the axes
	url += "&chxp=2,50|3,50";

	//alert(url);

	document.getElementById("blur_chart").src=url;
}
