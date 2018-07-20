#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"

varying vec2 vTexCoord;
varying vec2 vScreenPos;

//#ifdef COMPILEPS
uniform vec2 cPixelSize; //The size of a pixel: vec2(1.0/width, 1.0/height)
uniform float cFar = 0.0; // Far plane

const float GOLDEN_ANGLE = 2.39996323;
const float MAX_BLUR_SIZE = 20.0;
const float RAD_SCALE = 0.5; // Smaller = nicer blur, larger = faster

uniform float cBlurClamp; // max blur amount
uniform float cBias; 	  //aperture - bigger values for shallower depth of field
uniform float cFocus;
uniform float cProximityMultiplier;
// cFocus -> focusPoint
// cBias -> focusScale
//#endif

void VS() {
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
}

float getBlurSize(float depth, float focusPoint, float focusScale) {
	float coc = clamp((1.0 / focusPoint - 1.0 / depth)*focusScale, -1.0, 1.0);
	return abs(coc) * MAX_BLUR_SIZE;
}

// Centre tex coord, focal plane as proportion of available depth, blur scale/bias, source texture, source depth
// vec3 depthOfField(vec2 texCoord, float focusPoint, float focusScale, sampler2D diffTexture, sampler2D depthTexture) {
	// float centerDepth = ReconstructDepth(texture2D(depthTexture, texCoord).r) * cFar;
	// float centerSize = getBlurSize(centerDepth, focusPoint, focusScale);
	
	// vec3 color = texture2D(diffTexture, texCoord).rgb; // Previously had vTexCoord
	// float tot = 1.0;

	// float radius = RAD_SCALE;
	
	// // Spiral around and sample, using golden angle
	// for (float ang = 0.0; radius < MAX_BLUR_SIZE; ang += GOLDEN_ANGLE) {
		// vec2 tc = texCoord + vec2(cos(ang), sin(ang)) * cPixelSize * radius;

		// vec3 sampleColor = texture2D(diffTexture, tc).rgb;
		// float sampleDepth = ReconstructDepth(texture2D(depthTexture, tc).r) * cFar;
		// float sampleSize = getBlurSize(sampleDepth, focusPoint, focusScale);
		
		// if (sampleDepth > centerDepth) {
			// sampleSize = clamp(sampleSize, 0.0, centerSize*2.0);
		// }

		// float m = smoothstep(radius-0.5, radius+0.5, sampleSize);
		// color += mix(color/tot, sampleColor, m);
		// tot += 1.0;
		// radius += RAD_SCALE/radius;
	// }
	// return color /= tot;
// }

vec3 depthOfField(vec2 texCoord, float focusPoint, float focusScale, sampler2D diffTexture, sampler2D depthTexture) {
	float centerDepth = texture2D(sDepthBuffer, vTexCoord).r;
	// float centerSize = getBlurSize(0.0, focusPoint, focusScale);
	
	vec3 color = texture2D(diffTexture, texCoord).rgb; // Previously had vTexCoord
	float tot = 1.0;

	float radius = RAD_SCALE;
	return color /= tot;
	return vec3(0.0);
}

void PS() {
	// Set pixel size
	
		// vec2 dimensions = textureSize(sDiffMap).xy;
		// vec2 blabla = vec2(1 / dimensions.x, 1 / dimensions.y);
		// cPixelSize = vec2(0.0);
		// SET THIS IN CODE
	
	
	// I am not sure which values this ought to be, given that we've got focal point as a 
	// proportion of depth and thus the far plane should be 1.0 by default. This is multiplied into
	// the depth that gets read at the centre and the samples. 
	// I imagine the focal point is supposed to be a world pos, and the far plane is supposed to 
	// be world pos too.
	// SET FAR IN PREPASS OR IN CODE
	
	// To test for nice values - change the radius value
	// vec4 = vec4(vec3,1) MAY NOT WORK FOR SYNTAX
	// = depthOfField(vTexCoord, 0.5, 1.0, sDiffMap, sDepthBuffer);
	gl_FragColor = vec4(1.0, 0.0, 0.05, 1.0);
}