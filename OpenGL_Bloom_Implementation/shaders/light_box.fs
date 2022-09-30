#version 330 core
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;
layout (location = 2) out vec4 BrightColor2;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} fs_in;

uniform sampler2D diffuseTexture;
uniform vec3 lightColor;

void main()
{
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;           
    FragColor = vec4(color, 1.0); 
    vec4 bloomColor = vec4(lightColor, 0);
    float brightness = dot(bloomColor.rgb, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(bloomColor.rgb, 1.0);
    else
	  BrightColor = vec4(0.0, 0.0, 0.0, 1.0);

    BrightColor2 = BrightColor;
}