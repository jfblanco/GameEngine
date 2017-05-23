in vec3 vertexPosition;
out vec4 color;
uniform mat4 projectionMatrix;
uniform mat4 viewCustomMatrix;
uniform mat4 modelMatrix;

void main() {
	color = vec4(0.0,0.0,1.0,1.0);
	gl_Position =  projectionMatrix * viewCustomMatrix * modelMatrix * vec4(vertexPosition, 1.0);
}