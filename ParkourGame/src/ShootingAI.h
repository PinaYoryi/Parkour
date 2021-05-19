#pragma once
#include "Component.h"
#include "Entity.h"

class ShootingAI : public Component {
public:
	ShootingAI() {}
	bool init(const std::map<std::string, std::string>& mapa) override;
	void update() override;
protected:
private:
	Entity* _objective;

	std::string _bala;
	float _RoF;

	float _cooldown;
};