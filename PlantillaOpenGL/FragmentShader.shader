#version 330 core
//Primera linea SIEMPRE es la version

//Atributos de entrada (Vienen desde el vertex shader)
in vec4 fragmentColor;

//Atributos de Salida 
out vec4 salidaColor;

//Funcion main()
void main() {
	salidaColor = fragmentColor;
}