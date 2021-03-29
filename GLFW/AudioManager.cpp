#include "AudioManager.h"
AudioManager::AudioManager()
{
	soundEngine = createIrrKlangDevice();
}
AudioManager::~AudioManager()
{
	soundEngine->drop();
}
void AudioManager::play(const char *filename,bool loop)
{
	soundEngine->play2D(filename,loop);
}
void AudioManager::stopAll()
{
	soundEngine->stopAllSounds();
}
