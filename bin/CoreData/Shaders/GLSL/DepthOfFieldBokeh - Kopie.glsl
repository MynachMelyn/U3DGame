#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "Lighting.glsl"

varying vec2 vScreenPos;
varying vec2 vTexCoord;
varying vec2 vScreenPosFull;

#ifdef COMPILEPS

uniform float cBlurClamp;  // max blur amount
uniform float cBias; //aperture - bigger values for shallower depth of field
uniform float cFocus;  // this value comes from ReadDepth script.

uniform float cFocalLength;
uniform float cFocalPlane;
uniform float czFar;
uniform float czNear;

float normpdf(in float x, in float sigma) {
    return 0.39894*exp(-0.5*x*x/(sigma*sigma))/sigma;
}

vec3 OnePassBlur(sampler2D texSampler, vec2 texCoord, float blurScale) {
    //declare stuff
    const int mSize = 9;
    const int kSize = (mSize-1)/2;
    float kernel[mSize];
    vec3 final_colour = vec3(0.0);
    
    //create the 1-D kernel
    float sigma = 7.0;
    float Z = 0.0;
    for (int j = 0; j <= kSize; ++j)
    {
        kernel[kSize+j] = kernel[kSize-j] = normpdf(float(j), sigma);
    }
    
    //get the normalization factor (as the gaussian has been clamped)
    for (int j = 0; j < mSize; ++j)
    {
        Z += kernel[j];
    }
    
    //read out the texels
    for (int i=-kSize; i <= kSize; ++i)
    {
        for (int j=-kSize; j <= kSize; ++j)
        {
            final_colour += kernel[kSize+j]*kernel[kSize+i]*texture2D(texSampler, (texCoord.xy+ blurScale * vec2(float(i),float(j)))).rgb;

        }
    }
        
        
    return final_colour/(Z*Z);
}

vec4 blur13(sampler2D image, vec2 uv, vec2 resolution, vec2 direction) {
  vec4 color = vec4(0.0);
  vec2 off1 = vec2(1.411764705882353) * direction;
  vec2 off2 = vec2(3.2941176470588234) * direction;
  vec2 off3 = vec2(5.176470588235294) * direction;
  color += texture2D(image, uv) * 0.1964825501511404;
  color += texture2D(image, uv + (off1 / resolution)) * 0.2969069646728344;
  color += texture2D(image, uv - (off1 / resolution)) * 0.2969069646728344;
  color += texture2D(image, uv + (off2 / resolution)) * 0.09447039785044732;
  color += texture2D(image, uv - (off2 / resolution)) * 0.09447039785044732;
  color += texture2D(image, uv + (off3 / resolution)) * 0.010381362401148057;
  color += texture2D(image, uv - (off3 / resolution)) * 0.010381362401148057;
  return color;
}

// float CircleOfConfusion(float focalLength, float focalPlane, float zFar, float zNear, float rawDepth) {
	// float A = 4.5;
	// float CoCScale = (A * focalLength * focalPlane * (zFar-zNear)) / ((focalPlane - focalLength) * zNear * zFar);
	// float CoCBias = (A * focalLength * (zNear - focalPlane)) / ((focalPlane * focalLength) * zNear);
	// return abs(rawDepth * CoCScale + CoCBias);
// }

// float NewCoC(float F, float zNear, float zFar, float focalPlane, float focalLength) {
	// float A = 20.0;
	// float F = focalLength;
	// float P = focalPlane;
	// float D = rawDepth;
	// return abs(A * (F * (P - D))/(D * (P - F)))
// }

// z dist we wish to focus on, s is the constant scale factor relative to cam setup??
// float getCOCDiameter(float zF, float S, float N, float F, float D) {
	// //return abs(S * (1 - (zF/N)) + (S*zF*((F-N)/(N*F)))*D);
	// return 1.0;
// }

float CircleOfConfusionNoConvert() {
	return = scalef * abs(1 - (zFocus / z));
}

#endif


void VS() {
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPosFull = GetScreenPos(gl_Position).xy;
}

void PS() {

    //float aspectratio = 800.0/800.0;
	float aspectratio = textureSize(sDiffMap, 0).x / textureSize(sDiffMap, 0).y;
    vec2 aspectcorrect = vec2(1.0, aspectratio);
    aspectcorrect *= 0.1;
    
	//TODO: is vTexCoord any different from vScreenPos?
	float depth = ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );

    float factor = ( depth - cFocus );     
    vec2 dofblur = vec2 (abs(clamp( factor * cBias, -cBlurClamp, cBlurClamp )));
	
    //col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,-0.29 )*aspectcorrect) * dofblur*0.4);   
	
	
	//float CoC = getCOCDiameter(150.0, 1.0, 1.0, 300.0, depth) / 5;
	float CoC = CircleOfConfusion( cFocalLength, cFocalPlane, czFar, czNear, depth);

	//ORIGINAL
    #ifndef DEBUGMODE
		//gl_FragColor = finalColour / weight; // DIVIDE BY NUMBER OF LAYERED SAMPLES
		//gl_FragColor = vec4(OnePassBlur(sDiffMap, vTexCoord, dofblur.x / 100.0), 1.0);
		gl_FragColor = vec4(OnePassBlur(sDiffMap, vTexCoord, 0.0), 1.0);
	#endif
	
	#ifdef DEBUGMODE
		//gl_FragColor = vec4(dofblur, dofblur);
		gl_FragColor = vec4(CoC);
	#endif
	
	gl_FragColor.a = 1.0;
	
    //gl_FragColor = vec4(vScreenPosFull.x, vScreenPosFull.y, 1.0, 1.0);
}