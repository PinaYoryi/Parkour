#include "MusicPlayer.h"
#include "AudioSource.h"
#include "Component.h"
#include "Entity.h"

MusicPlayer::~MusicPlayer() {

}

bool MusicPlayer::init(const std::map<std::string, std::string>& mapa)
{
	if (_myEntity->getComponent<AudioSource>() == nullptr || !_myEntity->getComponent<AudioSource>()->isInitialized()) return false;
	_myEntity->getComponent<AudioSource>()->playSound2D(true);

	return true;
}
