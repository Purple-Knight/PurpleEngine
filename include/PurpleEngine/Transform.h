#pragma once
#include <PurpleEngine.h>
#include <Vector2.h>

class PURPLE_ENGINE_API Transform
{
public:	
	
	Vector2<float> position;
	float rotation;
	Vector2<float> scale;
 
	Transform();
	Transform(const Transform&) = delete;
	Transform(Transform&&) = delete;
	~Transform() = default;

	Transform& operator=(const Transform&) = delete;
	Transform& operator=(Transform&&) = delete;

	void SetPosition(Vector2<float> position);
	void SetPosition(float x, float y) { SetPosition(Vector2<float>(x, y)); }
	void SetRotation(float rotation);
	void SetScale(Vector2<float> scale);
	void SetScale(float x, float y) { SetPosition(Vector2<float>(x, y)); }
	
	Vector2<float> TransformPoint(Vector2<float> position);
	inline Vector2<float> TransformPoint(float x, float y) { return TransformPoint(Vector2<float>(x, y)); }

private:


};