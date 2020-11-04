#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{
	Day = 1;
	Month = 1;
	Year = 2000;
}
Date::Date(unsigned int Day, unsigned int Month, unsigned int Year)
{
	if (Day>0 && Day <= 31)
		this->Day = Day;
	else
	{
		cout << "Please Enter A valid Day" << endl;
		this->Day = 1;
	}
	if (Month>0 && Month <= 12)
		this->Month = Month;
	else
	{
		cout << "Please Enter A valid Month" << endl;
		this->Month = 1;
	}
	if (Year>1870)
		this->Year = Year;
	else
	{
		cout << "Please Enter A valid Year" << endl;
		this->Year = 1870;
	}

}
void Date::setDate(Date Date)
{
	Day = Date.getDay();
	Month = Date.getMonth();
	Year = Date.getYear();
}
void Date::setDate(unsigned int Day, unsigned int Month, unsigned int Year)
{
	if (Day>0 && Day <= 31)
		this->Day = Day;
	else
	{
		cout << "Please Enter A valid Day" << endl;
		this->Day = 1;
	}
	if (Month>0 && Month <= 12)
		this->Month = Month;
	else
	{
		cout << "Please Enter A valid Month" << endl;
		this->Month = 1;
	}
	if (Year>1870)
		this->Year = Year;
	else
	{
		cout << "Please Enter A valid Year" << endl;
		this->Year = 1870;
	}
}
void Date::setDay(unsigned int Day)
{
	if (Day>0 && Day <= 31)
		this->Day = Day;
	else
	{
		cout << "Please Enter A valid Day" << endl;
		this->Day = 1;
	}
}
void Date::setMonth(unsigned int Month)
{
	if (Month>0 && Month <= 12)
		this->Month = Month;
	else
	{
		cout << "Please Enter A valid Month" << endl;
		this->Month = 1;
	}
}
void Date::setYear(unsigned int Year)
{
	if (Year>1870)
		this->Year = Year;
	else
	{
		cout << "Please Enter A valid Year" << endl;
		this->Year = 1870;
	}
}

unsigned int Date::getDay()
{
	return Day;
}
unsigned int Date::getMonth()
{
	return Month;
}
unsigned int Date::getYear()
{
	return Year;
}

ostream& operator<<(ostream& os, Date& Date)
{
	os << Date.getDay() << "/" << Date.getMonth() << "/" << Date.getYear() << endl;
	return os;
}
istream& operator >> (istream& is, Date& Date1)
{
	Date temp;
	cout << "	Day: ";
	is >> temp.Day;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "You can only enter numbers..." << endl;
		cout << "	Day: ";
		is >> temp.Day;
	}
	cout << "	Month: ";
	is >> temp.Month;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "You can only enter numbers..." << endl;
		cout << "	Month: ";
		is >> temp.Month;
	}

	cout << "	Year: ";
	is>> temp.Year;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "You can only enter numbers..." << endl;
		cout << "	Year: ";
		is >> temp.Year;
	}

	if (temp.Day >= 1 && temp.Day <= 31)
		Date1.Day = temp.Day;
			
	else
	{
		while (temp.Day <0 || temp.Day >31)
		{
			cout << "Please enter a valid day" << endl;
			cout << "	Day: ";
			is >> temp.Day;
			Date1.setDay(temp.Day);
		}
	}
	if (temp.Month >= 1 && temp.Month <= 12)
		Date1.Month = temp.Month;
			
	else
	{
		while (temp.Month <0 || temp.Month >12)
		{
			cout << "Please enter a valid Month" << endl;
			cout << "	Month: ";
			is >> temp.Month;
			Date1.setMonth(temp.Month);
		}
	}
	if (temp.Year >1870 && temp.Year <= 2017)
		Date1.Year = temp.Year;
	else
	{
		while (temp.Year < 1870|| temp.Year > 2017)
		{
			cout << "Please enter a valid Year" << endl;
			cout << "	Year: ";
			is >> temp.Year;
			Date1.setYear(temp.Year);
		}
	}

	return is;
}
istream& operator >> (istream& is, Date* Date1)
{
	Date temp;
	cout << "	Day: ";
	is >> temp.Day;
	cout << "	Month: ";
	is >> temp.Month;
	cout << "	Year: ";
	is>> temp.Year;

	if (temp.Day >= 1 && temp.Day <= 31)
		Date1->setDay(temp.Day);
			
	else
	{
		while (temp.Day <0 || temp.Day >31)
		{
			cout << "Please enter a valid day" << endl;
			cout << "	Day: ";
			is >> temp.Day;
			Date1->setDay(temp.Day);
		}
	}
	if (temp.Month >= 1 && temp.Month <= 12)
		Date1->setMonth(temp.Month);
			
	else
	{

		while (temp.Month <0 || temp.Month >12)
		{
			cout << "Please enter a valid Month" << endl;

			cout << "	Month: ";
			is >> temp.Month;
			Date1->setMonth(temp.Month);
		}
	}
	if (temp.Year >1870 && temp.Year <= 2017)
		Date1->setYear(temp.Year);
	else
	{
		while (temp.Year < 1870|| temp.Year > 2017)
		{
			cout << "Please enter a valid Year" << endl;
			cout << "	Year: ";
			is >> temp.Year;
			Date1->setYear(temp.Year);
		}
	}

	return is;
}

