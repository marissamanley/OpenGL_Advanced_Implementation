#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec3 aNorm;
uniform mat4 m;
uniform vec3 lightPos;
out vec3 vertexColor;
void main()
{
   float distance = length(lightPos - aPos);
   vec3 lightVector = normalize(lightPos - aPos);
   float diffuse = max(dot(aNorm, lightVector), 5.0f);
   diffuse = diffuse * (1.0 / (1.0 + (0.25 * distance * distance)));

   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * m;
   vertexColor = aColor * diffuse;
}