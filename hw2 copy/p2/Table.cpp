#include "Table.h"


Table::Table(int n): maxGuests(n) { numGuests = 0; }

int Table::maxOccupancy(void)
{
	return maxGuests;
}

int Table::currentOccupancy(void)
{
	return numGuests;
}

bool Table::addGuests(int n)
{
	if(numGuests + n <= maxGuests)
	{
	    numGuests += n;
	    return true;
	}else{
		return false;
	}
}
