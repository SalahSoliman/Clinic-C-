#include <iostream>
#include "Patient.h"
#include "Date.h"
#include "Contact.h"
#include"Clinic.h"
#include <string>

using namespace std;

int main()
{

	Clinic DrMohamed;
	Patient A("name","address","mobil","ph","em",12,12,1996);
	Patient B("ahmed","address","mobil","ph","em",12,12,1996);
	Patient C("abdallah","address","mobil","ph","em",12,12,1996);
	Patient *ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
	Patient D("rami","address","mobil","ph","em",12,12,1996);
	Patient E("salah","address","mobil","ph","em",12,12,1996);
	ptr1=&A;
	ptr2=&B;
	ptr3=&C;
	ptr4=&D;
	ptr5=&E;
	DrMohamed.addPatient(ptr1);
	DrMohamed.addPatient(ptr2);
	DrMohamed.addPatient(ptr3);
	DrMohamed.addPatient(ptr4);
	DrMohamed.addPatient(ptr5);
	
	DrMohamed.removePatient(4);
	//DrMohamed.searchPatient("nas");
	
	DrMohamed.printPatients();
	return 0;
}