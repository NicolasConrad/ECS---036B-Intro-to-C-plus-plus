#include<iostream>
#include "Shape.h"
using namespace std;

//Rectangle

Rectangle::~Rectangle(void){}

void Rectangle::draw(void) const 
{
	cout << "<rect x=\"" << position.x << "\" y=\"" << position.y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
}

bool Rectangle::fits_in(const Rectangle& r) const
{
	if(position.x >= r.position.x && position.x <= r.position.x + r.width && position.y >= r.position.y && position.y <= r.position.y + r.height 
	    && position.x + width <= r.position.x + r.width && position.y + height <= r.position.y + r.height)
		return true;
	else
		return false;
}

bool Rectangle::overlaps(const Rectangle& r) const
{
	if( position.x + width <= r.position.x || position.y + height <= r.position.y || position.x >= r.position.x + r.width || position.y >= r.position.y + r.height)
		return false;
	else
		return true;
}

bool Rectangle::overlaps(const Circle& r) const
{
	int xmin = min(max(r.center.x, position.x), position.x + width);
	int ymin = min(max(r.center.y, position.y), position.y + height);
	int dx = xmin - r.center.x;
	int dy = ymin - r.center.y;
	int dsquared = (dx*dx) + (dy*dy);
	int rSquared = r.radius * r.radius;
	if(dsquared < rSquared)
		return true;
	return false;
}

bool Rectangle::overlaps(const Shape& s) const
{
	return s.overlaps(*this);
}

//Circle
Circle::~Circle(void){}

void Circle::draw(void) const 
{
	cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"/>" << endl;
}

bool Circle::fits_in(const Rectangle& r) const
{
	if(center.x - radius >= r.position.x && center.x + radius <= r.position.x + r.width && center.y - radius >= r.position.y && center.y + radius <= r.position.y + r.height)
		return true;
	return false;
}

bool Circle::overlaps(const Rectangle& r) const
{
	r.overlaps(*this);
}

bool Circle::overlaps(const Circle& r) const
{
	int dx = center.x - r.center.x;
	int dy = center.y - r.center.y;
	int dSquared = (dx*dx) + (dy*dy);
	int rSumSquared = (radius + r.radius)*(radius + r.radius);
	if(dSquared < rSumSquared)
	{
		return true;
	}
	return false;
}

bool Circle::overlaps(const Shape& s) const
{
	return s.overlaps(*this);
}