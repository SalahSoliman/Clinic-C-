#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	Date();
	Date(unsigned int Day, unsigned int Month, unsigned int Year);
	void setDate(Date Date);
	void setDate(unsigned int Day, unsigned int Month, unsigned int Year);
	void setDay(unsigned int Day);
	void setMonth(unsigned int Month);
	void setYear(unsigned int Year);
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();
	friend ostream& operator<<(ostream &os, Date& Date);
	friend istream& operator >> (istream& is, Date& Date);
	friend istream& operator >> (istream& is, Date* Date1);
	
private:
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;

};

