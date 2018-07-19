#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "Lighting.glsl"
#include "PostProcess.glsl"

varying vec2 vScreenPos;
varying vec2 vTexCoord;
varying vec2 vScreenPosFull;

#ifdef COMPILEPS

uniform float cBlurClamp;  // max blur amount
uniform float cBias; //aperture - bigger values for shallower depth of field
uniform float cFocus;  // this value comes from ReadDepth script.

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

float basicCOC(float depth, float focus, float bias, float blurClamp) {
	float f = clamp((depth - focus) * bias, -blurClamp, blurClamp);
    return float(abs(f));
}

const vec2 samples[40] = vec2[40](
    vec2( 0.0,0.4 ),
    vec2( 0.15,0.37 ),
    vec2( 0.29,0.29 ),
    vec2( -0.37,0.15 ),
    vec2( 0.4,0.0 ),
    vec2( 0.37,-0.15 ),
    vec2( 0.29,-0.29 ),
    vec2( -0.15,-0.37 ),
    vec2( 0.0,-0.4 ),
    vec2( -0.15,0.37 ),
    vec2( -0.29,0.29 ),
    vec2( 0.37,0.15 ),
    vec2( -0.4,0.0 ),
    vec2( -0.37,-0.15 ),
    vec2( -0.29,-0.29 ),
    vec2( 0.15,-0.37 ),
    vec2( 0.15,0.37 ),
    vec2( -0.37,0.15 ),
    vec2( 0.37,-0.15 ),
    vec2( -0.15,-0.37 ),
    vec2( -0.15,0.37 ),
    vec2( 0.37,0.15 ),
    vec2( -0.37,-0.15 ),
    vec2( 0.15,-0.37 ),
    vec2( 0.29,0.29 ),
    vec2( 0.4,0.0 ),
    vec2( 0.29,-0.29 ),
    vec2( 0.0,-0.4 ),
    vec2( -0.29,0.29 ),
    vec2( -0.4,0.0 ),
    vec2( -0.29,-0.29 ),
    vec2( 0.0,0.4 ),
    vec2( 0.29,0.29 ),
    vec2( 0.4,0.0 ),
    vec2( 0.29,-0.29 ),
    vec2( 0.0,-0.4 ),
    vec2( -0.29,0.29 ),
    vec2( -0.4,0.0 ),
    vec2( -0.29,-0.29 ),
    vec2( 0.0,0.4 )
);

#endif


void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vScreenPos = GetScreenPosPreDiv(gl_Position);
    vTexCoord = GetQuadTexCoord(gl_Position);
    vScreenPosFull = GetScreenPos(gl_Position).xy;
}

void PS()
{
	const float depthMult = 10.0;
	
    float aspectratio = 800.0/800.0;
    vec2 aspectcorrect = vec2(1.0,aspectratio);
    aspectcorrect *= 0.1;
    
	float depth = depthMult * ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );
	
	// PUT THESE BACK IN
    float factor = clamp( ( depth - cFocus ) * cBias, -cBlurClamp, cBlurClamp );
    vec2 dofblur = vec2 (abs(factor));

	vec4 col = vec4(0.0);
	//col += texture2D(sDiffMap, vScreenPos);
	int weights = 1;
	// for (int i = 0; i < 40; i++) {
		// // Prevent blur bleeding onto in-focus objects by only sampling if we're
		// // Closer than what we sample (By a threshold)
		// float sampleddofblur = depthMult * ReconstructDepth( texture2D(sDepthBuffer, vTexCoord).r );
		// sampleddofblur = clamp( ( sampleddofblur - cFocus ) * cBias, -cBlurClamp, cBlurClamp );
		// sampleddofblur = abs(sampleddofblur);
		
		// //HUH??????? THEY'RE THE SAME?!?!?
		// if(dofblur.x == sampleddofblur) {
			// col += texture2D(sDiffMap, vScreenPos  + (samples[i] * aspectcorrect) * dofblur);
			// weights++;
		// }
	// } 
    

		//NEW
		col += GaussianBlur(2, vec2(1.0, 0.0), vec2(1.0), 1.0, sDiffMap, vScreenPos) / 2;
		col += GaussianBlur(2, vec2(0.0, 1.0), vec2(1.0), 1.0, sDiffMap, vScreenPos) / 2;
		/////

	//ORIGINAL
    #ifndef DEBUGMODE
	//gl_FragColor = col/weights;
	gl_FragColor = col;
	#endif
	
	#ifdef DEBUGMODE
	if(factor < 0.0) {
		gl_FragColor = vec4(-factor, 0, 0, 1.0);		
	} else {
		gl_FragColor = vec4(factor);
	}
	#endif
	
    gl_FragColor.a = 1.0;
    //gl_FragColor = vec4(vScreenPosFull.x, vScreenPosFull.y, 1.0, 1.0);
}