#pragma once
#include "Component.h"
#include "Entity.h"

class DronMissile : public Component {
public:
	DronMissile() {}
	bool init(const std::map<std::string, std::string>& mapa) override;
	void onCollisionStart(Entity* other) override;
};