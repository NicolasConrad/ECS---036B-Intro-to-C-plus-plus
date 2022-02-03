#include "Fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Fraction::Fraction(int a, int b)
{
	if(b == 0)
		throw invalid_argument("zero denominator");
	this->num = a;
	this->den = b;
	this->reduce_fraction(&num, &den);
	this->changeNegative();
}

Fraction::Fraction(void)
{
	this->num = 1;
	this->den = 1;
}
int Fraction::getNum(void) const
{
	return this->num;
}

int Fraction::getDen(void) const
{
	return this->den;
}

int Fraction::find_gcd(int n1, int n2)
{
	int gcd, remainder;

	/* Euclid's algorithm */
	remainder = n1 % n2; 
	while ( remainder != 0 )
	{
	    n1 = n2;
	    n2 = remainder; 
		remainder = n1 % n2; 
	} 
	gcd = n2; 

	return gcd;
}

void Fraction::reduce_fraction(int* nump, int* denomp)
{
	int gcd;   
	gcd = find_gcd(*nump, *denomp);
	*nump = *nump / gcd;
	*denomp = *denomp / gcd;
}

void Fraction::changeNegative(void)
{
	if(this->den < 0)
	{
		den *= -1;
		num *= -1;
	}
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	if(f.den == 1)
	{
		os << f.num;
		return os;
	}
	os << f.num << "/" << f.den;
	return os;
}

istream& operator>>(istream& is, Fraction& f)
{
	char slash;
	is >> f.num >> slash >> f.den;
	if(f.den == 0)
		throw invalid_argument("zero denominator");
	f.reduce_fraction(&f.num, &f.den);
	return is;
}

const Fraction operator+(Fraction& f1, Fraction& f2)
{
	int temp1 = f1.den;
	int temp2 = f2.den;
	f1.den *= f2.den;
	f1.num *= f2.den;
	f2.den *= temp1;
	f2.num *= temp1;
	int newNum = f1.num + f2.num;
	int newDen = f2.den;
	f1.den /= temp2;
	f1.num /= temp2;
	f2.den /= temp1;
	f2.num /= temp1;
	return Fraction(newNum, newDen);
	
}

const Fraction operator-(Fraction& f1, Fraction& f2)
{
	int temp1 = f1.den;
	int temp2 = f2.den;
	f1.den *= f2.den;
	f1.num *= f2.den;
	f2.den *= temp1;
	f2.num *= temp1;
	int newNum = f1.num - f2.num;
	int newDen = f2.den;
	f1.den /= temp2;
	f1.num /= temp2;
	f2.den /= temp1;
	f2.num /= temp1;
	return Fraction(newNum, newDen);
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	if(&rhs == this)
		return *this;
	this->num = rhs.num;
	this->den = rhs.den;
	return *this;
}


