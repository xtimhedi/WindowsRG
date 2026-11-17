#include "stdafx.h"
#include BOX_H
#include PCH
#include <string>

void Box::render(SDL_Renderer* renderer) {
	SDL_FRect rect = { x, y, width, height };
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);

	std::string text = std::to_string(number);

	SDL_SetRenderScale(renderer, 4, 4);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDebugText(
		renderer,
		(x + (width - text.length() * SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 4.0f) / 2.0f) / 4.0f,
		(y + (height - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 4.0f) / 2.0f) / 4.0f,
		text.c_str()
	);
	SDL_SetRenderScale(renderer, 1, 1);
}
