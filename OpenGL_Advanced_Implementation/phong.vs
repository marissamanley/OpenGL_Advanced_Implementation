#version 330 core
layout (location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTexCoord;
uniform mat4 mvp;
uniform vec3 lightPos;
uniform mat4 projection;
uniform mat4 view;

out vec3 lightPosFrag;
out vec3 vertexColor;
out vec3 position;
out vec3 normal;
out vec2 TexCoord;

out vec3 FragPos;


void main()
{
   gl_Position = projection * view * mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);
   position = aPos;
   normal = mat3(transpose(inverse(mvp))) * aNorm; 
   lightPosFrag = lightPos;
   FragPos = vec3(mvp * vec4(aPos, 1.0));
   TexCoord = aTexCoord;
}