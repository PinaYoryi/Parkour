#include "Lifetime.h"
#include "SceneManager.h"
#include "SceneManager.cpp"
#include "LevelBuilder.h"
#include "MotorLoop.h"
#include <random>
LevelBuilder::LevelBuilder() {}

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
		
		Entity* platform = Entity::instantiate(_platfromPrefab, _lastP);	// Se genera una plataforma en la posici�n antigua
		Rigidbody* pRigid = platform->getComponent<Rigidbody>();
		
		float posVarX = (rand() % 50) - 25;		// Variaci�n en X
		float posVarY = (rand() % 2) - 1;		// Variaci�n en Y
		float posVarAng = (rand() % 90) - 45;	// variaci�n en �ngulo en z

		_lastP = { _lastP.x + posVarX, _lastP.y + posVarY, _lastP.z - 100 };
		_lastR = { _lastR.x, _lastR.y, _lastR.z + posVarAng };

		pRigid->setPosition({ _lastP.x, _lastP.y, _lastP.z });						// Se mueve 
		pRigid->setRotation(Quaternion::Euler({ _lastR.x, _lastR.y, _lastR.z }));	// Y orienta seg�n las variaciones aleatorias

		if (rand() % 100 < _enemyChance) {		// Si debe ponerse enemigo
			std::string nameEnemy = _turretPrefab;
			if (rand() % 100 > _turretChance) nameEnemy = _dronePrefab;	// Se decide cu�l instanciar
			
			float dir = pRigid->getEntity()->getComponent<Transform>()->rotation().toEuler().z;
			
			pRigid = Entity::instantiate(nameEnemy, _lastP)->getComponent<Rigidbody>();
			pRigid->setPosition({ _lastP.x + (float)sin(dir * M_PI / 180.0f) * 45 , _lastP.y + (float)cos(dir * M_PI / 180.0f) * 45, _lastP.z });
			pRigid->setRotation(Quaternion::Euler({ _lastR.x, _lastR.y, _lastR.z }));
		}

		_myEntity->getComponent<AudioSource>()->playSound2D();
	}
}