
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

    float aspectratio = 800.0/800.0;
    vec2 aspectcorrect = vec2(1.0,aspectratio);
    aspectcorrect *= 0.1;
    
	// We may need to use vTexCoord -> vScreenPos here instead
    float depth = 100.0 * DecodeDepth(texture2D(sDepthBuffer, vTexCoord).rgb);
    float factor = ( depth - cFocus );     
    vec2 dofblur = vec2 (clamp( factor * cBias, -cBlurClamp, cBlurClamp ));
    vec4 col = vec4(0.0);
    
    col += texture2D(sDiffMap, vScreenPos);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,0.4 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.15,0.37 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,0.29 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.37,0.15 )*aspectcorrect) * dofblur);    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.4,0.0 )*aspectcorrect) * dofblur);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.37,-0.15 )*aspectcorrect) * dofblur);    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,-0.29 )*aspectcorrect) * dofblur);    
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.15,-0.37 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,-0.4 )*aspectcorrect) * dofblur);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.15,0.37 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,0.29 )*aspectcorrect) * dofblur);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.37,0.15 )*aspectcorrect) * dofblur); 
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.4,0.0 )*aspectcorrect) * dofblur);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.37,-0.15 )*aspectcorrect) * dofblur);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,-0.29 )*aspectcorrect) * dofblur);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.15,-0.37 )*aspectcorrect) * dofblur);
    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.15,0.37 )*aspectcorrect) * dofblur*0.9);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.37,0.15 )*aspectcorrect) * dofblur*0.9);        
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.37,-0.15 )*aspectcorrect) * dofblur*0.9);        
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.15,-0.37 )*aspectcorrect) * dofblur*0.9);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.15,0.37 )*aspectcorrect) * dofblur*0.9);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.37,0.15 )*aspectcorrect) * dofblur*0.9);     
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.37,-0.15 )*aspectcorrect) * dofblur*0.9);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.15,-0.37 )*aspectcorrect) * dofblur*0.9);    
    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,0.29 )*aspectcorrect) * dofblur*0.7);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.4,0.0 )*aspectcorrect) * dofblur*0.7);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,-0.29 )*aspectcorrect) * dofblur*0.7);    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,-0.4 )*aspectcorrect) * dofblur*0.7);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,0.29 )*aspectcorrect) * dofblur*0.7);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.4,0.0 )*aspectcorrect) * dofblur*0.7);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,-0.29 )*aspectcorrect) * dofblur*0.7);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,0.4 )*aspectcorrect) * dofblur*0.7);
             
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,0.29 )*aspectcorrect) * dofblur*0.4);
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.4,0.0 )*aspectcorrect) * dofblur*0.4);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.29,-0.29 )*aspectcorrect) * dofblur*0.4);    
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,-0.4 )*aspectcorrect) * dofblur*0.4);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,0.29 )*aspectcorrect) * dofblur*0.4);
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.4,0.0 )*aspectcorrect) * dofblur*0.4);  
    col += texture2D(sDiffMap, vScreenPos + (vec2( -0.29,-0.29 )*aspectcorrect) * dofblur*0.4);   
    col += texture2D(sDiffMap, vScreenPos + (vec2( 0.0,0.4 )*aspectcorrect) * dofblur*0.4);   
            
    gl_FragColor = col/41.0;
    gl_FragColor.a = 1.0;
}
