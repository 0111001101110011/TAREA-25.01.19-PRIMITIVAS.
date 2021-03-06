// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
	
using namespace std;

void dibujar();
 void dibujarPoligonos();
void dibujarPuntos();
void dibujarLineas();
void dibujarLineaContinua();
void dibujarTrianguloContinuo();
void dibujarCuadrado();
void dibujarCuadradoContinuo();
void dibujarPaisaje();
void dibujarCasa();
void dibujarFondo();
void dibujarArbol();
void dibujarCielo();

int main()
{
	// Creamos una ventana
	GLFWwindow *window;

	// Si no se puede inicializar glfw, finalizamos la ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	// Si no podemos iniciar la ventana, terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL << std::endl;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(0.5f, 0.6f, 1.0f, 0.0f);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

void dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// dibujarPoligonos();
	// dibujarPuntos();
	// dibujarLineas();
	// DibujarLineaContinua();
	// dibujarTrianguloContinuo();
	// dibujarCuadrado();
	// dibujarCuadradoContinuo();
	dibujarPaisaje();
}


// Funciones de Dibujo


void dibujarPoligonos()
{
	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);

	glBegin(GL_TRIANGLES);
		glVertex3f(1, 1, 0.0);
		glVertex3f(1, -1, 0.0);
		glVertex3f(-1, -1, 0.0);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
		glVertex3f(.25, .25, 0.0);
		glVertex3f(.25, -.25, 0.0);
		glVertex3f(-.25, -.25, 0.0);
		glVertex3f(-.25, .25, 0.0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		glVertex3f(-.75, -.8, 0.0);
		glColor3f(.2, .5, .8);
		glVertex3f(-.50, -.3, 0.0);
		glVertex3f(-.55, -.7, 0.0);
	glEnd();
}

void dibujarPuntos()
{
	glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex3f(-0.4f, 0.1f, 0);
		glVertex3f(0, 0.3f, 0);
		glVertex3f(0.1f, 0.4f, 0);
		glVertex3f(0.2f, 0.1f, 0);
		glVertex3f(0.3f, 0.8f, 0);
		glVertex3f(0.4f, 0.9f, 0);
		glVertex3f(0.5f, 0.4f, 0);
		glVertex3f(0.6f, 0.2f, 0);
		glVertex3f(0.7f, 0.1f, 0);
		glVertex3f(0.8f, 0.6f, 0);
		glVertex3f(0.9f, 0.5f, 0);
	glEnd();
}

void dibujarLineas()
{
	glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3f(-0.4f, 0.1f, 0);
		glVertex3f(0, 0.3f, 0);
		glVertex3f(0.1f, 0.4f, 0);
		glVertex3f(0.2f, 0.1f, 0);
		glVertex3f(0.3f, 0.8f, 0);
		glVertex3f(0.4f, 0.9f, 0);
		glVertex3f(0.5f, 0.4f, 0);
		glVertex3f(0.6f, 0.2f, 0);
		glVertex3f(0.7f, 0.1f, 0);
		glVertex3f(0.8f, 0.6f, 0);
		glVertex3f(0.9f, 0.5f, 0);
	glEnd();
}

void dibujarLineaContinua()
{
	glBegin(GL_LINE_STRIP);
		glColor3f(1, 1, 1);
		glVertex3f(-.25, -.25f, 0);
		glVertex3f(-.25, .25f, 0);
		glVertex3f(.25f, 0.25f, 0);
		glVertex3f(.25f, -0.25f, 0);
		glVertex3f(-.25, -.25f, 0);
	glEnd();
}

void dibujarTrianguloContinuo()
{
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(.25F, .25f, 0);
		glVertex3f(.25f, 0, 0);
		// A partir del 3er vértice, los nuevos vértices harán un nuevo triángulo con los dos vértices anteriores a éste.
		glVertex3f(.6f, -0.3, 0);
		glVertex3f(-.4f, 0.5, 0);
	glEnd();
}

