#include "Lifetime.h"
#include "SceneManager.h"
#include "SceneManager.cpp"
#include "LevelBuilder.h"
#include "MotorLoop.h"
#include <random>

LevelBuilder::LevelBuilder() {}

bool LevelBuilder::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("platformprefab") == mapa.end() || mapa.find("lastplatform") == mapa.end() || mapa.find("time") == mapa.end()) return false;

	std::string s = mapa.at("platformprefab");
	_platfromPrefab = s;

	s = mapa.at("lastplatform");
	_lastTransform = SceneManager::GetInstance()->getEntityByID(std::stoi(s))->getComponent<Transform>();

	s = mapa.at("time");
	_mTime = _cTime = std::stof(s);

	return true;
}

void LevelBuilder::update() {
	_cTime -= MotorLoop::GetInstance()->getDeltaTime();
	if (_cTime < 0) {
		_cTime = _mTime;
		
		Vector3<> prevP = _lastTransform->position();
		Vector3<> prevA = _lastTransform->rotation().toEuler();
		Entity* platform = Entity::instantiate(_platfromPrefab, prevP);
		_lastTransform = platform->getComponent<Transform>();
		
		float posVarX = (rand() % 30) - 15;		// Variación en X
		float posVarY = (rand() % 5) - 2.5;		// Variación en Y
		float posVarAng = (rand() % 180) - 90;	// variación en ángulo en z
		_lastTransform->setPosition({prevP.x + posVarX, prevP.y + posVarY, prevP.z - 100});
		_lastTransform->setRotation(prevA.x, prevA.y, prevA.z + posVarAng);
	}
}