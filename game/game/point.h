#pragma once
#include <math.h>



class Point {
public:
	float x;
	float y;
	virtual double distanceFromPoint(Point p);

	Point(float x, float y);
	Point() {}

	Point operator+(const Point& other) { return Point(this->x + other.x,this->y+other.y); }
	void operator+=(const Point& other){ this->x += other.x; this->y += other.y; }
};