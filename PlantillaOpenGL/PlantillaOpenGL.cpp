// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//



#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
/*#include <conio.h>*/

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

#include "Shader.h"
#include "Vertice.h"

Shader *shader;
GLuint posicionID;
GLuint colorID; 

vector<Vertice> triangulo;     
//Para rendear un elemento se necesitar del vertex y el buffer
GLuint vertexArrayTrianguloID;
GLuint bufferTrinaguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> chichenitza;
GLuint vertexArrayChichenitzaID;
GLuint bufferChichenitzaID;
void inicializarCuadrado() {
	Vertice v1 = {
		vec3(-0.8, 0.8, 0.0),
		vec4(0.4, 0.7, 0.1, 1.0)
	};
	Vertice v2 = {
		vec3(-0.4, 0.8, 0.0),
		vec4(0.4, 0.7, 0.1, 1.0)
	};
	Vertice v3 = {
		vec3(-0.4, 0.5, 0.0),
		vec4(0.4, 0.7, 0.1, 1.0)
	};
	Vertice v4 = {
		vec3(-0.8, 0.5, 0.0),
		vec4(0.4, 0.7, 0.1, 1.0)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

using namespace std;

void inicializarTriangulo() {
	//Inicializar el vertice
	Vertice v1 =
	{
		vec3(0.0f,0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void inicializarChichenitza() {
	/*Vertice v1 = {
		vec3(-0.5f,-0.5f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v2 = {
		vec3(0.5f, -0.5f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v3 = {
		vec3(0.5f, -0.4f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v4 = {
		vec3(-0.5f, -0.4f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v1);
	chichenitza.push_back(v2);
	chichenitza.push_back(v3);
	chichenitza.push_back(v4);

	Vertice v5 = {
	vec3(-0.4f,-0.4f, 0.0f),
	vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v6 = {
		vec3(0.4f, -0.4f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v7 = {
		vec3(0.4f, -0.3f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v8 = {
		vec3(-0.4f, -0.3f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};

	chichenitza.push_back(v5);
	chichenitza.push_back(v6);
	chichenitza.push_back(v7);
	chichenitza.push_back(v8);



	Vertice v9 = {
		vec3(-0.3f,-0.3f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v10 = {
		vec3(0.3f, -0.3f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v11 = {
		vec3(0.3f, -0.2f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v12 = {
		vec3(-0.3f, -0.2f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v9);
	chichenitza.push_back(v10);
	chichenitza.push_back(v11);
	chichenitza.push_back(v12);


	Vertice v13 = {
		vec3(-0.2f,-0.2f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v14 = {
		vec3(0.2f, -0.2f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v15 = {
		vec3(0.2f, -0.1f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v16 = {
		vec3(-0.2f, -0.1f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v13);
	chichenitza.push_back(v14);
	chichenitza.push_back(v15);
	chichenitza.push_back(v16);

	Vertice v17 = {
		vec3(-0.1f,-0.1f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v18 = {
		vec3(0.1f, -0.1f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v19 = {
		vec3(0.1f, 0.1f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v20 = {
		vec3(-0.1f, 0.1f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v17);
	chichenitza.push_back(v18);
	chichenitza.push_back(v19);
	chichenitza.push_back(v20);

	Vertice v21 = {
		vec3(-0.6f,-0.6f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v22 = {
		vec3(0.6f, -0.6f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v23 = {
		vec3(0.6f, -0.5f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v24 = {
		vec3(-0.6f, -0.5f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v21);
	chichenitza.push_back(v22);
	chichenitza.push_back(v23);
	chichenitza.push_back(v24);

	Vertice v25 = {
		vec3(-0.7f,-0.7f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v26 = {
		vec3(0.7f, -0.7f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v27 = {
		vec3(0.7f, -0.6f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v28 = {
		vec3(-0.7f, -0.6f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v25);
	chichenitza.push_back(v26);
	chichenitza.push_back(v27);
	chichenitza.push_back(v28);

	Vertice v29 = {
		vec3(-0.8f,-0.8f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v30 = {
		vec3(0.8f, -0.8f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v31 = {
		vec3(0.8f, -0.7f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v32 = {
		vec3(-0.8f, -0.7f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v29);
	chichenitza.push_back(v30);
	chichenitza.push_back(v31);
	chichenitza.push_back(v32);

	Vertice v33 = {
		vec3(-0.9f,-0.9f,0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v34 = {
		vec3(0.9f, -0.9f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v35 = {
		vec3(0.9f, -0.8f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	Vertice v36 = {
		vec3(-0.9f, -0.8f, 0.0f),
		vec4(0.9101f,0.875f,0.8164f,1.0f)
	};
	chichenitza.push_back(v33);
	chichenitza.push_back(v34);
	chichenitza.push_back(v35);
	chichenitza.push_back(v36);

	Vertice v37 = {
		vec3(-0.03f,-0.03f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v38 = {
		vec3(0.03f, -0.03f, 0.0f),
		vec4(0.0,0.0f,0.0f,1.0f)
	};
	Vertice v39 = {
		vec3(0.03f, -0.1f, 0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v40 = {
		vec3(-0.03f, -0.1f, 0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	chichenitza.push_back(v37);
	chichenitza.push_back(v38);
	chichenitza.push_back(v39);
	chichenitza.push_back(v40);

	Vertice v41 = {
		vec3(-0.1f, -0.01f,0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v42 = {
		vec3(0.1f, -0.01f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v43 = {
		vec3(0.1f, 0.1f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v44 = {
		vec3(-0.1f, 0.1f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	chichenitza.push_back(v41);
	chichenitza.push_back(v42);
	chichenitza.push_back(v43);
	chichenitza.push_back(v44);

	Vertice v45 = {
		vec3(-0.9f, -0.9f,0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v46 = {
		vec3(0.1f, -0.9f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v47 = {
		vec3(0.1f, 0.1f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	Vertice v48 = {
		vec3(-0.1f, 0.1f, 0.0f),
		vec4(0.781f,0.472f,0.308f,1.0f)
	};
	chichenitza.push_back(v45);
	chichenitza.push_back(v46);
	chichenitza.push_back(v47);
	chichenitza.push_back(v48);
	*/
Vertice v57 = {
		vec3(-1, -1, 0.0),
		vec4(0.82, 0.63, 0.20, 1.0)
};
Vertice v58 = {
	vec3(1, -1, 0.0),
	vec4(0.82, 0.63, 0.20, 1.0)
};
Vertice v59 = {
	vec3(1, -0.95, 0.0),
	vec4(0.82, 0.63, 0.20, 1.0)
};
Vertice v60 = {
	vec3(-1, -0.95, 0.0),
	vec4(0.82, 0.63, 0.20, 1.0)
};
cuadrado.push_back(v57);
cuadrado.push_back(v58);
cuadrado.push_back(v59);
cuadrado.push_back(v60);

//Escalon 1
Vertice v1 = {
	vec3(-0.8, -0.8, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v2 = {
	vec3(0.8, -0.8, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v3 = {
	vec3(0.8, -0.95, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v4 = {
	vec3(-0.8, -0.95, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v1);
cuadrado.push_back(v2);
cuadrado.push_back(v3);
cuadrado.push_back(v4);

//Escalon 2
Vertice v5 = {
	vec3(-0.7, -0.65, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v6 = {
	vec3(0.7, -0.65, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v7 = {
	vec3(0.7, -0.8, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v8 = {
	vec3(-0.7, -0.8, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v5);
cuadrado.push_back(v6);
cuadrado.push_back(v7);
cuadrado.push_back(v8);

//Escalon 3
Vertice v9 = {
	vec3(-0.61, -0.65, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v10 = {
	vec3(0.61, -0.65, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v11 = {
	vec3(0.61, -0.5, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v12 = {
	vec3(-0.61, -0.5, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v9);
cuadrado.push_back(v10);
cuadrado.push_back(v11);
cuadrado.push_back(v12);

//Escalon 4
Vertice v13 = {
	vec3(-0.53, -0.35, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v14 = {
	vec3(0.53, -0.35, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v15 = {
	vec3(0.53, -0.5, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v16 = {
	vec3(-0.53, -0.5, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v13);
cuadrado.push_back(v14);
cuadrado.push_back(v15);
cuadrado.push_back(v16);

//Escalon 5
Vertice v17 = {
	vec3(-0.45, -0.35, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v18 = {
	vec3(0.45, -0.35, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v19 = {
	vec3(0.45, -0.20, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v20 = {
	vec3(-0.45, -0.20, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v17);
cuadrado.push_back(v18);
cuadrado.push_back(v19);
cuadrado.push_back(v20);

//Escalon 6
Vertice v21 = {
	vec3(-0.38, -0.05, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v22 = {
	vec3(0.38, -0.05, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v23 = {
	vec3(0.38, -0.20, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v24 = {
	vec3(-0.38, -0.20, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v21);
cuadrado.push_back(v22);
cuadrado.push_back(v23);
cuadrado.push_back(v24);

//Escalon 7
Vertice v25 = {
	vec3(-0.31, -0.05, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v26 = {
	vec3(0.31, -0.05, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v27 = {
	vec3(0.31, 0.10, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v28 = {
	vec3(-0.31, 0.10, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v25);
cuadrado.push_back(v26);
cuadrado.push_back(v27);
cuadrado.push_back(v28);

//Escalon 8
Vertice v29 = {
	vec3(-0.25, 0.25, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v30 = {
	vec3(0.25, 0.25, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v31 = {
	vec3(0.25, 0.10, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v32 = {
	vec3(-0.25, 0.10, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v29);
cuadrado.push_back(v30);
cuadrado.push_back(v31);
cuadrado.push_back(v32);

//Casita
Vertice v33 = {
	vec3(-0.18, 0.25, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v34 = {
	vec3(0.18, 0.25, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v35 = {
	vec3(0.18, 0.55, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
Vertice v36 = {
	vec3(-0.18, 0.55, 0.0),
	vec4(0.9, 0.67, 0.13, 1.0)
};
cuadrado.push_back(v33);
cuadrado.push_back(v34);
cuadrado.push_back(v35);
cuadrado.push_back(v36);

Vertice v37 = {
	vec3(-0.18, 0.50, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v38 = {
	vec3(0.18, 0.50, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v39 = {
	vec3(0.18, 0.55, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v40 = {
	vec3(-0.18, 0.55, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
cuadrado.push_back(v37);
cuadrado.push_back(v38);
cuadrado.push_back(v39);
cuadrado.push_back(v40);

Vertice v41 = {
	vec3(-0.18, 0.45, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v42 = {
	vec3(0.18, 0.45, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v43 = {
	vec3(0.18, 0.40, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
Vertice v44 = {
	vec3(-0.18, 0.40, 0.0),
	vec4(0.8, 0.57, 0.3, 1.0)
};
cuadrado.push_back(v41);
cuadrado.push_back(v42);
cuadrado.push_back(v43);
cuadrado.push_back(v44);

Vertice v45 = {
	vec3(-0.03, 0.25, 0.0),
	vec4(0.1, 0.1, 0.1, 1.0)
};
Vertice v46 = {
	vec3(0.03, 0.25, 0.0),
	vec4(0.1, 0.1, 0.1, 1.0)
};
Vertice v47 = {
	vec3(0.03, 0.38, 0.0),
	vec4(0.1, 0.1, 0.1, 1.0)
};
Vertice v48 = {
	vec3(-0.03, 0.38, 0.0),
	vec4(0.1, 0.1, 0.1, 1.0)
};
cuadrado.push_back(v45);
cuadrado.push_back(v46);
cuadrado.push_back(v47);
cuadrado.push_back(v48);

//Escaleras
Vertice v49 = {
	vec3(-0.18, 0.25, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v50 = {
	vec3(-0.12, 0.25, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v51 = {
	vec3(-0.14, -0.95, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v52 = {
	vec3(-0.20, -0.95, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
cuadrado.push_back(v49);
cuadrado.push_back(v50);
cuadrado.push_back(v51);
cuadrado.push_back(v52);

Vertice v53 = {
	vec3(0.18, 0.25, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v54 = {
	vec3(0.12, 0.25, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v55 = {
	vec3(0.14, -0.95, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
Vertice v56 = {
	vec3(0.20, -0.95, 0.0),
	vec4(0.7, 0.47, 0.2, 1.0)
};
cuadrado.push_back(v53);
cuadrado.push_back(v54);
cuadrado.push_back(v55);
cuadrado.push_back(v56);
}
void dibujar() {
	//Elegir el shader
	shader->enlazar();
	//Elegir un vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());
	//Soltar el vertex array
	glBindVertexArray(0);
	//Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	//Chichenitza
	glBindVertexArray(vertexArrayChichenitzaID);
	glDrawArrays(GL_QUADS, 0, chichenitza.size());

}

void actualizar() {
	
}
int main()
{
	/*Crear un contexto 

	°Un contexto es una ventana de un sistema operativo
	°OpenGL no gestiona el iso de ventanas*/

	//Declaramos un apuntador de ventana.

	GLFWwindow *window;
	// Si no se pudo iniciar glfw terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	window =
		glfwCreateWindow(1024, 728, "Ventana", NULL, NULL);
	if (!window) {
		glfwTerminate();
			exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, activamos funciones modernas(trabajar con GPU/CPU)
	glewExperimental = true;
	GLenum  errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;
	 
	//inicializarTriangulo();
	//inicializarCuadrado();
	inicializarChichenitza();
	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";


	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	
	//Desenlazar el shader
	shader->desenlazar();

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Crear vertex buffer
	glGenBuffers(1, &bufferTrinaguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrinaguloID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);


	//Habilitar atributos del Shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//--------CUADRADO-----

	//Vertex array y buffer para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
		
	//Crear el buffer del cuadrado
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);

	//Llenar el buffer 
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)* cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);

	//Habilitar atributos del Shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vertexArrayChichenitzaID);
	glBindVertexArray(vertexArrayChichenitzaID);
	glGenBuffers(1, &bufferChichenitzaID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferChichenitzaID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)* chichenitza.size(), chichenitza.data(), GL_STATIC_DRAW);

	//Habilitar atributos del Shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Ciclo de dibujo(draw loop)
	while (!glfwWindowShouldClose(window)) {
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(1, 0.5, 0, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar Buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();


		
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

