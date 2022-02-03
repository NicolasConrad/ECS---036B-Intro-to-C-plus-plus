#include <string>
using namespace std;

class SiteNumber
{
	public:
		SiteNumber(string num) : site_number(num) {}
		bool operator()(Runway* r1){ return site_number.compare(r1->site_number()) == 0; }
	private:
		const string site_number;
};