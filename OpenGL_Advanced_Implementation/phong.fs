#version 330 core
in vec3 position; //???

//Material variables
uniform vec3 matAmbient;
uniform vec3 matDiffuse;
uniform vec3 matSpecular;
uniform float shininess;

//Light variables
uniform vec3 lightAmbient;
uniform vec3 lightDiffuse;
uniform vec3 lightSpecular;

uniform float constant;
uniform float linear;
uniform float quadratic;

uniform vec3 aColor; //ignore

in vec3 lightPosFrag; //technically can be uniform
in vec3 normal;

in vec3 FragPos;  //Frag location in the world
in vec2 TexCoord;

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

uniform vec3 viewPos;
uniform sampler2D ourTexture;
void main()
{
    vec3 ambient = lightAmbient * matAmbient;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPosFrag - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = lightDiffuse * (diff * matDiffuse);

    float specularStrength = 10;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = lightSpecular * spec * matSpecular;


    float distance = length(lightPosFrag - FragPos);
    float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));    
    ambient *= attenuation; 
    diffuse *= attenuation;
    specular *= attenuation; 

    vec3 result = (ambient+diffuse+specular);

    FragColor = texture(ourTexture, TexCoord) * vec4(result, 1.0f);

    float brightness = dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(FragColor.rgb, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
}