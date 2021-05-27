#pragma once
#include "Transform.h"
#include "Rigidbody.h"

const int MAX_JUMP = 2;
const int TIME_ALIVE_FALLING = 5;
const int DEFAULT_SENSITIVITY = 1.0;
const int DEFAULT_SPEED = 250;

class PlayerController : public Component {
public:
	PlayerController();

	/// <summary>
	/// Inicializa el componente con los valores pasador por parametro
	/// utiliza setMesh para poner su mesh y setMaterial para poner su material
	/// </summary>
	bool init(const std::map<std::string, std::string>& mapa) override;

	void update() override;

	/// <summary>
	/// Movimientos f�sicos del jugador
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// Fija la velocidad de movimiento del jugador
	/// </summary>
	void setSpeed(float speed) { _speed = speed; }

	/// <summary>
	/// Le dice al game manager que cambia de escena con todo lo que conlleva
	/// </summary>
	void playerDead();

	/// <summary>
	/// Resetea el número de saltos que puede hacer
	/// </summary>
	void restoreJumps();

	/// <summary>
	/// Se avisa cuando el jugador deja de tocar el suelo.
	/// </summary>
	void becomesAirborne() { _airborne = true; _timeFalling = 0; };

protected:
	Transform* _trans;
	Rigidbody* _rigidbody;
	float _time;	//	Tiempo que ha durado vivo el jugador
	float _speed;	// Velocidad cuando te mueves

	int _maxJump;	// Máximo número de saltos
	int _remJump;	// Saltos que le quedan

	int _jumpStr;	// Potencia del salto

	bool _airborne = false;
	float _timeFalling; // Tiempo que lleva cayendo el jugador

	Transform* _camTrans;

	float _playerLived;	// Tiempo total que ha aguantado el jugador
};