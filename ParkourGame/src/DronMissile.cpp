#include "DronMissile.h"
#include "SceneManager.h"
#include "BasicAI.cpp"

bool DronMissile::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

// Destruye la bala al chocar con algo; si es "Sinbad", dice qu elo ha matado (cuando haya buen descraga de escenas se le matará)
void DronMissile::onCollisionStart(Entity* other) {
	if (other->getName() != "Drone") {
		if (other->getName() == "Sinbad") {
			std::cout << "Sinbad gets fucking shot\n";
		}
		SceneManager::GetInstance()->addEntityToRemove(_myEntity);
		std::cout << "Bullet resigned!";
	}
}