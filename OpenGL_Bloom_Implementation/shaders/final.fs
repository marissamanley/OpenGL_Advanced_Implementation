#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D scene;
uniform sampler2D bloomBlur;
uniform sampler2D noBlur;
uniform bool bloom;
uniform bool halo;
uniform float exposure;

void main()
{             
    const float gamma = 2.2;
    vec3 hdrColor = texture(scene, TexCoords).rgb;      
    vec3 bloomColor = texture(bloomBlur, TexCoords).rgb;
    vec3 blurColor = texture(noBlur, TexCoords).rgb;
    if(bloom)
    {
        if(halo)
        	hdrColor += (bloomColor-blurColor); // additive blending
        else
		hdrColor += bloomColor;
    }
    // tone mapping
    vec3 result = vec3(1.0) - exp(-hdrColor * exposure);
    // also gamma correct while we're at it       
    result = pow(result, vec3(1.0 / gamma));
    FragColor = vec4(result, 1.0);
}