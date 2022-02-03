#include<string>
#include "gcdistance.h"
#include "Facility.h"

Facility::Facility(std::string s) : site_number_(s.substr(0,10)), type_(s.substr(11, 13)), code_(s.substr(24, 4)), name_(s.substr(130, 50)), latitude_(convert_latitude(s.substr(535, 12))), longitude_(convert_longitude(s.substr(562, 12))) {}

std::string Facility::site_number(void) const { return site_number_; }

std::string Facility::type(void) const { return type_; }

std::string Facility::code(void) const { return code_; }

std::string Facility::name(void) const { return name_; }

double Facility::latitude(void) const 
{ 
	return latitude_; 
}

double Facility::longitude(void) const 
{ 
	return longitude_; 
}

double Facility::convert_latitude(std::string s) const
{
	double degrees = stod(s)/3600;
	if(s.back() == 'S')
		return degrees * -1;
	return degrees;
}

double Facility::convert_longitude(std::string s) const
{	
	double degrees = stod(s)/3600;
	if(s.back() == 'W')
		return degrees * -1;
	return degrees;

}

double Facility::distance(double lat, double lon) const
{
	double distance = gcdistance(lat, lon, latitude_, longitude_);
	return distance;
}

