#version 330
in vec3 vertexPosition;
in vec3 vertexColor;
out vec4 color;
uniform mat4 projectionMatrix;
uniform mat4 viewCustomMatrix;
uniform mat4 modelMatrix;

void main() {
	color = vec4(vertexColor,1.0);
	gl_Position =  projectionMatrix * viewCustomMatrix * modelMatrix * vec4(vertexPosition, 1.0);
}