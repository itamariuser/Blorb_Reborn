#pragma once
#include "point.h"
#include "color.h"
#include "gameView.h"
class Graphic
{
public:
	Point center;
	Point speed;
	GameView* gView;
	float mass;
	Graphic(Point center, Point speed, GameView* gView,float mass = 1.0) : center(center), speed(speed), gView(gView), mass(mass)
	{

	}

	virtual void draw(Color c) = 0;

protected:
	virtual void next() = 0;
};

class SimpleLine : public Graphic
{
public:

	Point end;
	Point endSpeed;
	SimpleLine(Point center, Point end, GameView* gView, Point startSpeed = Point(0, 0), Point endSpeed = Point(0, 0),float mass = 1.0) : Graphic(center, startSpeed, gView, mass), end(end), endSpeed(endSpeed) {}
	SimpleLine(GameView* gView,float mass = 1.0) : Graphic(Point(0, 0), Point(0, 0), gView, mass) {}
	virtual void draw(Color c = { 255, 165, 0, 255 })
	{
		next();
		gView->brushColor = c;
		gView->renderLineColored(center, end);
	}

private:
	virtual void next()
	{
		center += speed;
		end += endSpeed;
	}
};

class Diamond : public Graphic
{
public:
	SimpleLine lu;
	SimpleLine lr;
	SimpleLine ld;
	SimpleLine ll;

	Point uEnd;
	Point rEnd;
	Point dEnd;
	Point lEnd;

	int halfHeight;
	int animationSpeed;
	float slope;
	Color secondaryColor;

	Diamond(Point center, GameView* gView, Point speed, int halfHeight, int animationSpeed, Color secondaryColor) : Graphic(center, speed, gView), lu(gView), lr(gView), ld(gView), ll(gView), halfHeight(halfHeight), animationSpeed(animationSpeed), secondaryColor(secondaryColor)
	{
		
		lu = SimpleLine(center, Point(center.x, center.y - halfHeight), gView, speed, speed);
		lr = SimpleLine(center, Point(center.x + halfHeight, center.y), gView, speed, speed);
		ld = SimpleLine(center, Point(center.x, center.y + halfHeight), gView, speed, speed);
		ll = SimpleLine(center, Point(center.x - halfHeight, center.y), gView, speed, speed);
		slope = (lr.end.y - lu.end.y) / (lr.end.x - lu.end.x) * animationSpeed;
		uEnd = lu.end;
		rEnd = lr.end;
		dEnd = ld.end;
		lEnd = ll.end;
	}
	virtual void draw(Color c = { 255, 165, 0, 255 })
	{
		next();
		gView->brushColor = c;
		gView->renderLineColored(uEnd, rEnd);
		gView->renderLineColored(rEnd, dEnd);
		gView->renderLineColored(dEnd, lEnd);
		gView->renderLineColored(lEnd, uEnd);
		gView->brushColor = secondaryColor;
		lu.draw(secondaryColor);
		lr.draw(secondaryColor);
		ld.draw(secondaryColor);
		ll.draw(secondaryColor);
	}
private:
	virtual void next()
	{
		center += speed;
		uEnd += speed;
		rEnd += speed;
		dEnd += speed;
		lEnd += speed;
		lu.end = (lu.end.y < center.y) ? lu.end + Point(slope, slope) : uEnd;
		lr.end = (lr.end.x > center.x) ? lr.end + Point(-slope, slope) : rEnd;
		ld.end = (ld.end.y > center.y) ? ld.end + Point(-slope, -slope) : dEnd;
		ll.end = (ll.end.x < center.x) ? ll.end + Point(slope, -slope) : lEnd;
	}
};

class Circle : public Graphic
{
public:

	float radius;
	Circle(Point center, Point speed, GameView* gView, float radius = 20.0f) : Graphic(center, speed, gView), radius(radius) {}

	virtual void draw(Color c = { 255, 165, 0, 255 })
	{
		gView->brushColor = c;
		next();
		int pointsNumber = 10;
		if (pointsNumber == 0)
		{
			pointsNumber = M_PI * radius / 2;
		}

		float d_a = M_PI / pointsNumber,
			angle = d_a;

		Point start, end(radius, 0.0f);
		end += center;
		for (int i = 0; i<pointsNumber * 2; i++)
		{
			start = end;
			end.x = cos(angle) * radius;
			end.y = sin(angle) * radius;
			end += center;
			angle += d_a;
			gView->renderLineColored(start, end);
		}
	}
private:
	virtual void next()
	{
		if (center.x + radius > gView->width || center.x - radius < 0)
			speed.x *= -1;
		if (center.y + radius > gView->height || center.y - radius < 0)
			speed.y *= -1;

		center += speed;
	}
};


