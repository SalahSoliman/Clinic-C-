#pragma once
#ifndef PATIENT
#define PATIENT
#include <string>
#include "Date.h"
#include "Contact.h"
#include"MedicalHistory.h"
using namespace std;

class Patient
{
private:
	string name;
	string address;
	Date DofB;
	Contact C;
	Patient *next;
	MedicalHistory* firstMedicalHistory;
	int MedicalHistoryNum;

	//medHistory myHistory;

public:

//Constructors...
	Patient();
	Patient(string name, string address);
	Patient(string name,string address,string mobil, string tele, string email,unsigned int d,unsigned int m,unsigned int y);
// setters and getter for next
	inline void setNext(Patient* P){next= P;}
	inline Patient*  getNext(){return next;}

//Functions...
	void setName(string name);
	void setAddress(string Address);
	void setDate(unsigned int Day,unsigned int Month, unsigned int Year);
	void setContact(string mobile, string tel, string Email);
	void setDate(Date Date);
	void addMedicalHistory();
	void printMed();
	void SetFirstMH(MedicalHistory* MH);

	void SetPMN(int);
	int GetPMN();
	string getName();
	string getAddress();
	Date getDate();
	Contact getContact();
	MedicalHistory* getMH();

	~Patient();
//istream & ostream...

	friend istream& operator >> (istream& is, Patient& P1);
	friend ostream& operator << (ostream& os, Patient& P1);
	friend istream& operator>>(istream& is,Patient *P1);

	
};

#endif

