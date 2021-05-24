#include "DroneAI.h"
#include "SceneManager.h"
#include "BasicAI.h"
#include "PlayerController.h"
#include "GameManager.h"

bool DroneAI::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("strength") == mapa.end() || mapa.find("objective") == mapa.end()) return false;

	std::string s = mapa.at("strength");
	_strength = std::stof(s);

	s = mapa.at("objective");
	_objective = SceneManager::GetInstance()->getEntityByID(std::stoi(s));
	if (_objective == nullptr) return false;
}

void DroneAI::update() {
	_myEntity->getComponent<BasicAI>()->setStep(_strength);
	_myEntity->getComponent<BasicAI>()->moveTo(_objective->getComponent<Transform>()->position());
	//_myEntity->getComponent<BasicAI>()->RotateTo(_objective->getComponent<Transform>()->position());
}

void DroneAI::onCollisionStart(Entity* other) { 
	if (other->getName() == "Player") {
		other->getComponent<PlayerController>()->playerDead();
	} //Esto hay que mirar que funcione
}