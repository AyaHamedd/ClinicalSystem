#include "Date.h"
#include "Patient.h"
#include"Clinic.h"
#include "Case.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	Clinic clinic;
	readFromFile("Text.txt" , &clinic );
	clinic.deleteLast();
	char choice1;
	char choice;
	cout << "(a) for adding new patient, (b) for searching for a patient, (d) to show list of patients, (c) to exit" << endl;
	cin >> choice;
	while (choice != 'c')
	{
		Patient *patient= new Patient;
		string name;
		string address;
		Date date;
		int day;
		int month;
		int year;
		string number;
		string nsearch;
		Patient* requiredPatient;
		switch (choice)
		{
		case'b':
			cout << "enter patient's name" << endl;
			cin >> nsearch;
			requiredPatient = clinic.searchPatient(nsearch);
			if (requiredPatient != NULL)
			{
				requiredPatient->displayInfo(); //mariam hayyyeeellll
				cout << "enter (u) to update, (d) to delete, (c) to add case, (n) to exit" << endl;
				cin >> choice1;
				if (choice1 == 'u')
				{
					cout << "Enter Patient's name:" << endl;
					cin >> name;
					requiredPatient->setPatientName(name);
					cout << "Enter Patient's Address:" << endl;
					cin >> address;
					requiredPatient->setAddress(address);
					cout << "Enter Patient's birthdate day/month/year respectively:" << endl;
					cin >> day >> month >> year;
					date.setDay(day);
					date.setMonth(month);
					date.setYear(year);
					requiredPatient->setBirthDate(date);
					cout << "Enter Phone number:" << endl;
					cin >> number;
					requiredPatient->setPhone(number);
				}
				if (choice1 == 'd')
				{
					clinic.deletePatient(requiredPatient);
					cout << "deleted" << endl;
				}
				if (choice1 == 'c')
				{
					string diag, med;
					int d, m, y;
					cout << "enter diagnosis" << endl;
					cin >> diag;
					cout << "enter date day/month/year" << endl;
					cin >> d >> m >> y;
					Date date(d, m, y);
					cout << "enter medication" << endl;
					cin >> med;
					Case thecase(diag, date, med);
					requiredPatient->addCase(thecase);
				}
			}
			break;
		case'a':
			cout << "Enter Patient's name:" << endl;
			cin >> name;
			patient->setPatientName(name);
			cout << "Enter Patient's Address:" << endl;
			cin >> address;
			patient->setAddress(address);
			cout << "Enter Patient's birthdate day/month/year respectively:" << endl;
			cin >> day >> month >> year;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			patient->setBirthDate(date);
			cout << "Enter Phone number:" << endl;
			cin >> number;
			patient->setPhone(number);
			clinic.addPatient(patient);
			break;
		case 'd':
			clinic.showPatients();
			break;

		}
		cout<< "(a) for adding new patient, (b) for searching for a patient, (d) to show list of patients, (c) to exit" << endl;
		cin >> choice;
	}
	writeToFile("Text.txt", clinic);
}