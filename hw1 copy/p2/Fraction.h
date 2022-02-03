#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;

class Fraction
{
	private:	
		int num;
		int den;
	public:
		Fraction(int a, int b);
		Fraction(void);
		int getNum(void) const;
		int getDen(void) const;
		int find_gcd(int n1, int n2);
		void reduce_fraction(int* nump, int* denomp);
		void changeNegative(void);
		friend ostream& operator<<(ostream& os, const Fraction& f);
		friend istream& operator>>(istream& is, Fraction& f);
		friend const Fraction operator+(Fraction& f1, Fraction& f2);
		friend const Fraction operator-(Fraction& f1, Fraction& f2);
		Fraction& operator=(const Fraction& rhs);
};
#endif

