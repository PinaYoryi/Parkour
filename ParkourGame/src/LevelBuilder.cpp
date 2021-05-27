#include "Lifetime.h"
#include "SceneManager.h"
#include "LevelBuilder.h"
#include "MotorLoop.h"
#include "Rigidbody.h"
#include "AudioSource.h"
#include <random>

LevelBuilder::LevelBuilder() :_cTime(0), _enemyChance(0), _mTime(0), _turretChance(0) {}

bool LevelBuilder::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("platformprefab") == mapa.end() || mapa.find("lastplatform") == mapa.end() || mapa.find("time") == mapa.end() ||
		mapa.find("turretprefab") == mapa.end() || mapa.find("dronprefab") == mapa.end() || mapa.find("enemychance") == mapa.end() ||
		mapa.find("turretchance") == mapa.end()) return false;

	std::string s = mapa.at("platformprefab");
	_platfromPrefab = s;

	s = mapa.at("turretprefab");
	_turretPrefab = s;

	s = mapa.at("dronprefab");
	_dronePrefab = s;

	s = mapa.at("lastplatform");
	_lastP = SceneManager::GetInstance()->getEntityByID(std::stoi(s))->getComponent<Transform>()->position();
	_lastR = SceneManager::GetInstance()->getEntityByID(std::stoi(s))->getComponent<Transform>()->rotation().toEuler();

	_initP = _lastP;

	s = mapa.at("time");
	_mTime = _cTime = std::stof(s);

	s = mapa.at("enemychance");
	_enemyChance = std::stof(s);

	s = mapa.at("turretchance");
	_turretChance = std::stof(s);

	return true;
}

void LevelBuilder::update() {
	_cTime -= MotorLoop::GetInstance()->getDeltaTime();
	if (_cTime < 0) {
		_cTime = _mTime;

		Entity* platform = Entity::instantiate(_platfromPrefab, _lastP);	// Se genera una plataforma en la posición antigua
		Rigidbody* pRigid = platform->getComponent<Rigidbody>();

		float posVarX = (rand() % 50) - 25;		// Variación en X
		float posVarY = (rand() % 2) - 1;		// Variación en Y
		float posVarAng = (rand() % 90) - 45;	// variación en ángulo en z

		_lastP = { _initP.x + (float)sin((_lastR.z + posVarAng) * M_PI/180) * 20, 20 + _initP.y - (float)cos((_lastR.z + posVarAng) * M_PI / 180) * 20, _lastP.z - 100 };
		_lastR = { _lastR.x, _lastR.y, _lastR.z + posVarAng };

		pRigid->setPosition({ _lastP.x, _lastP.y, _lastP.z });						// Se mueve 
		pRigid->setRotation(Quaternion::Euler({ _lastR.x, _lastR.y, _lastR.z }));	// Y orienta según las variaciones aleatorias

		if (rand() % 100 < _enemyChance && _lastP.z < -100) {		// Si debe ponerse enemigo (en la primera plataforma no)
			std::string nameEnemy = _turretPrefab;
			if (rand() % 100 > _turretChance) nameEnemy = _dronePrefab;	// Se decide cuál instanciar

			float dir = pRigid->getEntity()->getComponent<Transform>()->rotation().toEuler().z;

			pRigid = Entity::instantiate(nameEnemy, _lastP)->getComponent<Rigidbody>();
			pRigid->setPosition({ 0, -65, _lastP.z });
		}

		_myEntity->getComponent<AudioSource>()->playSound2D();
	}
}