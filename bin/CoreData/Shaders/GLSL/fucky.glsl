#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"

varying vec2 vTexCoord;
varying vec2 vScreenPos;

//uniform vec2 cPixelSize = vec2(0.005, 0.005);
uniform float cFar; 

uniform float cFocusScale; 
uniform float cFocalPlane; 
uniform float cAperture; 

// Viewport Height / 24mm (The vertical size of 35mm format) - used to convert between mm and relative px
uniform float cSizeOverFormat;

uniform float cResWidth;

const float GOLDEN_ANGLE = 2.39996323;
const float MAX_BLUR_SIZE = 25.0;
const float RAD_SCALE = 0.5;
const float FOCAL_LENGTH = 0.045; //45 mm. 1 sceneunit = 1m, ish?
const float FOCAL_LENGTH_MM = 45.0; //45 mm. 1 sceneunit = 1m, ish?
// Every scene unit is about 2 metres?
const float SCENEUNITS_IN_M = 0.75;

void VS() {
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
}

#ifdef COMPILEPS

float getBlurSize(float depth, float focusPoint, float focusScale) {
	float coc = clamp((1.0 / focusPoint - 1.0 / depth)*focusScale, -1.0, 1.0);
	//float coc = clamp((depth - focusPoint)*focusScale, -1.0, 1.0);
	
	// Done as a proportion of the maximum blur
	return abs(coc) * MAX_BLUR_SIZE;
}

// Radius is in pixels. Conversion from absolute to mm is done here.
// Viewport/Texture resolution MUST BE IN 2:3 TO BE CORRECT
float getCoCBlurRadius(float depth, float focalPlane, float aperture ) {
	// objectdistance -> depth, planeinfocus -> focalPlane
	float CoC = abs(aperture * (FOCAL_LENGTH * (depth - focalPlane)) / (depth * (focalPlane - FOCAL_LENGTH)));
	// Multiplying by MAX_BLUR_SIZE seems like cheating...
	return MAX_BLUR_SIZE * CoC / cSizeOverFormat;
}

float getCoCBlurRadiusNvidia(float depth, float focalPlane, float aperture) {
	// N = f/D
	// Aperture -> diameter : D = f/N
	float D = FOCAL_LENGTH_MM / aperture;
	
	// focalPlane and depth are 0-1 based on scene depth, linear.
	
	//Weirdly, FOCAL_LENTH_MM is in mm, D is in mm, but the other two depth vars are in metres...
	
	float CoC = D * abs(FOCAL_LENGTH_MM / (focalPlane - FOCAL_LENGTH_MM)) * abs(1 - (focalPlane/depth));
	CoC = min(60, CoC); // Limit to 75mm
	//return 7.0 * CoC / cSizeOverFormat; //mm to px
	return 7.0 * CoC / cSizeOverFormat; //mm to px
}

float getCoCBlurRadiusGit(float depth, float focalPlane, float aperture) {
	depth *= cFar * 1000.0;
	focalPlane *= cFar * 1000.0;
	
	float a = (depth * FOCAL_LENGTH_MM) / (depth - FOCAL_LENGTH_MM);
	float b = (focalPlane * FOCAL_LENGTH_MM) / (focalPlane - FOCAL_LENGTH_MM);
	float c = (focalPlane - FOCAL_LENGTH_MM) / (depth * aperture * 0.03);
	float CoC = abs(a-b) * c;
	
	return CoC / cSizeOverFormat;
}

// Alle Eingaben sind in Metern.
// Von: desmos.com/calculator/j2gcokbykz
// TODO!!!: Move all but depth to use the uniforms
float getCoCBlurRadiusSE(float depth, float focalPlane, float aperture) {
	float F_M = FOCAL_LENGTH_MM / 1000;
	float f = focalPlane * cFar * SCENEUNITS_IN_M;
	float d = depth * cFar * SCENEUNITS_IN_M;
	float N = aperture;
	
	float a =  abs(d - f)/d;
	float b = (F_M * F_M) / (N * (f - F_M));
	float c = (cResWidth*1000) / 36; //Dividing 36 by 1000 is harder than just simplifying it.
	//return min(a * b * c, 60.0);
	return a * b * c;
}

float getCoC(float depth, float focalPlane, float aperture) {
	return getCoCBlurRadiusSE(depth, focalPlane, aperture);
}

vec3 depthOfField(vec2 texCoord, float focusPoint, float focusScale, sampler2D diffTexture, sampler2D depthTexture) {
	float centerDepth = ReconstructDepth(texture2D(depthTexture, texCoord).r);
	//float centerSize = getBlurSize(centerDepth, focusPoint, focusScale);
	// float centerSize = getCoCBlurRadiusNvidia(centerDepth, focusPoint, cAperture);
	float centerSize = getCoC(centerDepth, focusPoint, cAperture);
	
	#ifdef DEBUGMODE
		//return vec3(centerSize / MAX_BLUR_SIZE);
		return vec3(centerSize) / 15.0;
	#endif
	
	vec3 color = texture2D(diffTexture, texCoord).rgb; // Previously had vTexCoord
	float tot = 1.0;

	float radius = RAD_SCALE;
	
	// Spiral around and sample, using golden angle
	for (float ang = 0.0; radius < MAX_BLUR_SIZE; ang += GOLDEN_ANGLE) {
	
		//cGBufferInvSize.xy is the inverse of the viewport dimensions, i.e. pixel size
		vec2 tc = texCoord + vec2(cos(ang), sin(ang)) * cGBufferInvSize.xy * radius;

		vec3 sampleColor = texture2D(diffTexture, tc).rgb;
		float sampleDepth = ReconstructDepth(texture2D(depthTexture, tc).r);
		//float sampleSize = getBlurSize(sampleDepth, focusPoint, focusScale);
		// float sampleSize = getCoCBlurRadiusNvidia(sampleDepth, focusPoint, cAperture);
		float sampleSize = getCoC(sampleDepth, focusPoint, cAperture);
		
		if (sampleDepth > centerDepth) {
			sampleSize = clamp(sampleSize, 0.0, centerSize*2.0);
		}

		float m = smoothstep(radius-0.5, radius+0.5, sampleSize);
		color += mix(color/tot, sampleColor, m);
		tot += 1.0;
		radius += RAD_SCALE/radius;
	}
	return color /= tot;
}

#endif

void PS() {
	// centre coord, focal point, focal scale, diffuse, depth
	gl_FragColor = vec4(
	depthOfField(vTexCoord, 0.007/(1-cFocalPlane), cFocusScale, sDiffMap, sDepthBuffer),
	1.0);
}