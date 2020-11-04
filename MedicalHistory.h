#pragma once
#ifndef MEDICALHISTORY
#define MEDICALHISTORY
#include"Date.h"
#include<string>
#include"PrescribedMedicines.h"
using namespace std;
class MedicalHistory
{
private :
	string diagnosis;
	Date DoD;
	MedicalHistory* nextMedical;
	PrescribedMedicines* firstMed;
	int PrescribedMedNum;
	
public:

	MedicalHistory();

	PrescribedMedicines* getFirstMed();
	void setDiagnosis(string diagnosis);
	string getDiagnosis();
	void setDateofDiagnosis(unsigned int d, unsigned int m, unsigned int y);
	Date getDateofDiagnosis();
	void setNextMedical(MedicalHistory *MH);
	MedicalHistory* getNextMedical();
	void setFirstMedicine(PrescribedMedicines*FM);
	PrescribedMedicines*getNextPrescribedMed();
	int getMedicinesNUmber();
	void setMedicineNumber(int i);
	~MedicalHistory();

	void addMedicine();

	friend istream& operator >> (istream &is, MedicalHistory *MH);
	friend ostream& operator << (ostream &os, MedicalHistory &MH);
	friend ostream& operator << (ostream &os, MedicalHistory *MH);
	
};
#endif

