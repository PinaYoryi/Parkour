#include "DronMissile.h"
#include "SceneManager.h"
#include "PlayerController.h"

bool DronMissile::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

void DronMissile::onCollisionStart(Entity* other) {
	if (other->getName() != "Turret") {
		if (other->getName() == "Player") {
			other->getComponent<PlayerController>()->playerDead();
		}
		SceneManager::GetInstance()->addEntityToRemove(_myEntity);	// No hace nada (???)
	}
}