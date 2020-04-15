#pragma once
#pragma once
#pragma once
#include <iostream>

using namespace std;

class Telefon {
private:
	char* numeProducator;
	char* numeModel;
	int unitatiProduse;
	char* listaOperatoriGSMCompatibile;

public:
	Telefon();
	Telefon(const char*, const char*, int, const char*);
	Telefon(const Telefon&);
	Telefon& operator=(const Telefon&);
	char* getNumeProducator();
	char* getNumeModel();
	int getUnitatiProduse();
	char* getListaOperatoriGSMCompatibile();
	void setNumeProducator(const char*);
	void setNumeModel(const char*);
	void setUnitatiProduse(int);
	void setListaOperatoriGSMCompatibile(const char*);
	bool operator==(const Telefon&);
	friend ostream& operator<<(ostream& os, Telefon);
	friend istream& operator>>(istream& is, Telefon&);
	~Telefon();
};