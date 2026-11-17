#include <iostream>
#include <SDL3/SDL.h>
#include "stdafx.h"
#include PCH
#include BOX_H
#include LIST
#include <iostream>
#include <random>
#include "direction.h"

Box nullBox = { 0, 0, 0, 0, 0, 0, 0, 1 };
std::list<Box> boxes(4 * 4, nullBox);
int boxSize = 256 / 4;

int randiRange(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}


Box getBox(int index) {
	return *std::next(boxes.begin(), index);
}


bool filled(int id) {
	return (getBox(id) != nullBox);
}

int getIdVec2(int x, int y) {
	return y * 4 + x;
}

void moveTile(int index, Direction dir) {
	Box bx = getBox(index);
	switch (dir) {
	case DNORTH:
		bx.y--;
		break;
	case DEAST:
		bx.x++;
		break;
	case DSOUTH:
		bx.y++;
		break;
	case DWEST:
		bx.x--;
		break;
	case DNONE:
		break;
	}
}

bool isTileInDir(Direction dir, std::pair<int, int> me) {
	switch (dir) {
	case DNORTH:
		int index0 = getIdVec2(me.first, me.second - 1);
		if (getBox(index0) != nullBox) {
			return true;
		}
		break;
	case DEAST:
		int index1 = getIdVec2(me.first + 1, me.second);
		if (getBox(index1) != nullBox) {
			return true;
		}
		break;
	case DSOUTH:
		int index2 = getIdVec2(me.first, me.second + 1);
		if (getBox(index2) != nullBox) {
			return true;
		}
		break;
	case DWEST:
		int index3 = getIdVec2(me.first - 1, me.second);
		if (getBox(index3) != nullBox) {
			return true;
		}
		break;
	}

}

void moveUntilHit(int index) {

}

void moveAll() {

}

void addNumber() {
	std::vector<std::pair<int, int>> emptyCells;
	for (int ex = 0; ex < 4; ex++) {
		for (int ey = 0; ey < 4; ey++) {
			int idX = getIdVec2(ex, ey);
			if (!filled(idX)) {
				emptyCells.push_back({ ex, ey });
			}
		}
	}

	if (emptyCells.empty()) {
		return;
	}

	int randIndex = randiRange(0, emptyCells.size() - 1);
	int gx = emptyCells[randIndex].first;
	int gy = emptyCells[randIndex].second;

	int px = gx * boxSize;
	int py = gy * boxSize;

	int sv = (randiRange(1, 10) == 1) ? 4 : 2;

	Box box = { px, py, boxSize, boxSize, 255, 255, 255, sv };
	boxes.push_back(box);
}

int main() {
	SDL_Window* window = SDL_CreateWindow("2048", 256, 256, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	addNumber();

	std::cout << isTileInDir(DEAST, { 0, 0 }) << std::endl;


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