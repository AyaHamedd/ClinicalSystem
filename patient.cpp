#include "Patient.h"
#include "Date.h"
#include "Case.h"
#include <iostream>
#include <string>
using namespace std;

Patient::Patient()
{
	nextpatient = NULL;
	name = " ";
	address = " ";
	//birthD =NULL; 
	phone = " ";
	caseCounter = 0;
}
Patient::~Patient()
{

}
Patient::Patient(string n, string a, Date d, string ph)
{
	nextpatient = NULL;
	name = n;
	address = a;
	birthD = d;
	phone = ph;
	caseCounter = 0;

}

Patient::Patient(string n, string a, Date d, string ph, Patient*NE)
{
	nextpatient = NE;
	name = n;
	address = a;
	birthD = d;
	phone = ph;
	caseCounter = 0;

}
Patient* Patient::getNext()
{
	return nextpatient;
}
void Patient::setNext(Patient *p)
{
	nextpatient = p;
}
void Patient::setPatientName(string n)
{
	name = n;
}
void Patient::setAddress(string add)
{
	address = add;
}
void Patient::setBirthDate(Date d)
{
	birthD = d;
}
void Patient::setPhone(string ph)
{
	phone = ph;
}
void Patient::addCase(Case c)
{
	medicalhistory[caseCounter] = c;
	caseCounter++;
}
string Patient::getName()
{
	return name;
}
string Patient::getAddress()
{
	return address;
}
Date Patient::getBirthDate()
{
	return birthD;
}
string Patient::getPhone()
{
	return phone;
}
Case* Patient::getMedicalHistory()
{
	return medicalhistory;
}
void Patient::displayInfo()
{
	cout << name << endl;
	cout << birthD.getDay() << "/" << birthD.getMonth() << "/" << birthD.getYear() << endl;
	cout << address << endl;
	for (int i = 0; i < caseCounter; i++)
	{
		medicalhistory[i].displayCase();
	}


}

int Patient :: getCaseNumber ()
{
	return caseCounter;
}

void Patient :: setCaseCount (int s)
{
	caseCounter = s;
}