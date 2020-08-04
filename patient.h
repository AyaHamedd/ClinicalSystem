#ifndef PATIENTCLASS
#define PATIENTCLASS
#include <iostream>
#include <string>
//#include <string.h>
#include "Case.h"
#include "Date.h"
using namespace std;
class Patient
{
private:
	string name;
	string address;
	Date birthD;
	string phone;
	Patient *nextpatient;
	int caseCounter;
public:
	Case medicalhistory[10];

	Patient(); //doaa
	virtual ~Patient(); //doaa
	Patient(string n, string a, Date d, string ph);
	Patient(string n, string a, Date d, string ph, Patient* NE);
	Patient* getNext();
	void setNext(Patient *p);
	void setPatientName(string n);
	void setAddress(string add);
	void setBirthDate(Date d);
	void setPhone(string ph);
	void setCaseCount ( int s);
	void addCase(Case c);
	string getName();
	string getAddress();
	Date getBirthDate();
	string getPhone();
	Case* getMedicalHistory();
	void displayInfo();
	int getCaseNumber ();
};
#endif