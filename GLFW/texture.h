#pragma once
#include "GameManager.h"
class Texture
{
private:
	GLint width, height;
	GLuint shaderProgram, VBO, VAO, texture;
	const GLchar* vertexShaderSource = "#version 430 core\n"
		"layout(location = 0) in vec2 aPos;"
		"out vec2 TexCoord;"
		"uniform mat4 projection;"
		"void main()"
		"{"
		"gl_Position = projection * vec4(aPos,1.0, 1.0);"
		"if(gl_VertexID==0)TexCoord = vec2(0.0f,0.0f);"
		"if(gl_VertexID==1)TexCoord = vec2(1.0f,0.0f);"
		"if(gl_VertexID==2)TexCoord = vec2(1.0f,1.0f);"
		"if(gl_VertexID==3)TexCoord = vec2(0.0f,1.0f);"
		"}";

	const GLchar* fragmentShaderSource = "#version 430 core\n"
		"out vec4 FragColor;"
		"in vec2 TexCoord;"
		"uniform sampler2D texture1;"
		"void main()"
		"{"
		"FragColor = texture(texture1, TexCoord);"
		"}";
public:
	void bind();
	void unbind();
	void createProgram();
	GLuint load(const char* file, bool png = true);
	void init(const char* file,bool png=true);
	void setBounds(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void draw(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
};