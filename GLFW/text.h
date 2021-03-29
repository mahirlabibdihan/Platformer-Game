#pragma once
#include "GameManager.h"
class Text
{
	GLint width, height;
	GLuint shaderProgram, VBO, VAO, texture;
	const GLchar* vertexShaderSource = "#version 430 core"
		"layout(location = 0) in vec4 vertex;" // <vec2 pos, vec2 tex>
		"out vec2 TexCoords;"
		"uniform mat4 projection;"
		"void main()"
		"{"
		"gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);"
		"TexCoords = vertex.zw;"
		"}";

	const GLchar* fragmentShaderSource = "#version 430 core"
		"in vec2 TexCoords;"
		"out vec4 color;"
		"uniform sampler2D text;"
		"uniform vec3 textColor;"
		"void main()"
		"{"
		"vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);"
		"color = vec4(textColor, 1.0) * sampled;"
		"}";
public:
	void createProgram();
	void init();
	void draw(std::string text, float x, float y, float scale);
};