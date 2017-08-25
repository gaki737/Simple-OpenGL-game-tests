#include "Player.h"

const double pi180 = 0.017453292519943295769236907684886;


Player::Player(Vector3 pos)
{
	this->position = pos;
	this->cam = Camera(pos);
	bb = BoundingBox(pos, 0.5f, 0.5f, 1.8f);
}

void Player::MoveRight(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw - 90)*pi180);
	direction.z = delta * cos((this->yaw - 90)*pi180);
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::MoveLeft(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw + 90)*pi180);
	direction.z = delta * cos((this->yaw + 90)*pi180);
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::MoveForward(double delta)
{
	Vector3 direction;

	direction.x = delta * sin((this->yaw)*pi180);
	direction.z = delta * -cos((this->yaw)*pi180);
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::MoveBackwards(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw)*pi180);
	direction.z = delta * cos((this->yaw)*pi180);
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::MoveUp(double delta)
{
	Vector3 direction;
	direction = Vector3(0, 1, 0)*delta;
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::MoveDown(double delta)
{
	Vector3 direction;
	direction = Vector3(0, -1, 0)*delta;
	this->position = this->position + (direction*this->movementSpeed);
	this->bb.moveBB(direction*this->movementSpeed);
	this->cam.move(direction, this->movementSpeed);
}

void Player::rotate(float _yaw, float _pitch)
{
	float yaw = _yaw*this->mouseSensitivity;
	float pitch = _pitch*this->mouseSensitivity;
	this->cam.rotate(yaw, pitch);
	

	this->yaw += yaw;

	if (this->yaw >= 360 || this->yaw <= -360)
		this->yaw = 0;

	if ((this->pitch + pitch) <= 90 && (this->pitch + pitch) >= -90)
	{
		this->pitch += pitch;
	}
}
