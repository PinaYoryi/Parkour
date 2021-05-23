#include "GameManager.h"
#include "MotorLoop.h"
#include "SceneManager.h"

GameManager* GameManager::_singleton = nullptr;

GameManager* GameManager::GetInstance() {
	return _singleton;
}

bool GameManager::Init() {
	if (_singleton != nullptr) return false;
	_singleton = new GameManager(); return true;
}

float GameManager::getDeltaTime() {
	return MotorLoop::GetInstance()->getDeltaTime();
}

void GameManager::onFinish(float time) {
	_secondsLasted = time;
	toScene("level.lua");
}
void GameManager::toScene(std::string scene, sceneState state) {
	switch (state)
	{
	case Continues://continuar la escena pausada (elimina las entidades no pausadas)
		SceneManager::GetInstance()->continueScene();
		break;
	case Pauses://pausar la escena y cargar un menu
		SceneManager::GetInstance()->pauseScene();

		break;
	case Neutral://cargar otra escena
		SceneManager::GetInstance()->newScene(scene);

	}
}
