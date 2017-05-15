in vec3 vertexPosition;
uniform mat4 projectionMatrix;
uniform mat4 positionMatrix;

void main() {
	gl_Position = projectionMatrix * positionMatrix * vec4(vertexPosition, 1.0);
}