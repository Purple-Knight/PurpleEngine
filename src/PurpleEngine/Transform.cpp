#include <Transform.h>
#include <iostream>
#include <PMath.h>

Transform::Transform() : position(Vector2<float>()), rotation(0.0f), scale(Vector2<float>()) 
{

}

void Transform::SetPosition(Vector2<float> position)
{
	this->position = position;
}

void Transform::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void Transform::SetScale(Vector2<float> scale)
{
	this->scale = scale;
}

Vector2<float> Transform::TransformPoint(Vector2<float> position)
{
	position.x *= scale.x;
	position.y *= scale.y;
	return Vector2<float>(position.x * std::cos(rotation * PMath::DEG2RAD) - position.y * std::sin(rotation * PMath::DEG2RAD) + this->position.x, position.x * std::sin(rotation * PMath::DEG2RAD) + position.y * std::cos(rotation * PMath::DEG2RAD) + this->position.y);
}