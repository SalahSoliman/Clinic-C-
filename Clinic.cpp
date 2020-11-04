#include "Clinic.h"

Clinic::Clinic()
{
	firstPatient = NULL;
	PatientsNum = 0;
}
int Clinic::getPatientsNum()
{
	return PatientsNum;
}
bool Clinic::passwordCheck()
{
	return 1;
}
void Clinic::setUserName(char un[255])
{

	for (int i = 0; i < 255; i++)
	{
		username[i] = un[i];
		//♣
	}

}
void Clinic::setPassword(char pass[255])
{
	for (int i = 0; i < 255; i++)
		password[i] = pass[i];
}

void Clinic::addPatient()
{
	PatientsNum++;
	cout << "Patient: " << PatientsNum << endl;
	Patient *P = new Patient;
	Patient *currPatient = firstPatient;
	if (firstPatient == NULL)
	{
		firstPatient = P;
		cin >> firstPatient;
		P->addMedicalHistory();
		return;
	}
	else
	{
		while (currPatient->getNext() != NULL)
		{
			currPatient = currPatient->getNext();
		}
		cin >> P;
		currPatient->setNext(P);
	}
	P->addMedicalHistory();
}

void Clinic::printPatients()
{
	if (PatientsNum == 0)
	{
		cout << "No Patients to print..." << endl;
		return;
	}
	cout << endl;
	cout << "Number of Patients in the List: " << PatientsNum << endl;
	cout << "___________________________________________________________" << endl;
	Patient *currPatient = firstPatient;

	int i = 0;
	while (PatientsNum - i != 0)
	{

		cout << "Patient: " << i + 1 << endl;
		cout << "Name :" << currPatient->getName() << endl;
		cout << "Address:" << currPatient->getAddress() << endl;
		cout << "Date of Birth: ";
		cout << currPatient->getDate();
		cout << currPatient->getContact();
		currPatient->printMed();
		currPatient = currPatient->getNext();
		cout << "___________________________________________________________" << endl;
		i++;
	}
}
void Clinic::removePatient(string name)
{
	//if (!passwordCheck())
	//	return;
	if (PatientsNum == 0)
	{
		cout << "There is no patients in your list to remove..." << endl;
		return;
	}
	else
	{
		PatientsNum--;
		Patient *currPatient = firstPatient;
		Patient *temp = firstPatient;

		if (firstPatient->getName() == name)
		{
			currPatient = firstPatient->getNext();
			firstPatient = currPatient;
			delete temp;
			cout << "The Patient '" << name << "' is Terminated..." << endl;
			return;
		}


		while (currPatient->getNext() != NULL)
		{
			if (currPatient->getNext()->getName() == name)
			{
				temp = currPatient;
				currPatient = currPatient->getNext();
				temp->setNext(currPatient->getNext());
				delete currPatient;
				cout << "The Patient '" << name << "' is Terminated..." << endl;
				return;
			}
			currPatient = currPatient->getNext();

		}
	}
}
void Clinic::removePatient(int i)
{
	//if (passwordCheck() == 0)
	//	return;
	if (i>PatientsNum || i <= 0)
	{
		cout << "There is no Patient with this order in the list..." << endl;
		return;
	}
	else
	{
		PatientsNum--;
		int j = 1;
		Patient *currPatient = firstPatient;
		Patient *temp = firstPatient;
		while (i >= j)
		{
			if (i - j == 1 || i == j)
			{
				if (i == 1)
				{
					firstPatient = currPatient->getNext();
					delete currPatient;
					cout << "The Patient number '" << i << "' is Terminated..." << endl;
					return;
				}
				else
				{
					temp = currPatient;
					currPatient = currPatient->getNext();
					temp->setNext(currPatient->getNext());
					delete currPatient;
					cout << "The Patient number '"<<i<<"' is Terminated..." << endl;
					return;
				}
			}
			else if (currPatient->getNext() != NULL)
			{
				currPatient = currPatient->getNext();
			}
			j++;
		}

	}
}
Patient* Clinic::searchPatient(string n)
{
	int flag = 0;
	Patient *currPatient = firstPatient;
	for (int i = 0; i<PatientsNum; i++)
	{
		if (currPatient->getName() == n)
		{
			//strncmp((currPatient->getName()).c_str(), n.c_str(), strlen(n.c_str())) == 0
			char c;
			cout << "The patient's info you are looking for is: " << endl;
			cout << *currPatient << endl;
			cout << "Do you want to modify any of the Patient's info...?(y/n) " << endl;
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				cout << "To Modify Name Press '1'" << endl;
				cout << "To Modify Address Press '2'" << endl;
				cout << "To Modify Date of birth Press '3'" << endl;
				cout << "To Modify Contact Press '4'" << endl;
				cout << "To Remove This Patient Press '5'" << endl;
				cout << "To add Medical history Press '6'" << endl;
				while (c)
				{
					cout << " your choice : ";
					cin >> c;
					cin.ignore();

					if (c == '1')
					{
						string name;
						cout << "Name: ";
						cin >> name;
						currPatient->setName(name);
					}

					else if (c == '2')
					{

						string address;
						cout << "Address: ";
						cin >> address;
						currPatient->setAddress(address);
					}
					else if (c == '3')
					{
						unsigned int d, m, y;
						cout << "Day: ";
						cin >> d;

						cout << "Month: ";
						cin >> m;

						cout << "Year: ";
						cin >> y;
						currPatient->setDate(d, m, y);
					}
					else if (c == '4')
					{
						string mobileN, tele, email;
						cout << "Mobile: ";
						cin >> mobileN;
						cout << "Tel: ";
						cin >> tele;
						cout << "E-mail: ";
						cin >> email;
						currPatient->setContact(mobileN, tele, email);

					}
					else if (c == '5')
					{
						removePatient(currPatient->getName());
						flag = 1;
					}
					else if (c == '6')
					{
						currPatient->addMedicalHistory();
					}
					if (flag != 1)
					{
						cout << "Do you want to modify any thing else...?(y/n)" << endl;
						cin >> c;
						cin.ignore();

						if (c == 'n' || c == 'N')
							break;
					}
					else
						break;
				}
			}

			return currPatient;
		}
		currPatient = currPatient->getNext();
	}
	cout << n << " is not in the list..." << endl;
	return NULL;
}


