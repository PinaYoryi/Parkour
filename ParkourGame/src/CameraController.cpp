#include "CameraController.h"
#include "Input.h"
#include "OgreMotor.h"
#include <OgreRenderWindow.h>
#include "Vector3.h"
#include "Entity.h"

CameraController::CameraController():
	_sensibility(0),
	_pitch(0),
	_yaw(0)
{
}

bool CameraController::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("sensibility") == mapa.end()) return false;

	_trans = _myEntity->getComponent<Transform>();

	std::string s = mapa.at("sensibility");
	_sensibility = std::stof(s);

	return true;
}

void CameraController::update() {
	if (!_active) return;
	Ogre::RenderWindow* win = OgreMotor::GetInstance()->getRenderWindow();
	Vector2<int> center(win->getWidth() / 2, win->getHeight() / 2);
	Vector2<int> dir = Input::GetInstance()->getMousePos() - center;

	_pitch -= dir.y * _sensibility;
	if (_pitch > 90) _pitch = 90;
	else if (_pitch < -90) _pitch = -90;

	_yaw -= dir.x * _sensibility;
	if (_yaw >= 180) _yaw -= 360;
	else if (_yaw < -180) _yaw += 360;

	_trans->setLocalRotation(Quaternion::Euler({ _pitch, _yaw,  0 }));
	Input::GetInstance()->setMousePos(center);
	
}
