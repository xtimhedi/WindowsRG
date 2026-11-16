#include "stdafx.h"
#include BOX_H
#include PCH

void Box::render(SDL_Renderer* renderer) {
	SDL_FRect rect = { x, y, width, height };
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}