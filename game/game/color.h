#pragma once

#include "SDL.h"


class Color : public SDL_Color
{
public:
	Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		this->r = r; this->g = g; this->b = b; this->a = a;
	}
};