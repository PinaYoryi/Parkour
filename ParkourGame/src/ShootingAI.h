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
	Entity* _objective;	// Objetivo de los disparos
	string _bala;		// Prefab de la bala
	float _RoF;			// Segundos que hay que esperar por cada disparo
	float _cooldown;	// Segundo hasta el último disparo
};