#pragma once
#include "Component.h"
#include "Transform.h"

class CameraController : public Component
{
public:
	CameraController();

	/// <summary>
	/// Inicializa las variables según el mapa
	/// </summary>
	bool init(const std::map<std::string, std::string>& mapa) override;

	/// <summary>
	/// Mueve el componente camara de la entidad que tiene esta clase en
	/// base a los movimientos del raton
	/// </summary>
	void update() override;

	/// <summary>
	/// Fija la sensibilidad del movimiento de la camara
	/// </summary>	
	void setSensibility(float sen) { _sensibility = sen; }
private:
	float _pitch, _yaw, _sensibility;	// Rotaciones de la cámara


	Transform* _trans;
};