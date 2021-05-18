#include "PlayerController.h"
#include "Entity.h"
#include "Input.h"
#include "OgreMotor.h"
#include <OgreRenderWindow.h>
#include "GameManager.h"

PlayerController::PlayerController() : _trans(nullptr), _rigidbody(nullptr), _sensibility(0), _pitch(0), _yaw(0), _speed(0), _inMenu(false) {
}

bool PlayerController::init(const std::map<std::string, std::string>& mapa) {
	//TODO: rellenar init con los valores del mapa
	//El try es necesario para que no explote la aplicacion si no hay camara que usar
	_trans = _myEntity->getComponent<Transform>();
	_rigidbody = _myEntity->getComponent<Rigidbody>();
	_pitch = _yaw = 0;
	_sensibility = 1.0f;
	_speed = 250.0f;
	_inMenu = false;
	_maxJump = _remJump = 2;
	return true;
}

void PlayerController::update() {
	if (!_active) return;
	if (Input::GetInstance()->keyDown(SDL_SCANCODE_ESCAPE)) _inMenu = !_inMenu;
	if (!_inMenu) {
		_time += GameManager::GetInstance()->getDeltaTime();
		Ogre::RenderWindow* win = OgreMotor::GetInstance()->getRenderWindow();
		Vector2<int> center(win->getWidth() / 2, win->getHeight() / 2);
		Vector2<int> dir = Input::GetInstance()->getMousePos() - center;

		_pitch -= dir.y * _sensibility;
		if (_pitch > 90) _pitch = 90;
		else if (_pitch < -90) _pitch = -90;

		_yaw -= dir.x * _sensibility;
		if (_yaw >= 180) _yaw -= 360;
		else if (_yaw < -180) _yaw += 360;

		_trans->setLocalRotation(Quaternion::Euler({ _pitch, _yaw, 0 }));
		Input::GetInstance()->setMousePos(center);
	}
}

void PlayerController::fixedUpdate() {
	bool moveInput = false;
	float rotation = 0;
	if (Input::GetInstance()->keyHold(SDL_SCANCODE_W)) {
		std::cout << "W: ";
		moveInput = true;
	}
	else if (Input::GetInstance()->keyHold(SDL_SCANCODE_A)) {
		std::cout << "A: ";
		rotation = 270;
		moveInput = true;
	}
	else if (Input::GetInstance()->keyHold(SDL_SCANCODE_S)) {
		std::cout << "S: ";
		rotation = 180;
		moveInput = true;
	}
	else if (Input::GetInstance()->keyHold(SDL_SCANCODE_D)) {
		std::cout << "D: ";
		rotation = 90;
		moveInput = true;
	}

	if (moveInput) {
		Vector3<> dir = _trans->rotation().toVector();
		dir = dir.rotate(rotation, _rigidbody->getGravity());
		_rigidbody->addForce(dir * _speed);
	}

	if (Input::GetInstance()->keyDown(SDL_SCANCODE_SPACE) && _remJump-- > 0) {
		std::cout << "SALTA\n";
		_rigidbody->addForce(_rigidbody->getGravity().normalized() * -5000);
	}
}

void PlayerController::restoreJumps() {
	_remJump = _maxJump;
}

void PlayerController::playerDead() {
	GameManager::GetInstance()->onFinish(false, _time);
}