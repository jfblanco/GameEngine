uniform vec4 scale;

void main() {
	vec4 pos = gl_Vertex * scale;
	gl_Position = gl_ModelViewProjectionMatrix * pos;
}