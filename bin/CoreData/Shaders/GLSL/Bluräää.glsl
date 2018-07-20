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

float getCoC(float depth) {
	// Lazy, but all of these *are* technically accessible from here, in this scope
	// Multiplying the depth by ten works for our chosen values, and doesn't make too much impact on the depth comparison later.
	float factor = clamp( ( depth - cFocus ) * cBias, -cBlurClamp, cBlurClamp );
	if(factor < 0.0) {
		factor *= cProximityMultiplier;
	}
	return float(abs(factor));
}

float magicalFunction(float x) {
	return (1 / (1 - pow(x + 0.1, 4))) - 1;
}

// Does Gaussian blur whilst taking into account the depth difference and difference in CoC
vec4 GaussianBlurDoF(int blurKernelSize, vec2 blurDir, vec2 blurRadius, float sigma, sampler2D texSampler, vec2 texCoord) {
	// Get the depth and coc of the current pixel - TODO move this to the main pixel shader later
	float depth = 10 * ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );
	//float coc = getCoC(depth);	
	
    int blurKernelSizeHalfSize = blurKernelSize / 2;

    // Incremental Gaussian Coefficent Calculation (See GPU Gems 3 pp. 877 - 889)
    vec3 gaussCoeff;
    gaussCoeff.x = 1.0 / (sqrt(2.0 * PI) * sigma);
    gaussCoeff.y = exp(-0.5 / (sigma * sigma));
    gaussCoeff.z = gaussCoeff.y * gaussCoeff.y;

    vec2 blurVec = blurRadius * blurDir;
    vec4 avgValue = vec4(0.0);
    float gaussCoeffSum = 0.0;

	// Take one sample from the centre, the pivot texel, to start
    avgValue += texture2D(texSampler, texCoord) * gaussCoeff.x;
    gaussCoeffSum += gaussCoeff.x;
    gaussCoeff.xy *= gaussCoeff.yz;

	// The problem here is: how do we reject sampling and take said rejection into account in the gaussian coefficient sum?
	
    for (int i = 1; i <= blurKernelSizeHalfSize; i++) {
		vec2 sampleCoordPos = texCoord + float(i) * blurVec;
		vec2 sampleCoordNeg = texCoord - float(i) * blurVec;
		
		// Get depth at the sample point
		float sampleDepth = 10 * ReconstructDepth( texture2D(sDepthBuffer, sampleCoordPos).r );
		
		// Get the influence of the CoC on the depth rejection, which is similar to a log graph (but cheaper)
		float cocInfluence = magicalFunction(getCoC(sampleDepth));
				
		{ // New Scope to separate likenamed vars
			// The higher the delta, the higher the rejection amount
			float delta = ((depth - sampleDepth) / 10.0) * cocInfluence; // May want to clamp this formally
			if(delta > 0) {
				vec3 colourA = texture2D(texSampler, sampleCoordPos).rgb;
				vec3 colourB = texture2D(texSampler, texCoord).rgb;
				avgValue += vec4( (colourB.r - colourA.r)*delta + colourA.r, (colourB.g - colourA.g)*delta + colourA.g, (colourB.b - colourA.b)*delta + colourA.b, 1.0 ) * gaussCoeff.x;
				// avgValue += texture2D(texSampler, texCoord) * gaussCoeff.x;
			} else {
				avgValue += texture2D(texSampler, sampleCoordPos) * gaussCoeff.x;
			}
		}
		
		
		
		// Get depth at the sample point
		float sampleDepth = 10 * ReconstructDepth( texture2D(sDepthBuffer, sampleCoordNeg).r );
		
		// Get the influence of the CoC on the depth rejection, which is similar to a log graph (but cheaper)
		float cocInfluence = magicalFunction(getCoC(sampleDepth));
				
		{ // New Scope to separate likenamed vars
			// The higher the delta, the higher the rejection amount
			float delta = ((depth - sampleDepth) / 10.0) * cocInfluence; // May want to clamp this formally
			if(delta > 0) {
				vec3 colourA = texture2D(texSampler, sampleCoordNeg).rgb;
				vec3 colourB = texture2D(texSampler, texCoord).rgb;
				avgValue += vec4( (colourB.r - colourA.r)*delta + colourA.r, (colourB.g - colourA.g)*delta + colourA.g, (colourB.b - colourA.b)*delta + colourA.b, 1.0 ) * gaussCoeff.x;
				// avgValue += texture2D(texSampler, texCoord) * gaussCoeff.x;
			} else {
				avgValue += texture2D(texSampler, sampleCoordNeg) * gaussCoeff.x;
			}
		}
		
		
		
		// if(sampleCoC < 0.1 && depth > sampleDepth) {
			// // REJECT
			// avgValue += texture2D(texSampler, texCoord) * gaussCoeff.x;
		// } else {
			// // ACCEPT
			// avgValue += texture2D(texSampler, sampleCoordNeg) * gaussCoeff.x;
		// }        

        gaussCoeffSum += 2.0 * gaussCoeff.x;
		
		// I believe this line just proceeds to the next gaussian values needed to sample, 
		// so we ALWAYS do it regardless of whether or not we reject
        gaussCoeff.xy *= gaussCoeff.yz;
    }

    return avgValue / gaussCoeffSum;
}


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
	
		//gl_FragColor = GaussianBlur(9, cBlurDir, cBlurHInvSize * cBlurRadius * dofblur, cBlurSigma * dofblur, sDiffMap, vTexCoord);
		gl_FragColor = GaussianBlurDoF(9, cBlurDir, cBlurHInvSize * cBlurRadius * dofblur, cBlurSigma * dofblur, sDiffMap, vTexCoord);
		
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
