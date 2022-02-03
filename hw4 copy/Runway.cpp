#include<string>
#include "Runway.h"

Runway::Runway(std::string s) : site_number_(s.substr(0, 10)), name_(s.substr(13, 7)), length_(stoi(s.substr(20, 5))){}

int Runway::convert_length(std::string s) const
{
	int length = stoi(s);
	return length;
}

std::string Runway::site_number(void) const { return site_number_; }

std::string Runway::name(void) const { return name_; }

int Runway::length(void) const { return length_; }



