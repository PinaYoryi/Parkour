#pragma once

#include "Entity.h"
#include <vector>

enum sceneState {
	Neutral,
	Pauses,
	Continues
};

class GameManager {
public:
	~GameManager() {}

	/// <summary>
	/// Devuelve una instancia de la clase. La crea si no existe.
	/// </summary>
	static GameManager* GetInstance();

	/// <summary>
	/// Inicializa la clase GameManager con los parametros dados si no se ha inicializado antes.
	/// Devuelve true si se inicializa por primera vez y false si ya hab�a sido inicializada.
	/// </summary>
	static bool Init();
	
	/// <summary>
	/// Termina la partida. Cambia a la escena pertienente y guarda el tiempo que ha durado la partida.
	/// </summary>
	void onFinish(float time);

	/// <summary>
	/// Carga una escena teniendo en cuenta si es un menú de pausa o no
	/// </summary>
	void toScene(std::string scene, sceneState state = Neutral);

	/// <summary>
	/// Devuelve el valor de deltaTime
	/// </summary>
	float getDeltaTime();

	float getLastedTime() { return _secondsLasted; }

protected:
	static GameManager* _singleton;

	bool _paused;
	float _secondsLasted;

	GameManager() : _secondsLasted(0), _paused(false) {};
};