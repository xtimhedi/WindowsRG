#include <iostream>
#include <SDL3/SDL.h>
#include "stdafx.h"

int main()
{
	RenderingServer* server = CreateServer("WindowsRG", 800, 600);
	server->isRendering = true;

	while (server->isRendering) {
		SDL_Event e;
		while (PollServerEvents(server, &e)) {
			if (e.type == SDL_EVENT_QUIT) {
				server->isRendering = false;
			}
		}
	}
	DestroyServer(server);
	SDL_Quit();
}
