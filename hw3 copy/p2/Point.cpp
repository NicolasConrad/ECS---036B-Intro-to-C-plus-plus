#include<iostream>
#include"Point.h"
using namespace std;

Point Point::operator+(const Point& rhs) const
{
	Point p;
	p.x = this->x + rhs.x;
	p.y = this->y + rhs.y;
	return p;
}

Point Point::operator-(const Point& rhs) const
{
	Point p;
	p.x = this->x - rhs.x;
	p.y = this->y - rhs.y;
	return p;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.x << "," << p.y << ")" << endl; 
	return os;
}

istream& operator>>(istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}