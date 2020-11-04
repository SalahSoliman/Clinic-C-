#include <iostream>
#include "Contact.h"

using namespace std;

Contact::Contact()
{
	setMobile("");
	setTel("");
	setEmail("");
}

Contact::Contact(string mobile, string tel, string Email)
{
	setMobile(mobile);
	setTel(tel);
	setEmail(Email);
}
void Contact:: setContact(string mobile, string tel, string Email)
{
	this->mobile=mobile;
	this->tel =tel;
	this->Email=Email;
}
//Functions...
void Contact::setMobile(string mobile)
{
	this-> mobile =mobile;
}
void Contact::setTel(string tel)
{
	this->tel = tel;
}
void Contact::setEmail(string Email)
{
	this->Email = Email;
}

string Contact::getMobile()
{
	return mobile;
}
string Contact::getTel()
{
	return tel;
}
string Contact::getEmail()
{
	return Email;
}

//istream &ostream...

istream& operator >> (istream& is, Contact& C)
{
	cout << "Contacts:"<<endl;
	cout << "	Mobile: ";
	is >> C.mobile;
	cout << "	Tel: ";
	is >> C.tel;
	cout <<	"	Email: ";
	is >> C.Email;

	return is;
}

ostream& operator << (ostream& os, Contact& C)
{
	os << "Your Contacts: " << endl;
	os << "	Mobile: " << C.mobile << endl;
	os << "	Tel: " << C.tel << endl;
	os << "	Email: " << C.Email << endl;

		return os;
}

//Destructors...
Contact::~Contact()
{
}
