#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNorm;
uniform mat4 mvp;
uniform vec3 lightPos;
uniform mat4 projection;
uniform mat4 view;
uniform vec3 viewPos;

out vec3 vertexColor;
void main()
{
    vec3 aColor = vec3(1.0, 0.1, 0.1);
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = ambientStrength * lightColor;

    vec3 normal = mat3(transpose(inverse(mvp))) * aNorm;
    vec3 norm = normalize(normal);
    vec3 FragPos = vec3(mvp * vec4(aPos, 1.0));
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor; 

    float specularStrength = 10;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient+diffuse+specular) * aColor;
    vertexColor = result;
    gl_Position = projection * view * mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}