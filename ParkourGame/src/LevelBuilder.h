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
	Transform* _lastTransform;		// Transform de la última plataforma puesta

	float _mTime;					// Tiempo máximo entre plaatformas
	float _cTime;					// Tiempo restante entre plataformas
};