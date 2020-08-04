#include "Patient.h"
#include "Date.h"
#include "Case.h"
#include <string>
#include "Clinic.h"
#include <iostream>
#include <fstream>
using namespace std;

Clinic::Clinic()
{
	first_patient = NULL;
	patientsNumber = 0;
}
int Clinic::getPatientsNumber()
{
	return patientsNumber;
}
void Clinic::addPatient(Patient *toAdd)
{
	Patient* current;
	current = first_patient;
	if (patientsNumber == 0)
	{
		/*Patien = new Patient(toAdd.getName(), toAdd.getAddress(), toAdd.getBirthDate(), toAdd.getPhone(),NULL);*/
		first_patient = toAdd;
		patientsNumber++;
	}
	else
	{
		while (current->getNext() != NULL)
		{
			current = current->getNext();
		}
		/*current->setNext(new Patient(toAdd.getName(), toAdd.getAddress(), toAdd.getBirthDate(), toAdd.getPhone(), NULL));*/
		current->setNext(toAdd);
		patientsNumber++;
	}
}
void Clinic::deletePatient(Patient* P)
{

	Patient*current = first_patient;
	if (P == first_patient)
	{
		first_patient = current->getNext();
		patientsNumber--;
		delete current;
	}
	else
	{
		while ((current->getNext()) != P)
		{
			current = current->getNext();
		}
		
		current->setNext(P->getNext());
		patientsNumber--;
		delete P;
	}
}
	
Patient* Clinic::searchPatient(string n)
{
	Patient *current;
	current = first_patient;

	while (current != NULL)
	{
		if ((current->getName()) == n)
		{
			return current;
		}
		current = current->getNext();
	}
	cout << "not found" << endl;
	Patient* walahaga = NULL;
	return walahaga;
}

void writeToFile(string filename , Clinic c)
{
	ofstream myfile(filename, ios::out);
	if (!myfile)
		cout << "error";
	else
	{
		for ( int i=0; i<c.getPatientsNumber() ; i++)
		{
			Date dat;
			myfile<<"Name: "<<c[i].getName()<<" Address: "<<c[i].getAddress()<<" D.O.F.: ";
			dat=c[i].getBirthDate(); 
			myfile<<dat.getDay()<<" "<<dat.getMonth()<<" "<<dat.getYear();
			myfile<<" Phone: "<<c[i].getPhone()<<" MedicalHistoryNo "<<c[i].getCaseNumber()<<" ";
			for ( int j=0; j<c[i].getCaseNumber() ; j++)
			{
				dat=c[i].medicalhistory[j].getDate();
				myfile<<dat.getDay()<<" "<<dat.getMonth()<<" "<<dat.getYear()<<" ";
				myfile<<c[i].medicalhistory[j].getDiagnosis()<<" "<<c[i].medicalhistory[j].getMedication()<<" ";
			}
			myfile<<endl;
		}
		myfile.close();
	}
}
void readFromFile(string filename , Clinic *c)
{
	ifstream myfile(filename);
	//Patient* current;
	//current = c->first_patient;
	int patientcounter=0;
	int casecount;
	string wanted , no;
	int d , m, y;

	if (!myfile)
		cout << "error";
	else
	{
		while (!myfile.eof())
		{
			Patient *n = new Patient ;
			myfile>>no>>wanted>>no;
			n->setPatientName(wanted);
			myfile>>wanted>>no;
			n->setAddress(wanted);
			myfile>>d>>m>>y>>no;
			Date dat(d,m,y);
			n->setBirthDate(dat);
			myfile>>wanted>>no;
			n->setPhone(wanted);
			myfile>>casecount;
			n->setCaseCount(casecount);
			for ( int b=0; b<casecount ; b++)
			{
				myfile>>d>>m>>y;
				Date dat(d,m,y);
				n->medicalhistory[b].setCaseDate(dat);
				myfile>>wanted;
				n->medicalhistory[b].setDiag (wanted);
				myfile>>wanted;
				n->medicalhistory[b].setMedication(wanted);
			}
			n->setNext(NULL);
			c->addPatient(n);
			/*if ( current == NULL)
			{
				current=n;
				patientcounter++;
			}
			else
			{
				while ( current -> getNext() != NULL )
				{
					current=current->getNext();
				}
				current = n;
				patientcounter++;
			}*/
		}

	}
	myfile.close();
}


void Clinic::showPatients()
	{
		Patient* current;
		current = first_patient;
		Patient *temp = current;
		while(current !=NULL)
		{

			cout<<current->getName()<<endl;
			current = current -> getNext();
		}
	}
Patient& Clinic :: operator[] ( int i)
	{
		Patient *head;
		Patient *current;
		head=first_patient;
		current=head;
		int x=0;
		while ( current->getNext() != NULL && x<i)
		{
			current = current->getNext();
			x++;
		}
		return *current;
	}

void Clinic :: deleteLast ()
{
	Patient *current;
	current= first_patient;
	while ( current->getNext()->getNext()!= NULL)
		current=current->getNext();
	current->setNext (NULL);
	patientsNumber--;
}