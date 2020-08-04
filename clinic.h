#ifndef CLINICCLASS
#define CLINICCLASS
#include "Patient.h"
#include "Date.h"
#include "Case.h"
#include <iostream>
#include <string>
using namespace std;

class Clinic
{
private:
	Patient *first_patient;
	int patientsNumber;
public:
	Clinic();
	void deleteLast();
	int getPatientsNumber();
	void addPatient(Patient *toAdd);
	void deletePatient(Patient* p);
	Patient* searchPatient(string n);
	void showPatients();
	Patient& operator[] ( int i);
	friend void writeToFile(string filename ,Clinic c );
	friend void readFromFile(string filename , Clinic *c );

};
#endif