#include "PlayerController.h"
#include "Entity.h"
#include "Input.h"
#include "OgreMotor.h"
#include <OgreRenderWindow.h>
#include "GameManager.h"

PlayerController::PlayerController() :
	_trans(nullptr),
	_rigidbody(nullptr),
	_sensibility(0),
	_time(0),
	_timeFalling(0),
	_pitch(0),
	_yaw(0),
	_speed(0),
	_maxJump(0),
	_remJump(0),
	_airborne(false),
	_inMenu(false) {
}

bool PlayerController::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("sensibility") == mapa.end() || mapa.find("speed") == mapa.end() || mapa.find("maxJump") == mapa.end()) return false;

	_trans = _myEntity->getComponent<Transform>();
	_rigidbody = _myEntity->getComponent<Rigidbody>();

	_pitch = _yaw = 0;

	std::string s = mapa.at("sensibility");
	_sensibility = std::stof(s);

	s = mapa.at("speed");
	_speed = std::stof(s);

	_inMenu = false;
	_airborne = false;

	s = mapa.at("maxJump");
	_maxJump = _remJump = std::stoi(s);

	return true;
}

void PlayerController::update() {
	if (!_active) return;
	if (Input::GetInstance()->keyDown(SDL_SCANCODE_ESCAPE)) _inMenu = !_inMenu;
	if (!_inMenu) {
		_time += GameManager::GetInstance()->getDeltaTime();
		if (_airborne) {
			_timeFalling += GameManager::GetInstance()->getDeltaTime();
			if (_timeFalling >= TIME_ALIVE_FALLING) playerDead();
		}
		Ogre::RenderWindow* win = OgreMotor::GetInstance()->getRenderWindow();
		Vector2<int> center(win->getWidth() / 2, win->getHeight() / 2);
		Vector2<int> dir = Input::GetInstance()->getMousePos() - center;

		_pitch -= dir.y * _sensibility;
		if (_pitch > 90) _pitch = 90;
		else if (_pitch < -90) _pitch = -90;

		_yaw -= dir.x * _sensibility;
		if (_yaw >= 180) _yaw -= 360;
		else if (_yaw < -180) _yaw += 360;

		Vector3<> gravity = _rigidbody->getGravity().normalized();
		_trans->setLocalRotation(Quaternion::Euler({ _pitch, _yaw,  0 }));
		Input::GetInstance()->setMousePos(center);
	}
}

void PlayerController::fixedUpdate() {
	bool moveInput = false;
	Vector3<> rotation = { 0,0,0 };
	if (Input::GetInstance()->keyHold(SDL_SCANCODE_W)) {
		rotation += {1, 0, 0};
		moveInput = true;
	}
	else if (Input::GetInstance()->keyHold(SDL_SCANCODE_S)) {
		rotation += {-1, 0, 0};
		moveInput = true;
	}

	if (Input::GetInstance()->keyHold(SDL_SCANCODE_A)) {
		rotation += {0, 0, -1};
		moveInput = true;
	}
	else if (Input::GetInstance()->keyHold(SDL_SCANCODE_D)) {
		rotation += {0, 0, 1};
		moveInput = true;
	}

	if (moveInput) {
		rotation.normalize();
		Vector3<> dir = _trans->rotation().toVector();
		dir = dir.crossProduct(_rigidbody->getGravity()).rotate(90, _rigidbody->getGravity()).normalize();
		dir = dir.rotate((180 / M_PI) * atan2(rotation.z, rotation.x), _rigidbody->getGravity());
		_rigidbody->addForce(dir * _speed);
	}

	if (Input::GetInstance()->keyDown(SDL_SCANCODE_SPACE) && _remJump-- > 0) {
		_rigidbody->addForce(_rigidbody->getGravity().normalized() * -5000);
	}
}

void PlayerController::restoreJumps() {
	_airborne = false;
	_remJump = _maxJump;
}

void PlayerController::playerDead() {
	GameManager::GetInstance()->onFinish(_time);
}