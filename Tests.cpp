#include "Drona.h"
#include "Telefon.h"
#include  <assert.h>

void TestDrona()
{	
	Drona D1("APPLE", "DroneX", 300, 5);
	Drona D2("US ARMY", "Drone51", 25, 8);
	Drona D3("Samsung", "DroneS", 5556, 9);

	assert(D1.getNumarRotoare() == 5);
	D1.setNumarRotoare(20);
	assert(D1.getNumarRotoare() == 20);

	assert(strcmp(D2.getNumeProducator(), "US ARMY") == 0);

	Drona D4(D1);
	assert(D4 == D1);

	Drona D5;
	assert(D5.getNumarRotoare() == 0);
	assert(D5.getNumeProducator() == NULL);

	Drona D6("Samsung", "DroneS", 5556, 9);
	assert(D6 == D3);

}

void TestTelefon()
{
	Telefon T1("LG", "G6", 560, "DIGI ORANGE");
	Telefon T2("APPLE", "X", 678, "DIGI");
	Telefon T3("Samsung", "S", 789, "DIGI");

	assert(T1.getUnitatiProduse() == 560);
	assert(strcmp(T1.getListaOperatoriGSMCompatibile(), "DIGI ORANGE") == 0);

	assert(strcmp(T2.getNumeProducator(), "APPLE") == 0);

	T3.setNumeModel("S20");
	assert(strcmp(T3.getNumeModel(), "S20") == 0);

	Telefon T4(T1);
	assert(T4 == T1);

	Telefon T5;
	T5.getListaOperatoriGSMCompatibile() == NULL;
	T5.getUnitatiProduse() == 0;
}

void MainTests()
{
	cout << "First Tests" << endl;
	TestDrona();
	TestTelefon();
	cout << "Succesful";
}