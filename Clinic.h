#pragma once
#include"Patient.h"
#include <fstream>

class Clinic
{
private:
	Patient *firstPatient;
	int PatientsNum;
	char username[255] = { '0' };
	char password[255]= { '0' };
public:

	Clinic();
	int getPatientsNum();
	bool passwordCheck();
	void setUserName(char un[255]);
	void setPassword(char pass[255]);
	void addPatient();
	void printPatients();
	void removePatient(string name);
	void removePatient(int i);
	Patient *searchPatient(string n);
	~Clinic();
//files...
	bool ReadFile(string F);
	bool WriteFile(string F);

	void deleteP();

};