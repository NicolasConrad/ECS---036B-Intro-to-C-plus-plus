#include<iostream>
using namespace std;

int main()
{
	char c;
	int x;
	int y;
	int width;
	int height;
	int radius;

	cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
	cout << "<svg width=\"700\" height=\"600\"" << endl << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
	cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;

	cin >> c;
	while(cin)
	{
		if(c == 'R')
		{
			cin >> x >> y >> width >> height;
			cout << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
		}
		else if(c == 'C')
		{
			cin >> x >> y >> radius;
			cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << radius << "\"/>" << endl;
		}
		cin >> c;
	}
	
	cout << "</g>" << endl;
	cout << "</svg>" << endl;
}