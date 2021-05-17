#include "Lifetime.h"
#include "SceneManager.h"
#include "GameManager.h"

Lifetime::Lifetime() : _endTime(0), _currentTime(0), _startedYet(false) {}

bool Lifetime::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("life") == mapa.end()) return false;

	_currentTime = 0;

	std::string s = mapa.at("life");
	_endTime = std::stof(s);

	return true;
}

void Lifetime::update(){
	if (!_startedYet) {	// Para que empiece cuando empiece el bucle del juego
		_startedYet = true;
	}
	else {
		_currentTime += GameManager::GetInstance()->getDeltaTime();	// El tiempo que lleva
		if (_currentTime >= _endTime) {	// Si debe morir
			SceneManager::GetInstance()->addEntityToRemove(_myEntity);
		}
	}
}