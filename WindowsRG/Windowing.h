#pragma once
#include <SDL3/SDL.h>

class RenderingServer {
public:
	SDL_Window* sdlWindow = nullptr;
	SDL_Renderer* sdlRenderer = nullptr;
	int width = 0;
	int height = 0;
	const char* title = nullptr;
	bool isRendering = false;
};

inline RenderingServer* CreateServer(const char* title, int w, int h) {
	RenderingServer* server = new RenderingServer();
	server->width = w;
	server->height = h;
	server->title = title;
	server->isRendering = true;
	server->sdlWindow = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE);
	server->sdlRenderer = SDL_CreateRenderer(server->sdlWindow, NULL);
	return server;
}

inline bool PollServerEvents(RenderingServer* server, SDL_Event* e) {
	SDL_GetWindowSize(server->sdlWindow, &server->width, &server->height);
	server->title = SDL_GetWindowTitle(server->sdlWindow);
	return SDL_PollEvent(e);
}

inline void RebuildServer(RenderingServer* server) {
	SDL_SetWindowSize(server->sdlWindow, server->width, server->height);
	SDL_SetWindowTitle(server->sdlWindow, server->title);
}

inline void DestroyServer(RenderingServer* server) {
	if (!server) return;
	SDL_DestroyRenderer(server->sdlRenderer);
	SDL_DestroyWindow(server->sdlWindow);
	delete server;
}
