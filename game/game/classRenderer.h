#include <SDL.h>
#include "color.h"
class ClassRenderer
{
public:
	SDL_Renderer* renderer;
	Color renderColor;

	ClassRenderer():renderColor(0,0,0,0) {};
	ClassRenderer(SDL_Window* win, int index, Uint32 flags);
	Color setRenderColor(Color color);
	void clear();
	void present();
	Color getRenderColor();
};