bool Clinic::ReadFile(string F)
{
	ifstream ifile(F);
	ifstream ifile2(F);
	string c;
	if (ifile.is_open() && getline(ifile2,c) )
	{
		Patient *p = new Patient;
		firstPatient = p;
		PatientsNum++;
		int i = 0, n = 0;
		string k, m, M, T;
		Date d;
		MedicalHistory* MH = new MedicalHistory;
		PrescribedMedicines *PM = new PrescribedMedicines;
		p->SetFirstMH(MH);
		p->SetPMN(p->GetPMN() + 1);
		MH->setFirstMedicine(PM);
		MH->setMedicineNumber(1);
		while (getline(ifile, m))
		{
			n++;
			if (i == 13 && m != "#" && m != "@")
			{
				i = 0;
				Patient *ptr = new Patient;
				MedicalHistory* mm = new MedicalHistory;
				PrescribedMedicines *pm = new PrescribedMedicines;
				PatientsNum++;
				p->setNext(ptr);
				p = ptr;
				MH = mm;
				PM = pm;
				p->SetFirstMH(mm);
				p->SetPMN(p->GetPMN()+1);
				MH->setFirstMedicine(pm);
				mm->setMedicineNumber(1);

			}
			else if (i == 13 && m == "#")
			{
				i = 8;
				getline(ifile, m);
				MedicalHistory* mm = new MedicalHistory;
				PrescribedMedicines *pm = new PrescribedMedicines;
				p->SetPMN(p->GetPMN() + 1);
				MH->setNextMedical(mm);
				mm->setFirstMedicine(pm);
				mm->setMedicineNumber(mm->getMedicinesNUmber() + 1);
				MH = mm;
				PM = pm;
			}
			else if (i == 13 && m == "@")
			{
				i = 12;
				getline(ifile, m);
				PrescribedMedicines *pm = new PrescribedMedicines;
				MH->setMedicineNumber(MH->getMedicinesNUmber() + 1);
				PM->setNextMedicine(pm);
				PM = pm;
			}
			if (i == 0) {
				p->setName(m);

			}
			else if (i == 1)
			{
				p->setAddress(m);
			}
			else if (i == 2)
			{

				M = m;
			}
			else if (i == 3)
			{

				T = m;
			}
			else if (i == 4)
			{

				string E = m;
				p->setContact(M, T, E);
			}
			else if (i == 5)
			{
				d.setDay(stoi(m));

			}
			else if (i == 6)
			{
				d.setMonth(stoi(m));

			}
			else if (i == 7)
			{
				d.setYear(stoi(m));
				p->setDate(d);
			}

			else if (i == 8)
			{
				MH->setDiagnosis(m);
			}
			else if (i == 9)
			{
				d.setDay(stoi(m));
			}
			else if (i == 10)
			{
				d.setMonth(stoi(m));
			}
			else if (i == 11)
			{
				d.setYear(stoi(m));
				MH->setDateofDiagnosis(d.getDay(), d.getMonth(), d.getYear());
			}
			else if (i == 12)
			{
				PM->setMedicine(m);
			}
			i++;
		}
		//if (n == 0)
		//{
		//	delete firstPatient;
		//	PatientsNum = 0;
		//		firstPatient = NULL;
		//}
	}
	ifile.close();
	ifile2.close();
	return 1;
}

