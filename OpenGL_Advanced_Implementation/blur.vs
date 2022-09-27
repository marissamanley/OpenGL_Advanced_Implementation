#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;
out float dist;
uniform vec3 camPos;

void main()
{
    TexCoords = aTexCoords;
    dist = distance(camPos, aPos);
    gl_Position = vec4(aPos, 1.0);
}