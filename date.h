#ifndef DATECLASS
#define DATECLASS
#include <string>
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();

};
#endif