bool Clinic::WriteFile(string F)
{
	ofstream ofile(F);
	string s;
	Contact C;
	Date d;
	Patient *p = firstPatient;
	MedicalHistory *m;
	PrescribedMedicines *M;
	if (p != NULL) {
		m = p->getMH();
	M = m->getFirstMed();
	}

	while (p != NULL)
	{
		m = p->getMH();
		s = p->getName();
		ofile << s << "\n";
		s = p->getAddress();
		ofile << s << "\n";
		C = p->getContact();
		s = C.getMobile();
		ofile << s << "\n";
		s = C.getTel();
		ofile << s << "\n";
		s = C.getEmail();
		ofile << s << "\n";
		d = p->getDate();
		ofile << d.getDay() << "\n" << d.getMonth() << "\n" << d.getYear() << "\n";
		int j = 0;
		while (m != NULL)
		{
			M = m->getFirstMed();
			d = m->getDateofDiagnosis();
			if (j > 0)ofile << "\n" << "#" << "\n";
			ofile << m->getDiagnosis() << "\n" << d.getDay() << "\n" << d.getMonth() << "\n" << d.getYear();
			int i = 0;
			while (M != NULL)
			{
				if (i > 0)ofile << "\n" << "@";
				ofile << "\n" << M->getMedicine();
				M = M->getNextMedicine();
				i++;
			}
			m = m->getNextMedical();
			j++;
		}
		p = p->getNext();
		ofile << "\n";
	}
	ofile.close();
	return 1;
}

Clinic::~Clinic()
{
	Patient *P=firstPatient;
	while (firstPatient != NULL)
	{
		P = P->getNext();
		delete firstPatient;
		firstPatient = P;
	}
	PatientsNum = 0;
}
//void Clinic::deleteP()
//{
//	bool flag = 0;
//	Patient *P = firstPatient;
//	Patient *P1 = firstPatient;
//	for (int i = 0; i < PatientsNum; i++)
//	{
//		while (P->getNext() != NULL)
//		{
//			if (flag)
//			{
//				P1 = P1->getNext();
//				flag = 0;
//			}
//			else if (!flag)
//			{
//				flag = 1;
//			}
//			P = P->getNext();
//		}
//		delete P;
//		P1->setNext(NULL);
//		P = firstPatient;
//		P1 = firstPatient;
//		flag = 0;
//	}
//	PatientsNum = 0;
//	firstPatient = NULL;
//}


