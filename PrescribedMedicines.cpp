#include "PrescribedMedicines.h"

PrescribedMedicines::PrescribedMedicines()
{
	setMedicine("");
	setNextMedicine(NULL);
}
void PrescribedMedicines::setMedicine(string med)
{
	Medicine = med;
}
string PrescribedMedicines::getMedicine()
{
	return Medicine;
}
void PrescribedMedicines::setNextMedicine(PrescribedMedicines *MED)
{
	nextMedicine = MED;
}
PrescribedMedicines* PrescribedMedicines::getNextMedicine()
{
	return nextMedicine;
}
istream& operator >> (istream &is, PrescribedMedicines *PM)
{ 

	char med[255];
	cout << "Medicine: ";
	cin.getline(med, 255);
	PM->setMedicine(med);
	return is;

}

ostream& operator << (ostream &is, PrescribedMedicines &PM)
{
	is << PM.getMedicine();

	return is;
}