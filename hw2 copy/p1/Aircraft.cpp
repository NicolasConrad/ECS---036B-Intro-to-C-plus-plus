#include<iostream>
#include"Aircraft.h"

Aircraft::Aircraft(int n, std::string name_str): numEng(n), nm(name_str)
{
	hrs = new int;
}

const std::string Aircraft::name(void)const
{
	return nm;
}

int Aircraft::numEngines(void)const
{
	return numEng;
}

void Aircraft::setHours(int i, int h)
{
	hrs[i-1] = h;
}

void Aircraft::print(void) const
{
	std::cout << "Aircraft: " << nm << " type: " << type() << " has " << numEng << " engines" << std::endl;

	for(int i = 0; i < numEng; ++i)
	    std::cout << "engine " << i+1 << ": " << hrs[i] << " hours" << std::endl;
}
   
void Aircraft::printSchedule(void) const
{
	std::cout<<"Maintenance schedule for " << nm << std::endl;
	
	for(int i = 0; i < numEng; ++i)
		if(maxHours() - hrs[i] > 0)
	    	std::cout << "engine " << i+1 << ": maintenance due in " << maxHours()-hrs[i] << " hours" << std::endl;
	    else
	    	std::cout << "engine " << i+1 << ": maintenance due now!!" << std::endl;
}

Aircraft::~Aircraft(void)
{
	delete hrs;
}

Aircraft* Aircraft::makeAircraft(char ch, std::string name_str)
{
	if(ch == 'A')
	{
		A380* a = new A380(name_str);
		return a;
	}else if(ch == 'B')
	{
		B737* b = new B737(name_str);
		return b;
	}else
		return 0;
}



A380::A380(std::string name_str): Aircraft(4, name_str){}

const std::string A380::type(void) const
{
	return "Airbus A380";
}
    
const int A380::maxHours(void) const
{
 return 750;
}

B737::B737(std::string name_str): Aircraft(2, name_str){}

const std::string B737::type(void) const
{
	return "Boeing B737";
}
    
const int B737::maxHours(void) const
{
 return 600;
}