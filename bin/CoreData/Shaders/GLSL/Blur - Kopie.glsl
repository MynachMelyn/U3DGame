#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "PostProcess.glsl"

varying vec2 vTexCoord;
varying vec2 vScreenPos;

#ifdef COMPILEPS
uniform vec2 cBlurDir;
uniform float cBlurRadius;
uniform float cBlurSigma;
uniform vec2 cBlurHInvSize; // I HAVE NO IDEA WHAT THIS IS OR WHERE IT COMES FROM

//NEW
#if defined(BLURDOF) || defined(BLURDOFDEBUG)
uniform float cBlurClamp;  // max blur amount
uniform float cBias; //aperture - bigger values for shallower depth of field
uniform float cFocus;  // this value comes from ReadDepth script.
uniform float cProximityMultiplier;
#endif

#endif

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
}

void PS()
{
    #ifdef BLUR3
        gl_FragColor = GaussianBlur(3, cBlurDir, cBlurHInvSize * cBlurRadius, cBlurSigma, sDiffMap, vTexCoord);
    #endif

    #ifdef BLUR5
        gl_FragColor = GaussianBlur(5, cBlurDir, cBlurHInvSize * cBlurRadius, cBlurSigma, sDiffMap, vTexCoord);
    #endif

    #ifdef BLUR7
        gl_FragColor = GaussianBlur(7, cBlurDir, cBlurHInvSize * cBlurRadius, cBlurSigma, sDiffMap, vTexCoord);
    #endif

    #ifdef BLUR9
        gl_FragColor = GaussianBlur(9, cBlurDir, cBlurHInvSize * cBlurRadius, cBlurSigma, sDiffMap, vTexCoord);
    #endif
	
	#ifdef BLURDOF
		float depth = 10 * ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );
		float factor = clamp( ( depth - cFocus ) * cBias, -cBlurClamp, cBlurClamp );
		if(factor < 0.0) {
			factor *= cProximityMultiplier;
		}
		float dofblur = abs(factor);
	
		gl_FragColor = GaussianBlur(9, cBlurDir, cBlurHInvSize * cBlurRadius * dofblur, cBlurSigma * dofblur, sDiffMap, vTexCoord);
	#endif
	
	#ifdef BLURDOFDEBUG
		float depth = 10 * ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );
		float factor = clamp( ( depth - cFocus ) * cBias, -cBlurClamp, cBlurClamp );
		if(factor < 0.0) {
			factor *= cProximityMultiplier;
		}

		if(factor < 0.0) {
			gl_FragColor = vec4(-factor, 0, 0, 1.0);		
		} else {
			gl_FragColor = vec4(factor);
		}
	#endif
}
