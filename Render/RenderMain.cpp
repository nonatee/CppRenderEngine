#include <iostream>
#include "Vector.h"
#include <SDL.h>
#include "Constants.h"
#include "Framebuffer.h"
#include "Tracing.h"
#include "Camera.h"
#include "Projection.h"
int radius = 100;
SDL_Event event;
int main(int argc, char* argv[]) {
	float time = 0.1;
	SDL_Window* window = SDL_CreateWindow("Framebuffer Example",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT,
		SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		WIDTH, HEIGHT);
	
	bool running = true;
	SDL_Event e;
	Camera camera(Vector3D(0, 0, 0), Vector3D(0, 0, 1), 1);
	while (running) {
		time +=0.1;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = false;
		}
		void* pixels;
		int pitch;
		setToWhite();
		
		Vector3D point1(0, 10, 10);
		Vector3D point2(-10, 0, 10);
		Vector3D point3(10, 0, 10);
		Vector2D pos1(GetProjection(camera,point1));
		Vector2D pos2(GetProjection(camera, point2));
		Vector2D pos3(GetProjection(camera, point3));
		//TraceLine(pos1, pos2);
		DrawTriangle(pos1, pos2, pos3);
		SDL_LockTexture(texture, nullptr, &pixels, &pitch);
		memcpy(pixels, framebuffer, WIDTH * HEIGHT * sizeof(uint32_t));
		SDL_UnlockTexture(texture);

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
		const Uint8* keyState = SDL_GetKeyboardState(NULL);

		if (keyState[SDL_SCANCODE_W]) {
			camera.position = camera.position + camera.lookDir;
		}
		if (keyState[SDL_SCANCODE_A]) {
			camera.position = camera.position + camera.GetCamRight()*-1.0f;
		}
		if (keyState[SDL_SCANCODE_S]) {
			camera.position = camera.position + camera.lookDir*-1.0f;
		}
		if (keyState[SDL_SCANCODE_D]) {
			camera.position = camera.position + camera.GetCamRight();
		}
		if (keyState[SDL_SCANCODE_UP]) {
			camera.RotateXY(10);
		}
		if (keyState[SDL_SCANCODE_DOWN]) {
			camera.RotateXY(-10);
		}
		if (keyState[SDL_SCANCODE_LEFT]) {
			camera.RotateXZ(10);
		}
		if (keyState[SDL_SCANCODE_RIGHT]) {
			camera.RotateXZ(-10);
		}
		if (keyState[SDL_SCANCODE_ESCAPE]) {
			running = true;
		}
		SDL_Delay(100);
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}