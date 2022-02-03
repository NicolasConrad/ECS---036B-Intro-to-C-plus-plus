#include "gcdistance.h"

class Closer
{
	public:
		Closer(double lat, double lon) : latitude(lat), longitude(lon) {}
		bool operator()(Facility* f1, Facility* f2)
		{
			return gcdistance(f1->latitude(), f1->longitude(), latitude, longitude) < gcdistance(f2->latitude(), f2->longitude(), latitude, longitude);
		}
	private:
		const double latitude;
		const double longitude;
};