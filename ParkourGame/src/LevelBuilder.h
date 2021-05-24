#pragma once
#include "Component.h"
#include "Transform.h"

class LevelBuilder : public Component {
public:
	LevelBuilder();
	bool init(const std::map<std::string, std::string>& mapa) override;
	void update() override;
protected:
private:
	std::string _platfromPrefab;	// Plataforma que pondrá
	std::string _turretPrefab;		// Torretas que pondrá
	std::string	_dronePrefab;		// Drones que pondrá
	Vector3<> _initP;
	Vector3<> _lastP;				// Posición de la última plataforma puesta
	Vector3<> _lastR;				// Rotación de la última plataforma puesta

	float _mTime;					// Tiempo máximo entre plataformas
	float _cTime;					// Tiempo restante entre plataformas

	float _enemyChance;				// Probabilidad de generar enemigo
	float _turretChance;			// Probabilidad de generar torreta
};