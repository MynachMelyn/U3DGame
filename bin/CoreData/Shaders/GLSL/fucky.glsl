#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"

varying vec2 vTexCoord;
varying vec2 vScreenPos;

//uniform vec2 cPixelSize = vec2(0.005, 0.005);
uniform float cFar; 

uniform float cFocusScale; 
uniform float cFWheel; // Wheel amount, 0-1
uniform float cAperture; 
uniform float cFocalLengthMM; 

// Viewport Height / 24mm (The vertical size of 35mm format) - used to convert between mm and relative px
uniform float cSizeOverFormat;

uniform float cResWidth;

const float GOLDEN_ANGLE = 2.39996323;
const float MAX_BLUR_SIZE = 10.0; //20-25
const float RAD_SCALE = 0.5;
// Every scene unit is about X metres?
const float SCENEUNITS_IN_M = 0.75;

void VS() {
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
}

#ifdef COMPILEPS
// Alle Eingaben sind in Metern.
// Von: desmos.com/calculator/j2gcokbykz
float getCoCBlurRadiusSE(float depth) {
	float F_M = cFocalLengthMM / 1000;
	float f = cFar * SCENEUNITS_IN_M * 0.006/(1-cFWheel); // min/(1-wheel) to get exponential increase;
	float d = depth * cFar * SCENEUNITS_IN_M;
	float N = cAperture;
	
	float a =  abs(d - f)/d;
	float b = (F_M * F_M) / (N * (f - F_M));
	float c = (cResWidth*1000) / 36; //Dividing 36 by 1000 is harder than just simplifying it.
	//return min(a * b * c, 60.0);
	return a * b * c;
}


vec3 depthOfField(vec2 texCoord, float focusScale, sampler2D diffTexture, sampler2D depthTexture) {
	float centerDepth = ReconstructDepth(texture2D(depthTexture, texCoord).r);
	//float centerSize = getBlurSize(centerDepth, focusPoint, focusScale);
	// float centerSize = getCoCBlurRadiusNvidia(centerDepth, focusPoint, cAperture);
	float centerSize = getCoCBlurRadiusSE(centerDepth);
	
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
		float sampleSize = getCoCBlurRadiusSE(sampleDepth);
		
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
	depthOfField(vTexCoord, cFocusScale, sDiffMap, sDepthBuffer),
	1.0);
}