#include "Domain.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

Domain::Domain(void)
{
	sizex = 600;
	sizey = 500;
}

Domain::~Domain(void)
{
	vector<const Shape*>:: iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++)
		delete *iter;
}

void Domain::addShape(const Shape* p)
{
	s.push_back(p);
}

void Domain::draw(void)
{
	Rectangle domain = Rectangle(Point(0,0), 600, 500);
	vector<const Shape*>::iterator iter;
	vector<const Shape*>::iterator iter2;
	string diagnostic = "ok";

	cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
	cout << "<svg width=\"700\" height=\"600\"" << endl << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
	cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;

	for(iter = s.begin(); iter != s.end(); iter++)
	{
		(*iter)->draw();
		if(!(*iter)->fits_in(domain))
			diagnostic = "does not fit";
	}

	if(diagnostic == "ok")
	{
		for(iter = s.begin(); iter != s.end()-1; iter++)
		{
			for(iter2 = iter+1; iter2 != s.end(); iter2++)
			{
				if((*iter)->overlaps(**iter2))
					diagnostic = "overlap";
			}
		}
	}

	cout << "</g>" << endl;
	cout << "<g transform=\"matrix(1,0,0,1,50,590)\"" << endl << " font-family=\"Arial\" font-size=\"32\">" << endl;
	cout << "<text x=\"0\" y=\"0\">" << diagnostic << "</text>" << endl;
	cout << "</g>" << endl;
	cout << "</svg>" << endl;
}