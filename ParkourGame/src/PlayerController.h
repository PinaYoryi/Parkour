#pragma once
#include "Transform.h"

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
	/// Fija la sensibilidad del movimiento de la camara
	/// </summary>
	void setSensibility(float sen) { _sensibility = sen; }

	/// <summary>
	/// Le dice al game manager que cambia de escena con todo lo que conlleva
	/// </summary>
	void playerDead();

protected:
	Transform* _trans;
	float _pitch, _yaw, _sensibility;
	float _time;
};