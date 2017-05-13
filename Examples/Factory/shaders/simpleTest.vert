in vec3 vertexPosition;

void main() {
	gl_Position = gl_ModelViewProjectionMatrix * vec4(vertexPosition, 1.0);
}