#pragma once
#include "Component.h"

class Floor : public Component {
public:
	Floor() {};
	bool init(const std::map<std::string, std::string>& mapa) override;
	void onCollisionStart(Entity* other) override;
protected:
private:
};