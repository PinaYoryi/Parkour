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

void GameManager::onFinish(float time, bool win) {
	_secondsLasted = time;
	if (win) toScene("winscene.lua");
	else toScene("aitest.lua");
}

void GameManager::toScene(std::string scene, sceneState state) {
	switch (state)
	{
	case Continues:
		SceneManager::GetInstance()->continueScene();
		break;
	case Pauses:
		SceneManager::GetInstance()->pauseScene();
		break;
	}
	SceneManager::GetInstance()->loadScene(scene);
}