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

const float GOLDEN_ANGLE = 2.39996323;
const float MAX_BLUR_SIZE = 20.0;
const float RAD_SCALE = 0.5;

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
	return abs(coc) * MAX_BLUR_SIZE;
}

vec3 depthOfField(vec2 texCoord, float focusPoint, float focusScale, sampler2D diffTexture, sampler2D depthTexture) {
	float centerDepth = ReconstructDepth(texture2D(depthTexture, texCoord).r) * cFar;
	float centerSize = getBlurSize(centerDepth, focusPoint, focusScale);
	
	#ifdef DEBUGMODE
		return vec3(centerSize);
	#endif
	
	vec3 color = texture2D(diffTexture, texCoord).rgb; // Previously had vTexCoord
	float tot = 1.0;

	float radius = RAD_SCALE;
	
	// Spiral around and sample, using golden angle
	for (float ang = 0.0; radius < MAX_BLUR_SIZE; ang += GOLDEN_ANGLE) {
	
		//cGBufferInvSize.xy is the inverse of the viewport dimensions, i.e. pixel size
		vec2 tc = texCoord + vec2(cos(ang), sin(ang)) * cGBufferInvSize.xy * radius;

		vec3 sampleColor = texture2D(diffTexture, tc).rgb;
		float sampleDepth = ReconstructDepth(texture2D(depthTexture, tc).r) * cFar;
		float sampleSize = getBlurSize(sampleDepth, focusPoint, focusScale);
		
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
	depthOfField(vTexCoord, cFocalPlane, cFocusScale, sDiffMap, sDepthBuffer),
	1.0);
}