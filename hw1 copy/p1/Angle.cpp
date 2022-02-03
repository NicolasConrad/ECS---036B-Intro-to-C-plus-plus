#include "Angle.h"
#include<iostream>
using namespace std;

void Angle::set(int t)
{
	if(t < -60)
		theta = -60;
	else if(t > 120)
		theta = 120;
	else
		theta = t;
}

Angle::Angle(void)
{
	theta = 30;
}
int Angle::get(void)
{
	return theta;
}
void Angle::change(int dt)
{
	this->set(theta+dt);
}
void Angle::print(void)
{
	cout << theta << endl;
}
