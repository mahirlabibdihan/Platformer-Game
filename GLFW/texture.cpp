#include "Texture.h"
/*#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>*/
#include <SOIL2.h>

//#endif

GLuint Texture::shaderProgram, Texture::VBO, Texture::VAO;
const GLchar* Texture::vertexShaderSource = "#version 430 core\n"
"layout(location = 0) in vec4 aPos;"
"out vec2 TexCoord;"
"uniform mat4 projection;"
"void main()"
"{"
"gl_Position = projection * vec4(aPos.x,aPos.y,1.0, 1.0);"
"TexCoord=vec2(aPos.z,aPos.w);"
"}";

const GLchar* Texture::fragmentShaderSource = "#version 430 core\n"
"out vec4 FragColor;"
"in vec2 TexCoord;"
"uniform sampler2D texture;"
"void main()"
"{"
"FragColor = texture(texture, TexCoord);"
"}";
void Texture::init()
{
	shaderProgram=createProgram();
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(iG::iScreenWidth), 0.0f, static_cast<float>(iG::iScreenHeight));
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	// Configure VAO , VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, NULL, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

GLuint Texture::createProgram()
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// link shaders
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Delete shader
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

GLuint Texture::load(const char* fileName)
{
	/*GLuint texture;
	glGenTextures(1, &texture);*/
	GLuint texture = SOIL_load_OGL_texture
	(
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	/*glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load image
	GLint nrChannels,width,height;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image = stbi_load(fileName, &width, &height, &nrChannels, 0);
	if (nrChannels == 4)	// PNG
	{
		glTexImage2D(
			GL_TEXTURE_2D, 
			0, 
			GL_RGBA, 
			width, 
			height, 
			0, 
			GL_RGBA, 
			GL_UNSIGNED_BYTE, 
			image
		);
	}
	else if (nrChannels == 3)  // JPG
	{
		glTexImage2D(
			GL_TEXTURE_2D, 
			0, 
			GL_RGB, 
			width, 
			height, 
			0, 
			GL_RGB, 
			GL_UNSIGNED_BYTE, 
			image
		);
	}
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);*/
	return texture;
}

void Texture::render(GLfloat x, GLfloat y, GLfloat w, GLfloat h,GLuint texture)
{
	GLfloat vertices[] = {
		x,     y,		0.0f, 0.0f ,
		x + w, y,       1.0f, 0.0f ,
		x + w, y + h,   1.0f, 1.0f ,
		x,     y + h,     0.0f, 1.0f
	};
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}