#include "BoundingBox.h"



void BoundingBox::moveBB(const Vector3 & dist)
{
	this->Center = this->Center + dist;

	this->LeftUpFront = this->LeftUpFront + dist;
	this->RightUpFront = this->RightUpFront + dist;
	this->RightDownFront = this->RightDownFront + dist;
	this->LeftDownFront = this->LeftDownFront + dist;

	this->LeftUpBack = this->LeftUpBack + dist;
	this->RightUpBack = this->RightUpBack + dist;
	this->RightDownBack = this->RightDownBack + dist;
	this->LeftDownBack = this->LeftDownBack + dist;
}

BoundingBox::BoundingBox(Vector3 pos, float width, float length, float height)
{
	this->Center = pos;
	this->height = height;
	this->length = length;
	this->width = width;

	this->LeftUpFront = Vector3(pos.x - (this->width / 2), pos.y + (this->height / 2), pos.z + (this->length / 2));
	this->RightUpFront = Vector3(pos.x + (this->width / 2), pos.y + (this->height / 2), pos.z + (this->length / 2));
	this->RightDownFront = Vector3(pos.x + (this->width / 2), pos.y - (this->height / 2), pos.z + (this->length / 2));
	this->LeftDownFront = Vector3(pos.x - (this->width / 2), pos.y - (this->height / 2), pos.z + (this->length / 2));

	this->LeftUpBack = Vector3(pos.x - (this->width / 2), pos.y + (this->height / 2), pos.z - (this->length / 2));
	this->RightUpBack = Vector3(pos.x + (this->width / 2), pos.y + (this->height / 2), pos.z - (this->length / 2));
	this->RightDownBack = Vector3(pos.x + (this->width / 2), pos.y - (this->height / 2), pos.z - (this->length / 2));
	this->LeftDownBack = Vector3(pos.x - (this->width / 2), pos.y - (this->height / 2), pos.z - (this->length / 2));
}
