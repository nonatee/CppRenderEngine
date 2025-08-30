#include "Vector.h"
#include "Camera.h"
#include "Constants.h"
#include <iostream>
static Vector3D Intercept(Vector3D vecDir, Vector3D vecPos, Vector3D planeNormal, Vector3D planePoint) {
	float t = (planeNormal.DotProduct(planePoint) - planeNormal.DotProduct(vecPos)) / planeNormal.DotProduct(vecDir);
	return vecPos + vecDir * t;
};
Vector2D GetProjection(Camera camera, Vector3D objPos) {
	Vector3D to = objPos - camera.position;
	if(to.DotProduct(camera.lookDir) < 0) {
		return(Vector2D(-1000,-1000)); // Object is behind the camera
	}
	Vector3D planeNormal = camera.lookDir;
	Vector3D planePoint = camera.lookDir * camera.planeDistance + camera.position;
	Vector3D intercept = Intercept(to, camera.position, planeNormal, planePoint) - camera.position;
	if (intercept.GetLength() < 1e-6f || std::isnan(intercept.GetLength())) {
		return(Vector2D(0,0));
	}
	//float sina = (intercept.CrossProduct(camera.GetCamRight()).GetLength()) / (intercept.GetLength() * camera.GetCamRight().GetLength());
	//float cosa = intercept.DotProduct(camera.GetCamRight()) / (intercept.GetLength() * camera.GetCamRight().GetLength());
	//float dx = -intercept.GetLength() * cosa; WHY DOES THIS NOT WORK?
	//float dy = intercept.GetLength() * sina;
	float dx = intercept.DotProduct(camera.GetCamRight());
	float dy = intercept.DotProduct(camera.GetCamUp()) / 1.0f;
	std::cout << dx << " " << dy << "\n";
	return Vector2D(WIDTH / 2 + dx, HEIGHT / 2 + dy);
};
