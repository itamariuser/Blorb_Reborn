#include <SDL.h>
#include "classRenderer.h"


ClassRenderer::ClassRenderer(SDL_Window* win, int index, Uint32 flags):renderColor(0,0,0,0)
{
	renderer = SDL_CreateRenderer(win, index, flags);
}


Color ClassRenderer::setRenderColor(Color color)
{
	Color lastColor = renderColor;
	renderColor = color;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	return lastColor;
}

Color ClassRenderer::getRenderColor()
{
	return renderColor;
}

void ClassRenderer::clear()
{
	SDL_RenderClear(renderer);
}

void ClassRenderer::present()
{
	SDL_RenderPresent(renderer);
}


