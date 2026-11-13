#pragma once

class Window {
public:
	int x;
	int y;
	int w;
	int h;
	const char* title;
	bool closeEnabled;
	bool minimizeEnabled;
	bool maximizeEnabled;
	bool borderless;
};