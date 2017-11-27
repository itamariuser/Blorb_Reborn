#include "point.h"
#include <SDL.h>

class Circle {
public:
	Circle(Point c, float r) : center(c), radius(r) {};
	Point center;
	float radius;
};