#pragma once
#ifndef PRESCRIBEDMEDICINES
#define PRESCRIBEDMEDICINES
#include <iostream>
#include<string>
using namespace std;

class PrescribedMedicines
{
private:
	string Medicine;
	PrescribedMedicines* nextMedicine;
	
public:
	PrescribedMedicines();

	void setMedicine(string med);
	string getMedicine();
	void setNextMedicine(PrescribedMedicines *MED);
	PrescribedMedicines* getNextMedicine();

	friend istream& operator >> (istream &is, PrescribedMedicines *PM);
	friend ostream& operator << (ostream &is, PrescribedMedicines &PM);

};
#endif

