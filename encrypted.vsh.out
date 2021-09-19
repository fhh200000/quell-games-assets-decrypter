uniform mat4 modelViewProjectionMatrix;

precision mediump float;

attribute vec2 inPosition;  
attribute mediump vec2 inTexcoord0;
attribute mediump vec4 inColor;
varying mediump vec2 varTexcoord0;
varying mediump vec4 varColor;

void main (void) 
{
	gl_Position	= modelViewProjectionMatrix * vec4(inPosition, 0.0, 1.0);
    varColor = inColor;
    varTexcoord0 = inTexcoord0;
}
