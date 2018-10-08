#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
 
varying vec2 vTexCoord;
varying vec4 vScreenPos;
 
#ifdef COMPILEPS
 
const vec4 ma = vec4(0.0,12.0,3.0,15.0);
const vec4 mb = vec4(8.0,4.0,11.0,7.0);
const vec4 mc = vec4(2.0,14.0,1.0,13.0);
const vec4 md = vec4(10.0,6.0,9.0,5.0);
const mat4 dm = mat4(ma,mb,mc,md);
 
float find_closest(int x, int y, float c0){
  float limit = 0.0;
  limit = ( dm[x][y] + 1.0 )/64.0;
 
  if(c0 < limit)
    return 0.0;
  return 1.0;
}
#endif
 
void VS(){
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vScreenPos = GetScreenPos(gl_Position);
    vTexCoord = GetTexCoord(iTexCoord);
}
 
void PS(){
      vec2 screenuv = vScreenPos.xy / vScreenPos.w;
 
      //vec4 lum = vec4(0.299, 0.587, 0.114, 0);
      vec4 lum = vec4(0.15, 0.15, 0.15, 0);
 
      float grayscale = dot(texture2D(sEnvMap, screenuv), lum);
      vec3 rgb = texture2D(sEnvMap, screenuv).rgb;
 
 
      vec2 xy = (vScreenPos.xy / vScreenPos.w)*(1.0/cGBufferInvSize);
      //int x = int(mod(xy.x, 8));
      //int y = int(mod(xy.y, 8));
      int x = int(mod(xy.x, 4));
      int y = int(mod(xy.y, 4));
 
      //vec3 finalRGB;
      //finalRGB.r = find_closest(x, y, rgb.r);
      //finalRGB.g = find_closest(x, y, rgb.g);
      //finalRGB.b = find_closest(x, y, rgb.b);
 
      float final = find_closest(x, y, grayscale);
      //gl_FragColor = vec4(finalRGB, 1.0);
      gl_FragColor = vec4(final,final,final,1.0);
}