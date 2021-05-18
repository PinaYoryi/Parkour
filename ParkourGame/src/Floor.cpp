#include "Floor.h"
#include "Entity.h"
#include "Rigidbody.h"
#include <math.h>
#include "PlayerController.h"
#include "Quaternion.h"

bool Floor::init(const std::map<std::string, std::string>& mapa) {
	return true;
}

// Si es el "Sinbad", cambia su gravedad a la negativa de su normal
void Floor::onCollisionStart(Entity* other) {
	if (other->getName() == "Sinbad") {
		Vector3<> dir = _myEntity->getComponent<Transform>()->rotation().toVector();
		dir = dir.rotate(90, { -1, 0, 0 });
		cout << dir << "\n";
		other->getComponent<Rigidbody>()->setGravity(dir.normalized() * 9.8);
		other->getComponent<Transform>()->setRotation(_myEntity->getComponent<Transform>()->rotation());
		other->getComponent<PlayerController>()->restoreJumps();
	}
}