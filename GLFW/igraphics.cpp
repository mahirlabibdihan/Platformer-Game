/*
Normal output screen is in text mode .
We need a screen which is in graphics mode to do graphical work . Opengl does that .
*/
#include "GameManager.h"

extern GameManager game;
GLuint iG::iWindowWidth;
GLuint iG::iWindowHeight;
GLuint iG::iWindowX;
GLuint iG::iWindowY;
GLuint iG::iScreenWidth;
GLuint iG::iScreenHeight;
GLfloat iG::iClearR;
GLfloat iG::iClearG;
GLfloat iG::iClearB;
vector<iG::vertice> iG::vertices;
GLfloat iG::r, iG::g, iG::b, iG::a;
GLuint iG::shaderProgram, iG::VBO, iG::VAO, iG::texture;
const GLchar* iG::vertexShaderSource = "#version 430 core\n"
"layout (location = 0) in vec2 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos,0.0, 1.0);\n"
"}";

const GLchar* iG::fragmentShaderSource = "#version 430 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}";
void update();
void iG::iInitialize(const char* title)
{
	if (!glfwInit()) { exit(EXIT_FAILURE); }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(iG::iWindowWidth, iG::iWindowHeight, "Bounce", glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, iKeyboard);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0f);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);     // Transparent Color
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Transparent Color

	iG::start();
	game.init();
	while (!glfwWindowShouldClose(window))
	{
		iDraw();
		update();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	iG::end();

	glfwTerminate();
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}