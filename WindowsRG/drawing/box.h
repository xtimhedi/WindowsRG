#pragma once
#include "stdafx.h"
#include PCH

class Box {
public:
	int x;
	int y;
	int width;
	int height;

	// color
	int r;
	int g;
	int b;


	void render(SDL_Renderer* renderer);
};