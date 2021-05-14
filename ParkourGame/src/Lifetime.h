#pragma once
#include "Component.h"
#include <time.h>

class Lifetime : public Component {
public:
	Lifetime() {};

	bool init(const std::map<std::string, std::string>& mapa) override;
	
	void update() override;

	float getMaxLife() { return _endTime; };

	float getStartLife() { return _startTime; };

	float getCurrentLife() { return _currentTime; };
protected:
private:
	float _endTime;		// Tiempo m�ximo que puede durar
	float _startTime;	// Tiemnpo en el cual empez�
	float _currentTime;	// Tiempo que lleva

	bool _startedYet;	// Para que no empiece a contar el tiempo hasta que se empiece a actualizar

	time_t timer;	// Temporizador usado para c�lculos

	struct tm dosmilveintiuno = { 0 };	// 1-1-2021
};