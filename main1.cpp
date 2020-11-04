#include <iostream>
#include "Patient.h"
#include "Date.h"
#include "Contact.h"
#include"Clinic.h"
#include <string>
#include"MedicalHistory.h"
#include <fstream>

using namespace std;

void HomeScreen()
{
	cout << endl << endl;
	cout << "Welcome To Dr Strange Clinic..." << endl;
	cout << "Press: " << endl;
	cout << "      '1' to add a Patient." << endl;
	cout << "      '2' to Remove a Patient." << endl;
	cout << "      '3' to Search for a Patient's Data." << endl;
	cout << "      '4' to Print all Patients Data." << endl;
	cout << "      '5' to Exit." << endl;
}


int  main()
{
	cout << "......                        .........   ..........   .....               .           ...      ..        .....     .........." << endl;
	cout << "..     ..                    ..               ..       ..    ..           ...          ....     ..      ..     ..   .." << endl;
	cout << "..      ..                   ..               ..       ..     ..         .....         .. ..    ..     ..      ..   .." << endl;
	cout << "..       ..                  ..               ..       ..     ..        .......        ..  ..   ..    ..            .." << endl;
	cout << "..       ..     ..   ...      ........        ..       ..    ..        .........       ..   ..  ..    ..            ......." << endl;
	cout << "..       ..     ..  ...              ..       ..       ..  ..         ...........      ..    .. ..    ..      ....  .." << endl;
	cout << "..      ..      .. ..                ..       ..       ..  ..        ..         ..     ..     ....     ..      ..   ..       .." << endl;
	cout << "..     ..       ...      ..          ..       ..       ..   ..      ..           ..    ..      ...      ..    ..    ..        ." << endl;
	cout << "......          ..       ..   ........        ..       ..    ..    ..             ..   ..       ..        .....     ..........." << endl;
	
	int x;

	Clinic DrStrange;
	DrStrange.ReadFile("Test.txt");
	do
	{
		HomeScreen();

		cout << "Your Choice: ";
		cin >> x;
		cin.ignore();
		cout << "*********************************************************************" << endl;

		if (x == 1)
		{
			DrStrange.addPatient();
		}
		else if (x == 2)
		{
			int y;
			cout << "Press:" << endl;
			cout << "      '1' to remove by name..." << endl;
			cout << "      '2' to remove by order..." << endl;
			cout << "Your Choice: ";
			cin >> y;
			cin.ignore();

			if (y == 1)
			{
				string name;
				cout << "Name: ";
				getline(cin, name);

				DrStrange.removePatient(name);
			}
			else if (y == 2)
			{
				int P_num;
				cout << "Patient Num: ";
				cin >> P_num;

				DrStrange.removePatient(P_num);
			}

		}
		else if (x == 3)
		{
			string name;

			if (DrStrange.getPatientsNum() == 0)
			{
				cout << "There is no Patients in The List..." << endl;
			}
			else
			{
				cout << "Name: ";
				getline(cin, name);

				DrStrange.searchPatient(name);
			}
		}

		else if (x == 4)
		{
			DrStrange.printPatients();
		}

	} while (x != 5);
	DrStrange.WriteFile("Test.txt");
	return 0;

}
