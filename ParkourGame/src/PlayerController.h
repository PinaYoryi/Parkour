#pragma once
#include "Transform.h"
#include "Rigidbody.h"

class PlayerController : public Component {
public:
	PlayerController();

	/// <summary>
	/// Inicializa el componente con los valores pasador por parametro
	/// utiliza setMesh para poner su mesh y setMaterial para poner su material
	/// </summary>
	bool init(const std::map<std::string, std::string>& mapa) override;

	/// <summary>
	/// Mueve el componente c�mara de la entidad que tiene esta clase en
	/// base a los movimientos del raton
	/// </summary>
	void update() override;

	/// <summary>
	/// Movimientos f�sicos del jugador
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// Fija la sensibilidad del movimiento de la camara
	/// </summary>
	void setSensibility(float sen) { _sensibility = sen; }

	/// <summary>
	/// Fija la velocidad de movimiento del jugador
	/// </summary>
	void setSpeed(float speed) { _speed = speed; }

	/// <summary>
	/// Le dice al game manager que cambia de escena con todo lo que conlleva
	/// </summary>
	void playerDead();

protected:
	Transform* _trans;
	Rigidbody* _rigidbody;
	float _pitch, _yaw, _sensibility;
	float _time; //Tiempo que ha durado vivo el jugador
	float _speed;
	bool _inMenu;
};