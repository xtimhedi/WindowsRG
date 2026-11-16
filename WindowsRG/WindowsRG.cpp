#include <iostream>
#include <SDL3/SDL.h>
#include "stdafx.h"
#include PCH
#include BOX_H
#include LIST
#include <iostream>
#include <random>

int randiRange(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

std::list<Box> boxes;

Box getBox(int index) {
	return *std::next(boxes.begin(), index);
}

int boxSize =  256 / 4;

enum Direction {
	NORTH, EAST, SOUTH, WEST
};

#define NORTH Direction::NORTH
#define EAST Direction::EAST
#define SOUTH Direction::SOUTH
#define WEST Direction::WEST

void moveTile(int index, Direction dir) {
	Box bx = getBox(index);
	switch (dir) {
	case NORTH:
		bx.y--;
	case EAST:
		bx.x++;
	case SOUTH:
		bx.y++;
	case WEST:
		bx.x--;
	}
}

void addNumber() {
	// calc random pos
	int x = randiRange(0, 4) * boxSize;
	int y = randiRange(0, 4) * boxSize;
	Box box = { x, y, boxSize, boxSize, 255, 255, 255 };
	boxes.push_back(box);
}

int main() {
	SDL_Window* window = SDL_CreateWindow("2048", 256, 256, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	addNumber();

	bool running = true;
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		for (auto box : boxes) {
			box.render(renderer);
		}

		SDL_RenderPresent(renderer);
	}
}