#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"

varying vec2 vTexCoord;
varying vec2 vScreenPos;

uniform vec2 cRTDimensions;
uniform vec2 cLowResDimensions;

const int COLOUR_LIMITER_STEPS = 15;

void VS() {
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
}

void PS() {
	// centre coord, focal point, focal scale, diffuse, depth
	// gl_FragColor = vec4(
	// depthOfField(vTexCoord, cFocusScale, sDiffMap, sDepthBuffer),
	// 1.0);
	vec2 uv = vTexCoord.xy;
	
	float dx = cLowResDimensions.x * (1.0 / cRTDimensions.x);
	float dy = cLowResDimensions.y * (1.0 / cRTDimensions.y);
	
	vec2 coord = vec2(dx * floor(uv.x/dx), dy * floor(uv.y/dy));
	
	vec3 col = texture2D(sDiffMap, coord).rgb;
	col *= COLOUR_LIMITER_STEPS;
	col = round(col);
	col /= COLOUR_LIMITER_STEPS;
	
	gl_FragColor = vec4(col, 1.0);
	// gl_FragColor = vec4(1.0);
}