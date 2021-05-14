#include "Floor.h"
#include "Entity.h"
#include "Rigidbody.h"

bool Floor::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

void Floor::onCollisionStart(Entity* other) {
	if (other->getComponent<PlayerController>() != nullptr) {
		other->getComponent<Rigidbody>()->setGravity(Vector3<>(0, 1, 0));
	}
}