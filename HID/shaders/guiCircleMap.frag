#version 450 core

in vec4 color;
in vec2 tex_coord;
out vec4 fColor;
uniform sampler2D tex;
void main(){
	vec4 pixelMapColor = texture(tex, tex_coord);
	if(pixelMapColor.xyz == vec3(1.0,1.0,1.0))
		discard;
	else
		fColor = color;
}