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
		float dir = _myEntity->getComponent<Transform>()->rotation().toEuler().z;
		other->getComponent<Rigidbody>()->setGravity({ (float)sin(dir * M_PI / 180.0f) * 9.8f, -(float)cos(dir * M_PI / 180.0f) * 9.8f, 0.0f });
		other->getComponent<Rigidbody>()->setRotation(Quaternion::Euler({ 0.0f, 0.0f, dir }));
		other->getComponent<PlayerController>()->restoreJumps();
	}
}

void Floor::onCollisionEnd(Entity* other) {
	if (other->getName() == "Player") {
		other->getComponent<PlayerController>()->becomesAirborne();
		//other->getComponent<Rigidbody>()->setGravity({ 0.0f, -9.8f, 0.0f });
	}
}