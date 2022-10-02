#pragma once
#include <PurpleEngine.h>

template <class T> 
class Vector2
{
public:
	Vector2();
	Vector2(T x, T y);
	Vector2(const Vector2&) = default;
	Vector2(Vector2&&) = default;
	~Vector2() = default;

	T x;
	T y;

	Vector2& operator=(const Vector2&) = default;
	Vector2& operator=(Vector2&&) = default;

	inline Vector2<T>& operator+(const Vector2<T>& vec) { return Vector2<T>(x + vec.x, y + vec.y); }
	inline Vector2<T>& operator+=(const Vector2<T>& vec) { x += vec.x; y += vec.y; return *this; }

	inline Vector2<T>& operator-(const Vector2<T>& vec) { return Vector2<T>(x - vec.x, y - vec.y); }
	inline Vector2<T>& operator-=(const Vector2<T>& vec) { x -= vec.x; y -= vec.y; return *this; }

	inline Vector2<T>& operator*(const int& scalar) { return Vector2<T>(x * scalar, y * scalar); }
	inline Vector2<T>& operator*=(const int& scalar) { x *= scalar; y *= scalar; return *this; }
	inline Vector2<T>& operator*(const float& scalar) { return Vector2<T>(x * scalar, y * scalar); }
	inline Vector2<T>& operator*=(const float& scalar) { x *= scalar; y *= scalar; return *this; }

	inline Vector2<T>& operator/(const int& scalar) { return Vector2<T>(x / scalar, y / scalar); }
	inline Vector2<T>& operator/=(const int& scalar) { x /= scalar; y /= scalar; return *this; }
	inline Vector2<T>& operator/(const float& scalar) { return Vector2<T>(x / scalar, y / scalar); }
	inline Vector2<T>& operator/=(const float& scalar) { x /= scalar; y /= scalar; return *this; }
};

template <class T>
Vector2<T>::Vector2() : x(0.0f), y(0.0f)
{
}

template <class T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y)
{
}