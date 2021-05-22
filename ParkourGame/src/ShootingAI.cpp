#include "ShootingAI.h"
#include "SceneManager.h"
#include "BasicAI.h"
#include "MotorLoop.h" 

bool ShootingAI::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("proyectile") == mapa.end() || mapa.find("objective") == mapa.end() || mapa.find("rof") == mapa.end()) return false;

	std::string s = mapa.at("proyectile");
	_bala = s;

	s = mapa.at("objective");
	_objective = SceneManager::GetInstance()->getEntityByID(std::stoi(s));
	if (_objective == nullptr) return false;

	s = mapa.at("rof");
	_RoF = std::stof(s);
	_cooldown = 0;

	return true;
}

void ShootingAI::update() {
	_cooldown -= MotorLoop::GetInstance()->getDeltaTime();

	Vector3<> ini = _myEntity->getComponent<Transform>()->position();	// Inicio del trayecto
	Vector3<> fin = _objective->getComponent<Transform>()->position();	// Final del trayecto
	_myEntity->getComponent<BasicAI>()->RotateTo(fin - ini);

	if (_cooldown < 0) {;
		_cooldown = _RoF;

		Entity* bala = Entity::instantiate(_bala, _myEntity->getComponent<Transform>()->position());

		Vector3<> tra = (fin - ini).normalize();						// Dirección del trayecto
		tra *= 2;															

		bala->getComponent<Rigidbody>()->setPosition(ini + tra);

		tra *= 500;	// Hasta el "infinito"
		bala->getComponent<BasicAI>()->MoveTo(ini + tra);
	}
}
