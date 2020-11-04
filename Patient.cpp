#include"Patient.h"

using namespace std;
//Constructors...
Patient::Patient()
{
	setName("");
	setAddress("");
	next =NULL;
	firstMedicalHistory=NULL;
	MedicalHistoryNum=0;
	
}

void Patient::SetPMN(int i)
{
	if (i < 0)cout << "Error!Please enter a valid Number of Medical History." << endl;
	else
		MedicalHistoryNum = i;

}
int Patient::GetPMN()
{
	return MedicalHistoryNum;
}
Patient::Patient(string name, string address)
{
	setName(name);
	setAddress(address);
	next=NULL;
	firstMedicalHistory=NULL;
	MedicalHistoryNum=0;
}
Patient::Patient(string name,string address,string mobil, string tele, string email,unsigned int d,unsigned int m,unsigned int y)
{
	setName(name);
	setAddress(address);
	setContact(mobil,tele,email);
	setDate(d,m,y);
	next=NULL;
	firstMedicalHistory=NULL;
	MedicalHistoryNum=0;
}
//Set Functions...
void Patient::setName(string name)
{
	this-> name = name;
}

void Patient::setAddress(string address)
{
	this-> address = address;
}

void Patient::setDate(unsigned int Day,unsigned int Month,unsigned int Year)
{
	cout << "Date of Birth:" << endl;
	this-> DofB.setDay(Day);
	this-> DofB.setMonth(Month);
	this->DofB.setYear(Year);
}

void Patient::setContact(string mobile ,string tel, string Email)
{
	this-> C.setMobile(mobile);
	this-> C.setTel(tel);
	this->C.setEmail(Email);

}
void Patient::setDate(Date Date)
{
	//cout << "Date of Birth:" << endl;
	this-> DofB.setDay(Date.getDay());
	this-> DofB.setMonth(Date.getMonth());
	this-> DofB.setYear(Date.getYear());
}


//Get Functions...
string Patient::getName()
{
	return name;
}
string Patient::getAddress()
{
	return address;
}
Date Patient::getDate()
{
	return DofB;
}
Contact Patient::getContact()
{
	return C;
}
MedicalHistory* Patient::getMH()
{
	return firstMedicalHistory;
}


//ostream & istream...
istream& operator >> (istream& is, Patient& P1)
{
	
	char n[255] ;
	cout << "Name: ";
	cin.getline(n, 255);
	P1.name = n;
	cout << "Address: ";
	cin.getline(n, 255);
	P1.address = n;
	is >> P1.DofB;
	is >> P1.C;
	return is;
}

ostream& operator << (ostream& os, Patient& P1)
{
	
	os << "Name: " << P1.name << endl;
	os << "Address: " << P1.address << endl;
	cout << "Date of Birth:" << endl;
	os << P1.DofB << endl;
	os << P1.C << endl;
	os << P1.firstMedicalHistory << endl;
	return os;
}
istream& operator>>(istream& is,Patient *P1)
{
	
	char n[255] ;
	cout << "Name: ";
	cin.getline(n, 255);
	P1->setName(n);
	cout << "Address: ";
	cin.getline(n, 255);
	P1->setAddress(n);
	cout << "Date of Birth:" << endl;
	is >> P1->DofB;
	is >> P1->C;
	cout << "___________________________________________________________" << endl;
	cin.ignore();

	return is;
}

void Patient::addMedicalHistory()
{
	MedicalHistoryNum++;
	MedicalHistory *currMedical = firstMedicalHistory;
	MedicalHistory *MedH = new MedicalHistory;
	if (firstMedicalHistory == NULL)
	{ 

		firstMedicalHistory = MedH;
		cin >> firstMedicalHistory;
	}
	else
	{
			char c = 'y';
			while (currMedical->getNextMedical() != NULL)
			{
				currMedical = currMedical->getNextMedical();
			}
			currMedical->setNextMedical(MedH);
			cin >> MedH;
		}

}

void Patient::printMed()
{
	if(MedicalHistoryNum==0)
	{
		cout << "No medical History for this Patient..." << endl;
		return;
	}
	MedicalHistory *currMed = firstMedicalHistory;

	int i=0;
	while (MedicalHistoryNum - i != 0)
		{

		cout << currMed << endl;

		currMed=currMed->getNextMedical();
		cout << "****************************************" << endl;
		i++;
		}
}

void Patient::SetFirstMH(MedicalHistory* MH)
{
	firstMedicalHistory = MH;
}

////Destructors...
Patient::~Patient()
{
	MedicalHistory* M = firstMedicalHistory;
	while (firstMedicalHistory != NULL)
	{
		M = M->getNextMedical();
		delete firstMedicalHistory;
		firstMedicalHistory = M;
	}
	MedicalHistoryNum = 0;
}	

