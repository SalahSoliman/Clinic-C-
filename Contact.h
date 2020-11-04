#pragma once
#include <iostream>
#include <string>

using namespace std;

class Contact
{
private:
	string mobile;
	string tel;
	string Email;

public:
//Constructor...
	Contact();
	Contact(string mobile, string tel, string Email);

//Functions...
	void setMobile(string mobile);
	void setTel(string tel);
	void setEmail(string Email);
	void setContact(string mobile, string tel, string Email);

	string getMobile();
	string getTel();
	string getEmail();
	

//istream &ostream...

	friend istream& operator >> (istream& is, Contact& C);
	friend ostream& operator << (ostream& os, Contact& C);

//Destructors...
	~Contact();
};

