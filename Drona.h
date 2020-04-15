#pragma once
#pragma once
#include <iostream>

using namespace std;

class Drona {
private:
	char* numeProducator;
	char* numeModel;
	int unitatiProduse;
	int numarRotoare;

public:
	Drona();
	Drona(const char*, const char*, int, int);
	Drona(const Drona&);
	Drona& operator=(const Drona&);
	char* getNumeProducator();
	char* getNumeModel();
	int getUnitatiProduse();
	int getNumarRotoare();
	void setNumeProducator(const char*);
	void setNumeModel(const char*);
	void setUnitatiProduse(int);
	void setNumarRotoare(int);
	bool operator==(const Drona&);
	friend ostream& operator<<(ostream& os, Drona);
	friend istream& operator>>(istream& is, Drona&);
	~Drona();
};