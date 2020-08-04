#include "Patient.h"
#include "Case.h"
#include <string>
#include "Clinic.h"
#include "Date.h"
#include <iostream>
using namespace std;

Case::Case()
{
	diagnosis = "";
	cd.setDay(0);
	cd.setMonth(0);
	cd.setYear(0);
	medication = "";
}
Case::Case(string d, Date dd, string m)
{
	diagnosis = d;
	cd = dd;
	medication = m;
}
void Case::setMedication(string med)
{
	medication = med;
}
void Case::setCaseDate(Date CD)
{
	cd = CD;
}
void Case::setDiag(string diag)
{
	diagnosis = diag;
}
string Case::getMedication()
{
	return medication;
}
Date Case::getDate()
{
	return cd;
}
string Case::getDiagnosis()
{
	return diagnosis;
}
void Case::displayCase()
{
	cout << "Diagnose:" << diagnosis << endl;
	cout << "Case date:" << cd.getDay() << "/" << cd.getMonth() << "/" << cd.getYear() << endl;
	cout << "Medication:" << medication << endl;
}