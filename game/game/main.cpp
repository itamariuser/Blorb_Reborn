#include "SDL.h"
#include "point.h"
#include <stdio.h>
#include "classRenderer.h"
#include "gameView.h"
#include "blorb.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TIME_FRAME_MILLIS 1000

int main(int, char**) {
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) //|SDL_INIT_EVENTS
	{
		_Printf_format_string_("%s", SDL_GetError);
	}
	GameView mainView("SDL Tutorial", SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE,1000);
	
	mainView.start();
	SDL_Delay(2 * 1000);
	SDL_Quit();
	return 0;
}

