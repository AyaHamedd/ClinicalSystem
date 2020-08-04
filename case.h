#ifndef CASECLASS
#define CASECLASS


#include <string>
#include <iostream>
#include "Date.h"

using namespace std;
class Case
{
private:
	string diagnosis;
	Date cd;
	string medication;
public:
	Case();
	Case(string d, Date dd, string m);
	void setMedication(string med);
	void setCaseDate(Date CD);
	void setDiag(string diag);
	string getMedication();
	Date getDate();
	string getDiagnosis();
	void displayCase();
};
#endif