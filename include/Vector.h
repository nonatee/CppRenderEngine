#pragma once
#include <cmath>
#include <iostream>

struct Vector2D {
	float x;
	float y;
	Vector2D(float a, float b) : x(a), y(b){}
	Vector2D operator-(const Vector2D& other) const {
		return Vector2D(x - other.x, y - other.y);
	}
	Vector2D operator*(float scalar) const {
		return Vector2D(x * scalar, y * scalar);
	}
	Vector2D operator+(const Vector2D& other) const {
		return Vector2D(x + other.x, y + other.y);
	}
};
struct Vector3D {
	float x;
	float y;
	float z;
	Vector3D(float x, float y,float z) : x(x), y(y), z(z) {}
	Vector3D operator-(const Vector3D& other) const {
		return Vector3D(x - other.x, y - other.y, z-other.z);
	}
	Vector3D operator*(float scalar) const {
		return Vector3D(x * scalar, y * scalar,z*scalar);
	}
	Vector3D operator+(const Vector3D& other) const {
		return Vector3D(x + other.x, y + other.y, z+other.z);
	}
	Vector3D CrossProduct(const Vector3D& other) const {
		return Vector3D(
			this->y * other.z - this->z * other.y,  // X
			this->z * other.x - this->x * other.z,  // Y
			this->x * other.y - this->y * other.x   // Z
		);
	}
	float DotProduct(Vector3D other) {
		return this->x * other.x + this->y * other.y + this->z + other.z;
	}
	float GetLength() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	void Normalize() {
		float length = this->GetLength();
		if (length > 0) {
			x *= (1.0f / length);
			y *= (1.0f / length);
			z *= (1.0f / length);
		}
	}
	Vector3D Normalized() {
		float length = this->GetLength();
		if (length > 0) {
			return *this * (1.0f / length);
		}
		return Vector3D(0, 0, 0); // or however you want to handle zero-length
	}
};