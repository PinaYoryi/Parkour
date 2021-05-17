#include "DroneAI.h"
#include "SceneManager.h"
#include "BasicAI.h"
#include "PlayerController.h"
#include "GameManager.h" //Temporal

bool DroneAI::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("strength") == mapa.end() || mapa.find("objective") == mapa.end()) return false;

	std::string s = mapa.at("strength");
	_strength = std::stof(s);

	s = mapa.at("objective");
	_objective = SceneManager::GetInstance()->getEntityByID(std::stoi(s), true);
	if (_objective == nullptr) return false;
}

void DroneAI::update() {
	_myEntity->getComponent<BasicAI>()->MoveTo(_objective->getComponent<Transform>()->position());
	_myEntity->getComponent<BasicAI>()->setStep(_strength);
	_myEntity->getComponent<BasicAI>()->RotateTo(_objective->getComponent<Transform>()->rotation().toEuler());
	//_myEntity->getComponent<BasicAI>()->setStepRot()
}

void DroneAI::onCollisionStart(Entity* other) { 
	/*if (other->hasComponent<PlayerController>()) {
		other->getComponent<PlayerController>()->playerDead();*/
	if (other->getName()=="Sinbad") {
#if (defined _DEBUG)
		std::cout << "Jugador muere\n";
#endif
		//GameManager::GetInstance()->onFinish(0.0, false); //Temporal
	}
}