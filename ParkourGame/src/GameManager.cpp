#include "GameManager.h"
#include "MotorLoop.h"
#include "SceneManager.h"
#include "Gui.h"
#include "TextComponent.h"
#include "Audio.h"

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
	SceneManager::GetInstance()->pauseScene();
	Entity::instantiate("textScore.prefab")->getComponent<TextComponent>()->setText("Has durado " + std::to_string(_secondsLasted) + " segundos");
	Entity::instantiate("botonIrMenuPpal.prefab");
	Entity::instantiate("botonReiniciar.prefab");
	Entity::instantiate("perdiste.prefab");
}

void GameManager::toScene(std::string scene, sceneState state) {
	switch (state)
	{
	case Continues:	// continuar la escena pausada (elimina las entidades no pausadas)
		SceneManager::GetInstance()->continueScene();		
		break;
	case Pauses:	// pausar la escena y cargar un menu
		SceneManager::GetInstance()->pauseScene();
		Entity::instantiate("botonReanudar.prefab");
		Entity::instantiate("botonIrMenuPpal.prefab");

		break;
	case Neutral:	// cargar otra escena
		SceneManager::GetInstance()->newScene(scene);
	}
}
