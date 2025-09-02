#include "Vector.h"
#include "FrameBuffer.h"
#include <cmath>
#include <iostream>
#include <chrono>

void TraceLine(Vector2D pos1, Vector2D pos2) {
	//auto start = std::chrono::high_resolution_clock::now();
	if (pos1.x < 0 || pos1.x >= WIDTH || pos1.y < 0 || pos1.y >= HEIGHT
		|| std::isnan(pos1.x) || std::isnan(pos1.y)
		|| std::isnan(pos2.x) || std::isnan(pos2.y)) {
		return;
	}
	if (pos2.x < 0 || pos2.x >= WIDTH || pos2.y < 0 || pos2.y >= HEIGHT) {
		return;
	}
	float divisor = 100;
	float dx = (pos2.x - pos1.x);
	float dy = (pos2.y - pos1.y);
	int counter = 0;

	for (float percentage = 0; percentage <= 1; percentage += 1/divisor) {
		int pixelX = static_cast<int>(std::floor(pos1.x + dx * percentage + 0.5));
		int pixelY = static_cast<int>(std::floor(pos1.y + dy * percentage + 0.5));
		framebuffer[pixelX + WIDTH * pixelY] = black;
		//std::cout << "x=" << pos1.x + dx * percentage << " y=" << pos1.y + dy * percentage << "\n";
		counter++;
	};
	//std::cout << "traced line from: " << pos1.x << ", " << pos1.y << " and " << pos1.x << ", " << pos1.y << "\n";
	//std::cout << counter << "\n";
	//auto end = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	//std::cout << "Function took " << duration.count() << " microseconds.\n";
};
void DrawTriangle(Vector2D pos1, Vector2D pos2, Vector2D pos3) {
	if (std::isnan(pos1.x) || std::isnan(pos1.y) ||
		std::isnan(pos2.x) || std::isnan(pos2.y) ||
		std::isnan(pos3.x) || std::isnan(pos3.y) ||
		pos1.x > WIDTH || pos1.y > HEIGHT ||
		pos2.x > WIDTH || pos2.y > HEIGHT ||
		pos3.x > WIDTH || pos3.y > HEIGHT) {
		return;
	}
	float divisor = 100;
	for (float percentage = 0; percentage <= 1; percentage += 1 / divisor) {
		TraceLine(pos2 + ((pos1 - pos2) * percentage), pos3 + ((pos1 - pos3) * percentage));
	};
};