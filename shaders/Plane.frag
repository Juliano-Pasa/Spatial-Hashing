#version 400

in vec3 Color;

void main() 
{
    gl_FragColor = vec4(Color, 1.0); //GL 4.0
}
