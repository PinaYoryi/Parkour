#include "Floor.h"
#include "Entity.h"
#include "Rigidbody.h"
#include <math.h>
#include "PlayerController.h"
#include "Quaternion.h"

bool Floor::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

void Floor::onCollisionStart(Entity* other) {
	if (other->getName() == "Player") {
		Vector3<> dir = _myEntity->getComponent<Transform>()->rotation().toVector();
		dir = dir.rotate(90, { -1, 0, 0 });
		other->getComponent<Rigidbody>()->setGravity(dir.normalized() * 9.8);
		other->getComponent<PlayerController>()->restoreJumps();
	}
}

void Floor::onCollisionEnd(Entity* other) {
	if (other->getName() == "Player") {
		other->getComponent<PlayerController>()->becomesAirborne();
	}
}