#pragma once

#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
class Window
{

public:
	Window();
	Window(GLint windowWidht, GLint windowHeight);


	int Initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() {
		return glfwWindowShouldClose(mainWindow);
	}

	bool* getsKeys() {
		return keys;
	}

	GLfloat getXChange();

	GLfloat getYChange();

	void swapBuffers() { glfwSwapBuffers(mainWindow); }
	~Window();


private:
	GLFWwindow* mainWindow;
	GLint widht, height;
	GLint bufferWidth, bufferHeight;
	
	//Para checar teclas 
	bool keys[1024];


	//Para checar mouse
	GLfloat lastX, lastY, xChange, yChange;
	bool mouseFirstMoved;

	void createCallbacks();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};

