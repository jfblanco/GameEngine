#version 450 core

uniform mat4 ProjMtx;
in vec4 vPosition;
in vec4 vColor;
in vec2 txCoord;
out vec4 color;
out vec2 tex_coord;
void main() {
	color = vColor;
	tex_coord = txCoord;
	gl_Position = ProjMtx * vPosition;
};