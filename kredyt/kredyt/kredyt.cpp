#include <iostream> 
#include <fstream> //zapis odczyt
#include <string> // zmienne tekstowe

using namespace std; //cin cout

//pobranie danych z pliku txt i wypisanie ich w command line
class porownanie {
public:
	string tekst;

	void wypisz() {
		ifstream plik("bank.txt");

		while (getline(plik, tekst)) {
			cout << tekst << endl;
		}
		tekst.clear();
	};
};

//wszystkie istotne kalkulacje i symulacja splat
class kalkulacja {
public:
	int lata, dni, miesiac;
	double rata, kwota, rrso, koszt, calosc;
	string nazwa;

	//wzor na obliczenie kosztow
	void wzor() {
		dni = lata * 365;
		miesiac = lata * 12;

		koszt = (rrso / 100.0) * kwota * (dni / 365.0);

		calosc = koszt + kwota;

		rata = calosc / miesiac;
	}

	//symulacja i zapis do pliku 
	void symulacja() {

		ofstream plik(nazwa);

		for (int i = 1; i <= miesiac; i++) {
			calosc = calosc - rata;
			cout << i << ". miesiac, rata: " << rata << " pozostaje: " << calosc << endl;
			plik << i << ". miesiac, rata: " << rata << " pozostaje: " << calosc << endl;
		}
		plik.close();
	}
};

int main() {

	porownanie f1;
	kalkulacja k1;
	int x, y, z;

	//pierwsze menu
	do {
		cout << "\n Kalkulator hipoteki" << endl;
		cout << "1. Sprawdzenie aktualnego RRSO w bankach" << endl;
		cout << "2. Kalkulacja kredytu" << endl;
		cout << "3. Wyjscie" << endl;
		cout << "Wybierz opcje: "; cin >> x; cout << "\n";


		//zabezpieczenie przed wpisaniem zlej liczby
		if (x <= 3 && x >= 1) {
			switch (x) {
				//class porownanie
				case 1: {
					f1.wypisz();
					break;
				}
				//class kalkulacja
				case 2: {
					cout << "\nW jakim banku chcialbys wziac kredyt?" << endl;
					cout << "1. mBank" << endl;
					cout << "2. Millennium" << endl;
					cout << "3. Santander" << endl;
					cout << "4. Alior Bank" << endl;
					cout << "5. ING" << endl;
					cout << "6. Wyjdz" << endl;
					cout << "Wybierz opcje: "; cin >> y; cout << "\n";

						if (y <= 5 && y >= 1) {
							switch (y) {
							case 1: {
								k1.rrso = 6.83;
								cout << "\nPrzez ile lat chcesz splacac kredyt? "; cin >> k1.lata;
								if (k1.lata <= 35 && k1.lata >= 1) {
									cout << "\nNa jaka kwote chcesz sie zapozyczyc? "; cin >> k1.kwota;
									k1.wzor();
									cout << "do splaty bedzie: " << k1.calosc << endl;
									cout << "rata miesieczna: " << k1.rata << endl;

									cout << "\nWykonac symulacje splat? \n 1 - Tak \n 2 - Nie" << endl;
									cin >> z;
									switch (z) {
									case 1: {
										k1.nazwa = "mBank";
										k1.symulacja();
									}
									case 2: {
										break;
									}
									default: {
										cout << "niepoprawny wybor" << endl;
									}
									}
								}
								else {
									cout << "niepoprawna liczba lat";
								}
								break;
							}
							case 2: {
								k1.rrso = 8.88;
								cout << "\nPrzez ile lat chcesz splacac kredyt? "; cin >> k1.lata;
								if (k1.lata <= 35 && k1.lata >= 1) {
									cout << "\nNa jaka kwote chcesz sie zapozyczyc? "; cin >> k1.kwota;
									k1.wzor();
									cout << "do splaty bedzie: " << k1.calosc << endl;
									cout << "rata miesieczna: " << k1.rata << endl;

									cout << "\nWykonac symulacje splat? \n 1 - Tak \n 2 - Nie" << endl;
									cin >> z;

									switch (z) {
									case 1: {
										k1.nazwa = "Millennium";
										k1.symulacja();
									}
									case 2: {
										break;
									}
									default: {
										cout << "niepoprawny wybor" << endl;
									}
									}
								}
								else {
									cout << "niepoprawna liczba lat";
								}
								break;
							}
							case 3: {
								k1.rrso = 7.57;
								cout << "\nPrzez ile lat chcesz splacac kredyt? "; cin >> k1.lata;
								if (k1.lata <= 35 && k1.lata >= 1) {
									cout << "\nNa jaka kwote chcesz sie zapozyczyc? "; cin >> k1.kwota;
									k1.wzor();
									cout << "do splaty bedzie: " << k1.calosc << endl;
									cout << "rata miesieczna: " << k1.rata << endl;

									cout << "\nWykonac symulacje splat? \n 1 - Tak \n 2 - Nie" << endl;
									cin >> z;

									switch (z) {
									case 1: {
										k1.nazwa = "Santander";
										k1.symulacja();
									}
									case 2: {
										break;
									}
									default: {
										cout << "niepoprawny wybor" << endl;
									}
									}
								}
								else {
									cout << "niepoprawna liczba lat";
								}
								break;
							}
							case 4: {
								k1.rrso = 7.22;
								cout << "\nPrzez ile lat chcesz splacac kredyt? "; cin >> k1.lata;
								if (k1.lata <= 35 && k1.lata >= 1) {
									cout << "\nNa jaka kwote chcesz sie zapozyczyc? "; cin >> k1.kwota;
									k1.wzor();
									cout << "do splaty bedzie: " << k1.calosc << endl;
									cout << "rata miesieczna: " << k1.rata << endl;

									cout << "\nWykonac symulacje splat? \n 1 - Tak \n 2 - Nie" << endl;
									cin >> z;

									switch (z) {
									case 1: {
										k1.nazwa = "Alior Bank";
										k1.symulacja();
									}
									case 2: {
										break;
									}
									default: {
										cout << "niepoprawny wybor" << endl;
									}
									}
								}
								else {
									cout << "niepoprawna liczba lat";
								}
								break;
							}
							case 5: {
								k1.rrso = 7.74;
								cout << "\nPrzez ile lat chcesz splacac kredyt? "; cin >> k1.lata;
								if (k1.lata <= 35 && k1.lata >= 1) {
									cout << "\nNa jaka kwote chcesz sie zapozyczyc? "; cin >> k1.kwota;
									k1.wzor();
									cout << "do splaty bedzie: " << k1.calosc << endl;
									cout << "rata miesieczna: " << k1.rata << endl;

									cout << "\nWykonac symulacje splat? \n 1 - Tak \n 2 - Nie" << endl;
									cin >> z;

									switch (z) {
									case 1: {
										k1.nazwa = "ING";
										k1.symulacja();
									}
									case 2: {
										break;
									}
									default: {
										cout << "niepoprawny wybor" << endl;
									}
									}
								}
								else {
									cout << "niepoprawna liczba lat";
								}
								break;
							}
							case 6: {
								return 0;
								break;
							}
							}
						}
						else {
							cout << "niepoprawny wybor";
						}
				}
				case 3: {
					return 0;
					break;
				}
			}
		}
		else {
			cout << "niepoprawny wybor" << endl;
		}


	} while (x != 3);
}