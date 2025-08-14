#pragma once
#include "Vector.h"
struct Camera {
	Vector3D position;
	Vector3D lookDir;
	float planeDistance;

	Camera(Vector3D position, Vector3D lookDir, float planeDistance)
		: position(position), lookDir(lookDir), planeDistance(planeDistance)
	{
	}
	
	Vector3D GetCamRight() {
		Vector3D worldUp(0, 1, 0);
		return worldUp.CrossProduct(lookDir).Normalized();
	}
    Vector3D GetCamUp() {
		return GetCamRight().CrossProduct(lookDir).Normalized();
    }
	void RotateXZ(float angle) {
		angle = angle * (3.14159265358979323846f / 180.0f); // Convert degrees to radians
		float oldX = lookDir.x;
		float oldZ = lookDir.z;

		lookDir.x = oldX * cos(angle) - oldZ * sin(angle);
		lookDir.z = oldX * sin(angle) + oldZ * cos(angle);
	}
	void RotateXY(float angle) {
		angle = angle * (3.14159265358979323846f / 180.0f); // Convert degrees to radians
		float oldX = lookDir.x;
		float oldY = lookDir.y;

		lookDir.x = oldX * cos(angle) - oldY * sin(angle);
		lookDir.y = oldX * sin(angle) + oldY * cos(angle);
	}
	Vector3D RotatedXZ(float angle) {
		angle = angle * (3.14159265358979323846f / 180.0f); // Convert degrees to radians
		Vector3D newVec = lookDir;
		newVec.x = lookDir.x * cos(angle) - lookDir.z * sin(angle);
		newVec.z = lookDir.x * sin(angle) + lookDir.z * cos(angle);
		return newVec;
	}
	Vector3D RotatedXY(float angle) {
		angle = angle * (3.14159265358979323846f / 180.0f); // Convert degrees to radians
		Vector3D newVec = lookDir;
		newVec.x = lookDir.x * cos(angle) - lookDir.y * sin(angle);
		newVec.y = lookDir.x * sin(angle) + lookDir.y * cos(angle);
		return newVec;
	}
	
	
};