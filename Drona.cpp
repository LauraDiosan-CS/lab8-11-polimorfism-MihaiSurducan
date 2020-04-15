#include <string.h>
#include <iostream>
#include "Drona.h"

using namespace std;

/*Constructorul*/
Drona::Drona()
{
	numeProducator = NULL;
	numeModel = NULL;
	unitatiProduse = 0;
	numarRotoare = 0;
}

Drona::Drona(const char* numeProducator, const char* numeModel, int unitatiProduse, int numarRotoare) {
	this->numeProducator = new char[strlen(numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(numeProducator) + 1, numeProducator);

	this->numeModel = new char[strlen(numeModel) + 1];
	strcpy_s(this->numeModel, strlen(numeModel) + 1, numeModel);

	this->unitatiProduse = unitatiProduse;

	this->numarRotoare = numarRotoare;
}

Drona::Drona(const Drona& d) {
	this->numeProducator = new char[strlen(d.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(d.numeProducator) + 1, d.numeProducator);

	this->numeModel = new char[strlen(d.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(d.numeModel) + 1, d.numeModel);

	this->unitatiProduse = d.unitatiProduse;

	this->numarRotoare = d.numarRotoare;
}


char* Drona::getNumeProducator() {
	return numeProducator;
}

void Drona::setNumeProducator(const char* n) {
	if (numeProducator) delete[]numeProducator;
	numeProducator = new char[strlen(n) + 1];
	strcpy_s(numeProducator, strlen(n) + 1, n);
}

char* Drona::getNumeModel() {
	return numeModel;
}

void Drona::setNumeModel(const char* n) {
	if (numeModel) delete[]numeModel;
	numeModel = new char[strlen(n) + 1];
	strcpy_s(numeModel, strlen(n) + 1, n);
}

int Drona::getUnitatiProduse()
{
	return unitatiProduse;
}

void Drona::setUnitatiProduse(int n) {
	unitatiProduse = n;
}

int Drona::getNumarRotoare()
{
	return numarRotoare;
}

void Drona::setNumarRotoare(int n) {
	numarRotoare = n;
}

/*Destructorul*/
Drona::~Drona() {
	if (numeProducator) delete[]numeProducator;
	numeProducator = NULL;

	if (numeModel) delete[]numeModel;
	numeModel = NULL;

	unitatiProduse = -1;
	numarRotoare = -1;
}

Drona& Drona::operator=(const Drona& d) {
	if (this == &d) return *this; //self-assignment

	if (numeProducator) delete[]numeProducator;
	this->numeProducator = new char[strlen(d.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(d.numeProducator) + 1, d.numeProducator);

	if (numeModel) delete[]numeModel;
	this->numeModel = new char[strlen(d.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(d.numeModel) + 1, d.numeModel);

	this->unitatiProduse = d.unitatiProduse;

	this->numarRotoare = d.numarRotoare;
	
	return *this;
}

bool Drona::operator==(const Drona& d) {
	if (d.numeProducator and d.numeModel and d.unitatiProduse and d.numarRotoare)
		return (strcmp(numeProducator, d.numeProducator) == 0) and (strcmp(numeModel, d.numeModel) == 0) and (unitatiProduse == d.unitatiProduse) and (numarRotoare == d.numarRotoare);
	return false;
}

ostream& operator<<(ostream& os, Drona d)
{
	os << "NumeProducator - " << d.numeProducator << ", NumeModel - " << d.numeModel << ",UnitatiProduse - " << d.unitatiProduse << ",NumarRotoare - " << d.numarRotoare << endl;
	return os;
}

istream& operator>>(istream& is, Drona& d)
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
	cout << "NumarRotoare:";
	int nr;
	is >> nr;
	d.setNumeProducator(nameP);
	d.setNumeModel(nameM);
	d.setUnitatiProduse(up);
	d.setNumarRotoare(nr);
	delete[] nameP;
	delete[] nameM;
	
	return is;

}

