#include <string.h>
#include <iostream>
#include "Telefon.h"

using namespace std;

/*Constructorul*/
Telefon::Telefon()
{
	numeProducator = NULL;
	numeModel = NULL;
	unitatiProduse = 0;
	listaOperatoriGSMCompatibile = NULL;
}

Telefon::Telefon(const char* numeProducator, const char* numeModel, int unitatiProduse, const char* listaOperatoriGSMCompatibile) {
	this->numeProducator = new char[strlen(numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(numeProducator) + 1, numeProducator);

	this->numeModel = new char[strlen(numeModel) + 1];
	strcpy_s(this->numeModel, strlen(numeModel) + 1, numeModel);

	this->unitatiProduse = unitatiProduse;

	this->listaOperatoriGSMCompatibile = new char[strlen(listaOperatoriGSMCompatibile) + 1];
	strcpy_s(this->listaOperatoriGSMCompatibile, strlen(listaOperatoriGSMCompatibile) + 1, listaOperatoriGSMCompatibile);
	
}

Telefon::Telefon(const Telefon& t) {
	this->numeProducator = new char[strlen(t.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(t.numeProducator) + 1, t.numeProducator);

	this->numeModel = new char[strlen(t.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(t.numeModel) + 1, t.numeModel);

	this->unitatiProduse = t.unitatiProduse;

	this->listaOperatoriGSMCompatibile = new char[strlen(t.listaOperatoriGSMCompatibile) + 1];
	strcpy_s(this->listaOperatoriGSMCompatibile, strlen(t.listaOperatoriGSMCompatibile) + 1, t.listaOperatoriGSMCompatibile);
}


char* Telefon::getNumeProducator() {
	return numeProducator;
}

void Telefon::setNumeProducator(const char* n) {
	if (numeProducator) delete[]numeProducator;
	numeProducator = new char[strlen(n) + 1];
	strcpy_s(numeProducator, strlen(n) + 1, n);
}

char* Telefon::getNumeModel() {
	return numeModel;
}

void Telefon::setNumeModel(const char* n) {
	if (numeModel) delete[]numeModel;
	numeModel = new char[strlen(n) + 1];
	strcpy_s(numeModel, strlen(n) + 1, n);
}

int Telefon::getUnitatiProduse()
{
	return unitatiProduse;
}

void Telefon::setUnitatiProduse(int n) {
	unitatiProduse = n;
}

char* Telefon::getListaOperatoriGSMCompatibile()
{
	return listaOperatoriGSMCompatibile;
}

void Telefon::setListaOperatoriGSMCompatibile(const char* n) {
	if (listaOperatoriGSMCompatibile) delete[]listaOperatoriGSMCompatibile;
	listaOperatoriGSMCompatibile = new char[strlen(n) + 1];
	strcpy_s(listaOperatoriGSMCompatibile, strlen(n) + 1, n);
}

/*Destructorul*/
Telefon::~Telefon() {
	if (numeProducator) delete[]numeProducator;
	numeProducator = NULL;

	if (numeModel) delete[]numeModel;
	numeModel = NULL;

	unitatiProduse = -1;
	
	if (listaOperatoriGSMCompatibile) delete[]listaOperatoriGSMCompatibile;
	listaOperatoriGSMCompatibile = NULL;
}

Telefon& Telefon::operator=(const Telefon& t) {
	if (this == &t) return *this; //self-assignment

	if (numeProducator) delete[]numeProducator;
	this->numeProducator = new char[strlen(t.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(t.numeProducator) + 1, t.numeProducator);

	if (numeModel) delete[]numeModel;
	this->numeModel = new char[strlen(t.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(t.numeModel) + 1, t.numeModel);

	this->unitatiProduse = t.unitatiProduse;

	if (listaOperatoriGSMCompatibile) delete[]listaOperatoriGSMCompatibile;
	this->listaOperatoriGSMCompatibile = new char[strlen(t.listaOperatoriGSMCompatibile) + 1];
	strcpy_s(this->listaOperatoriGSMCompatibile, strlen(t.listaOperatoriGSMCompatibile) + 1, t.listaOperatoriGSMCompatibile);

	return *this;
}

bool Telefon::operator==(const Telefon& t) {
	if (t.numeProducator and t.numeModel and t.unitatiProduse and t.listaOperatoriGSMCompatibile)
		return (strcmp(numeProducator, t.numeProducator) == 0) and (strcmp(numeModel, t.numeModel) == 0) and (unitatiProduse == t.unitatiProduse) and (strcmp(listaOperatoriGSMCompatibile, t.listaOperatoriGSMCompatibile) == 0);
	return false;
}

ostream& operator<<(ostream& os, Telefon t)
{
	os << "NumeProducator - " << t.numeProducator << ", NumeModel - " << t.numeModel << ",UnitatiProduse - " << t.unitatiProduse << ",OperatoriGSM - " << t.listaOperatoriGSMCompatibile << endl;
	return os;
}

istream& operator>>(istream& is, Telefon& t)
{
	cout << "NumeProducator:";
	char* nameP = new char[20];
	is >> nameP;
	cout << "NumeModel:";
	char* nameM = new char[20];
	is >> nameM;
	cout << "UnitatiProduse:";
	int up;
	is >> up;
	cout << "OperatoriGSM:";
	char* op = new char[100];
	is >> op;
	t.setNumeProducator(nameP);
	t.setNumeModel(nameM);
	t.setUnitatiProduse(up);
	t.setListaOperatoriGSMCompatibile(op);
	delete[] nameP;
	delete[] nameM;
	delete[] op;

	return is;

}

