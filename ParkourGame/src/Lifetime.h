#pragma once
#include "Component.h"
#include <time.h>

class Lifetime : public Component {
public:
	Lifetime();

	bool init(const std::map<std::string, std::string>& mapa) override;
	
	void update() override;

	float getMaxLife() { return _endTime; };

	float getCurrentLife() { return _currentTime; };
protected:
private:
	float _endTime;		// Tiempo máximo que puede durar
	float _currentTime;	// Tiempo que lleva

	bool _startedYet;	// Para que no empiece a contar el tiempo hasta que se empiece a actualizar
};