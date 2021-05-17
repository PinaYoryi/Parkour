#include "DronMissile.h"
#include "SceneManager.h"

bool DronMissile::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

void DronMissile::onCollisionStart(Entity* other) {
	//if (other->hasComponent<PlayerController>()) {
	if (other->getName() != "Drone") {
		if (other->getName() == "Sinbad") {
			//hacer algo, destruir? quitarle vida?
			std::cout << "Sinbad gets fucking shot\n";
		}
		SceneManager::GetInstance()->addEntityToRemove(_myEntity);
	}
}