void dibujarCuadrado()
{
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(.25F, .0f, 0);
		glVertex3f(.25f, .25f, 0);
		glVertex3f(0, .25f, 0);
	glEnd();
}

void dibujarCuadradoContinuo()
{
	glBegin(GL_QUAD_STRIP);
		glColor3f(.2, .32, .8);
		glVertex3f(0, 0, 0);
		glVertex3f(-.25F, .0f, 0);
		glVertex3f(-.25f, -.25f, 0);
		glVertex3f(0, -.25f, 0);
		glVertex3f(0, -.75, 0);
		glVertex3f(-.25, -.75, 0);
	glEnd();
}

void dibujarPaisaje()
{
	dibujarCasa();
	dibujarFondo();
	dibujarCielo();
	dibujarArbol();
}


void dibujarCielo() {
	glBegin(GL_POLYGON);
	glColor3f(1, 0.8, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.7,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}

	glEnd();

	//NUBE 1
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.1,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.0,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	//NUBE 2



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.3,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.4,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();


	/*
	glColor3f(0, 0, 0);
	glVertex3f(-0.8, 0.7, 0);
	glVertex3f(-0.8, 0.7, 0);
	glVertex3f(-0.5, 0.9, 0);
	glVertex3f(0.5, 0.9, 0);

	glEnd();
	*/
}

void dibujarArbol() {
	//TRONCO

	glBegin(GL_QUADS);
	glColor3f(0.647059f, 0.164706f, 0.164706f);
	glVertex3f(-0.6f, -0.5f, 0);
	glVertex3f(-0.5f, -0.5f, 0);
	glVertex3f(-0.5f, -0.10f, 0);
	glVertex3f(-0.6f, -0.10f, 0);

	glEnd();

	//RAMAS

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.45,
			0.1*sin((double)i*3.14159 / 180.0) -0.09 , 0);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.65,
			0.1*sin((double)i*3.14159 / 180.0) - 0.09, 0);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.55,
			0.1*sin((double)i*3.14159 / 180.0) - 0.001, 0);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(00.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.55,
			0.1*sin((double)i*3.14159 / 180.0) - 0.17, 0);
	}

	glEnd();
}


void dibujarCasa()
{	//CASA
	glBegin(GL_QUADS);
		glColor3f(0.91f, 0.76f, 0.65f);
		glVertex3f(.1f, -.5f, 0);
		glVertex3f(.5f, -.5f, 0);
		glVertex3f(.5f, -.10f, 0);
		glVertex3f(.1f, -.10f, 0);
	glEnd();

	//PUERTA
	glBegin(GL_QUADS);
		glColor3f(0.329412f, 0.329412f, 0.329412f);
		glVertex3f(.2f, -.5f, 0);
		glVertex3f(.3f, -.5f, 0);
		glVertex3f(.3f, -.30f, 0);
		glVertex3f(.2f, -.30f, 0);
	glEnd();

	//TECHO
	glBegin(GL_TRIANGLES);
		glColor3d(2, 2, 2);
		glVertex3d(.05f, -.10f, 0);
		glVertex3d(.55f, -.10f, 0);
		glVertex3d(.30f, .1f, 0);
	glEnd();

	// VENTANA 2
	glBegin(GL_QUADS);
		glColor3f(0.329412f, 0.329412f, 0.329412f);
		glVertex3f(.35f, -.2f, 0);
		glVertex3d(.35f, -.35f, 0);
		glVertex3d(.45f, -.35f, 0);
		glVertex3d(.45f, -.2f, 0);
	glEnd();


	

}



void dibujarFondo()
{
	// SUELO
	glBegin(GL_QUADS);
		glColor3f(.1f, .7f, .3f);
		glVertex3f(-1, -.5, 0);
		glVertex3f(1, -.5, 0);
		glVertex3f(1, -1, 0);
		glVertex3f(-1, -1, 0);
	glEnd();

	 glBegin(GL_POLYGON);
		glColor3f(0.0 , 0.0 , 1.0);
		glVertex3f(0,0,0);
	glEnd(); 
	


}