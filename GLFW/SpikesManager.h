#ifndef __SPIKES_MANAGER__
#define __SPIKES_MANAGER__
#include "Spike.h"
#include "GameManager.h"
class SpikesManager
{
	GLuint VBO, VAO, texture, shaderProgram;
	vector<Spike> s;	
public:
	SpikesManager();
	void addSpike(GLfloat,GLfloat);
	void update();	// Moving spikes
	void draw();
	bool checkCollision();
	void clear();
	void init();
};
#endif
