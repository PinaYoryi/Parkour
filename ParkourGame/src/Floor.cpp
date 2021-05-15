#include "Floor.h"
#include "Entity.h"
#include "Rigidbody.h"
#include <math.h>

bool Floor::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

void Floor::onCollisionStart(Entity* other) {
	if (other->getComponent<PlayerController>() != nullptr) {
		Vector3<> ang = other->getComponent<Transform>()->rotation().toEuler();
		ang *= M_PI_2 / 180; // A radianes
		other->getComponent<Rigidbody>()->setGravity({ -cos(ang.y) * sin(ang.x) * sin(ang.z) - sin(ang.y) * cos(ang.z), 
			-sin(ang.y) * sin(ang.x) * sin(ang.z) + cos(ang.y) * cos(ang.z),
			cos(ang.x) * sin(ang.z) });
		//other->getComponent<PlayerController>()->resetJump();
	}
}