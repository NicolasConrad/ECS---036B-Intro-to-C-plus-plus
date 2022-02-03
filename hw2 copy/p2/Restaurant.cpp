#include "Restaurant.h"
#include<iostream>
#include<stdexcept>
using namespace std;


Restaurant::Restaurant(int nLarge, int nMedium, int nSmall): size(nLarge+nMedium+nSmall)
{
	tableList = new Table*[6];
	for(int i = 0; i < nLarge; ++i)
	{
		tableList[i] = new Table(10);
		cout << "Table " << i+1 << " maximum occupancy 10" << endl;
	}

	for(int i = nLarge; i < nLarge + nMedium; ++i)
	{
		tableList[i] = new Table(7);
		cout << "Table " << i+1 << " maximum occupancy 7" << endl;
	}

	for(int i = nLarge + nMedium; i < nLarge + nMedium + nSmall; ++i)
	{
		tableList[i] = new Table(5);
		cout << "Table " << i+1 << " maximum occupancy 5" << endl;
	}
}

void Restaurant::addGuests(int nGuests)
{
	if(nGuests <= 0)
		throw invalid_argument("must be positive");
	for(int i = 0; i < size; ++i)
	{
		if(tableList[i]->addGuests(nGuests))
		{
			cout << nGuests << " guests added to table " << i+1 << endl;
			break;
		}
		if(i == size-1)
			cout << " could not accommodate " << nGuests << " guests" << endl;
	}
}

void Restaurant::printSummary(void)
{
	cout << "Summary:" << endl;
	for(int i = 0; i < size; ++i)
	{
		if(tableList[i]->currentOccupancy() != 0)
			cout << "table " << i+1 << " " << tableList[i]->currentOccupancy() << "/" << tableList[i]->maxOccupancy() << endl;
	}
}
