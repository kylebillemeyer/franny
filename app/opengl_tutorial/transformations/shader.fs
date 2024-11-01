#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixAmt;

void main()
{
	FragColor = mix(texture(texture1, vec2(TexCoord.x, -TexCoord.y)),
	                texture(texture2, TexCoord),
	                mixAmt);
}