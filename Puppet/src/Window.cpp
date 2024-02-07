#include "Window.h"

Window::Window() {
	widht = 800; 
	height = 600; 

	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0; 
	}

	xChange = 0.0f;
	yChange = 0.0f;

}

Window::Window(GLint windowWidht, GLint windowHeight) {
	widht = windowWidht;
	height = windowHeight;

	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}

	xChange = 0.0f;
	yChange = 0.0f;


}

int Window::Initialise() {

	if (!glfwInit()) {
		printf("Error Initialising GLFW");
		glfwTerminate();

		return 1;

	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(widht, height, "Test Window", NULL, NULL);
	if (!mainWindow) {

		printf("Error creating GLFW window!");
		glfwTerminate();
		return 1;

	}

	
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	glfwMakeContextCurrent(mainWindow);

	//Manejar teclas y mouse para camara 

	createCallbacks();
	glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	glewExperimental = GL_TRUE;

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;

	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, bufferWidth, bufferHeight);

	glfwSetWindowUserPointer(mainWindow, this);
}


void Window::createCallbacks() {
	glfwSetKeyCallback(mainWindow, handleKeys);
	glfwSetCursorPosCallback(mainWindow, handleMouse);
}


GLfloat Window::getXChange() {
	GLfloat theChange = xChange;
	xChange = 0; 
	return theChange;
}

GLfloat Window::getYChange() {
	GLfloat theChange = yChange;
	yChange = 0;
	return theChange;
}


//Con esto podemos acceder al arreglo de las teclas 
void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode) {
	
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
	
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	}
	
	if (key >= 0 && key < 1024) {
		
		if (action == GLFW_PRESS) {
			theWindow->keys[key] = true;
			//printf("Pressed: %d\n: ", key);
		}
		else if (action == GLFW_RELEASE) {
			theWindow->keys[key] = false;
			//printf("Released: %d\n: ", key);
		}
	}


}

void Window::handleMouse(GLFWwindow* window, double xPos, double yPos) {
	
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved) {
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;


	theWindow->lastX = xPos;
	theWindow->lastY = yPos;

	//printf("x:%.6f, y:%.6f\n", theWindow->xChange, theWindow->yChange);

}	






Window::~Window() {
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}