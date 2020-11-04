#include "MedicalHistory.h"

PrescribedMedicines* MedicalHistory::getFirstMed()
{
	return firstMed;
}
MedicalHistory::MedicalHistory()
{
	setDiagnosis("");
	DoD.setDate(1, 1, 2000);
	nextMedical = NULL;
	firstMed = NULL;
	PrescribedMedNum = 0;
}
void MedicalHistory::setDiagnosis(string diagnosis)
{
	this->diagnosis = diagnosis;
}

string MedicalHistory::getDiagnosis()
{
	return diagnosis;
}
void MedicalHistory::setDateofDiagnosis(unsigned int d, unsigned int m, unsigned int y)
{
	//cout << "Date of Diagnosis: " << endl;
	DoD.setDate(d, m, y);
}
Date MedicalHistory::getDateofDiagnosis()
{
	return DoD;
}
void MedicalHistory::setNextMedical(MedicalHistory *MH)
{
	nextMedical = MH;
}
MedicalHistory* MedicalHistory::getNextMedical()
{
	return nextMedical;
}
void MedicalHistory::setFirstMedicine(PrescribedMedicines*FM)
{
	firstMed = FM;
}
PrescribedMedicines* MedicalHistory::getNextPrescribedMed()
{
	return firstMed;
}

void MedicalHistory::addMedicine()
{
	char c = 'y';
	do{

	PrescribedMedNum++;
	cout << "Medicines num: " << PrescribedMedNum<<") ";
	PrescribedMedicines *M = new PrescribedMedicines;
	PrescribedMedicines *currM = firstMed;
		if (firstMed == NULL)
		{
			firstMed = M;
			cin >> firstMed;
		}
		else
		{
			while (currM->getNextMedicine() != NULL)
			{
				currM = currM->getNextMedicine();
			}
			cin >> M;
			currM->setNextMedicine(M);

		}
		cout << "Do you want to add medcine(y/n)?" << endl;
		cin >> c;
		cin.ignore();
		while (c != 'y' && c != 'n') {
			cout << "Please enter a valid choice" << endl;
			cin >> c;
			cin.ignore();
		}
	} while (c == 'y');

}

int MedicalHistory::getMedicinesNUmber()
{
	return PrescribedMedNum;
}
void MedicalHistory::setMedicineNumber(int i)
{
	if (i < 0)cout << "No. of Medcines can't be negative" << endl;
	PrescribedMedNum = i;
}


istream& operator >> (istream &is, MedicalHistory *MH)
{
	char d[255];
	cout << "Diagnosis: ";
	cin.getline(d,255);
	MH->setDiagnosis(d);
	cout << "Date of Diagnosis: "<<endl;
	cin >> MH->DoD;
	cin.ignore();
	MH->addMedicine();
	return is;
}
ostream& operator << (ostream &os, MedicalHistory &MH)
{
	cout << "Diagnosis: " << MH.getDiagnosis() << endl;
	cout << "Date of Diagnosis: " << MH.DoD << endl;
	PrescribedMedicines *currMed = MH.getFirstMed();
	int j = 0;
	cout << "medicines : " << endl;
	while (MH.PrescribedMedNum - j !=0)
	{
		cout << j << ") " << currMed->getMedicine() << endl;
		
		currMed = currMed->getNextMedicine();
		j++;
	}
	return os;
}

ostream& operator << (ostream &os, MedicalHistory *MH)
{
	cout << "Medical History due to: ";
	cout <<MH->DoD << endl;
	cout << "Diagnosis: " << MH->getDiagnosis() << endl;
	PrescribedMedicines *currMed = MH->getFirstMed();
	int j = 0;
	cout << "medicines: " << endl;
	while (MH->PrescribedMedNum - j != 0)
	{
		cout << j+1 << ") " << currMed->getMedicine() << endl;

		currMed = currMed->getNextMedicine();
		j++;
	}
	return os;
}
MedicalHistory::~MedicalHistory()
{
	PrescribedMedicines *curr=firstMed;
	while (firstMed != NULL)
	{
		curr = firstMed->getNextMedicine();
		delete firstMed;
		firstMed = curr;
	}
	//cout << firstMed->getMedicine();
	PrescribedMedNum = 0;
}