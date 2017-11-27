#pragma once
#include <SDL.h>
#include "color.h"
#include <unordered_map>
#include <functional>
class GameView
{
public:
	char* title;
	int xPos;
	int yPos;
	int width;
	int height;
	Uint32 flags;
	int timeFrame;


	SDL_Window *mainWindow;
	ClassRenderer ren;

	Color backgroundColor;
	Color brushColor;

	GameView(char* ntitle, int nxPos, int nyPos, int nwidth, int nheight, Uint32 nflags, int nnewTimeFrame);

	void start();
	bool renderLineColored(const Point start, const Point end);
private:
	bool stop;
	bool canCont;
	void displayOpeningScreen();
	void handleInput();
	void shutdown();
	void mainLoop();
	std::unordered_map<SDL_Keycode, std::function<void(void)>> map;
	void inputLoop();

};