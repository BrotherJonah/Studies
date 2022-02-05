// Baza danych osob oparta na tablicy
// Zapis/odczyt bazy danych do/z pliku
#include <iostream>
#include <stdio.h> 
#include <string>
#include <conio.h>
#include <fstream>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <fcntl.h>

#define BNAME "baza.dat" 
#define MAXLEN 40

using namespace std;

const int MAX = 50;

class Osoba {
private:
	char imie[MAXLEN];
	char nazwisko[MAXLEN];
	int pesel;
public:
	Osoba(const char* im, const char* nazw, int pes) {
		strcpy(imie, im);
		strcpy(nazwisko, nazw);
	};
	Osoba() {
		strcpy(imie, "");
		strcpy(nazwisko, "");
	};
	void wczytaj() {
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj pesel: ";
		cin >> pesel;
	};
	void wyswietl() {
		cout << imie << "\t";
		cout << nazwisko << "\t";
		cout << pesel << endl;
	};
	   
	int szukaj(int pes, Osoba* os);
	int daj_pesel() {
		return pesel;
	}
	char* daj_nazwisko() {
		return nazwisko;
	}
};

class Baza {
	Osoba tab[MAX];
public:
	int lelem = 0;    // aktualna liczba elementow tablicy
	int koniec = 0;    // pozycja na ktorej wstawic nastepny element
	Baza();
	int dodaj_osobe(Osoba* os) {
		cout << "Dodaj: ";
		os->wczytaj();
		int i = 0;
		int przed = 0;
		if (koniec == MAX) { 
			cout << "Brak miejsca" << endl;
			return 0;
		}
		tab[koniec] = *os;
		cout << "dodano na pozycji:" << koniec << " osobe o nazwisku: " << os->daj_nazwisko() << endl;
		koniec++;
		lelem++;
		return koniec;
	};

	int szukaj(int pesel, Osoba *os) {
		Osoba osoba;
		int i = 0;
		int pes;
		//cout << "Szukaj, koniec: " << koniec << endl;
		for (i = 0; i < koniec; i++) {
			osoba = tab[i];
			pes = osoba.daj_pesel();
			if (pes == pesel) {
				cout << "znaleziono poz: " << i << " Nazwisko: " << *os->daj_nazwisko() << endl;
				return i;
			}
		}
		return -1;
	};

	void wyswietl_liste(Osoba tab[]) {
		Osoba osoba;
		int i = 0;
		if (lelem == 0) {
			cout << "Lista jest pusta" << endl;
			return;
		}
		cout << "Wyswietl - koniec: " << koniec << endl;
		for (i = 0; i < koniec; i++) {
			osoba = tab[i];
			osoba.wyswietl();
		}
		cout << "liczba elementow: " << lelem;
		return;
	};

	int usun(int pesel) {
		int i = 0;
		int found = -1;
		Osoba osoba;

		cout << "Usun osobê pesel: " << pesel << endl;
		found = szukaj(pesel, &osoba);
		if (found < 0) {
			cout << "Nie ma takiej osoby w bazie danych" << endl;
			return -1;
		}
		else {
			cout << "Znalazlem i usuwam osobê z pozycji: " << found << " osobe o nazwisku " << osoba.daj_nazwisko() << endl;
			for (i = found; i < koniec; i++) {
				tab[i] = tab[i + 1];
			}
			koniec--;
			lelem--;
			return koniec;
		}
	};
};

void menu(void) {
	cout << "1 dodaj, 2 lista, 3 szukaj, 4 usun, 5 zapisz, 6 koniec\n";
}


//typedef struct {
//	char imie[MAXLEN];
//	char nazwisko[MAXLEN];
//	int pesel;
//} osoba_t;

//osoba_t tab[MAX]; // Tablica zawierajaca struktury typu osoba_t



int main() {
	int pesel;
	int wybor, res;
	int index;
	Baza mybaza;
	/*osoba_t osoba;*/
	Osoba osoba;

	/*res = odczyt();
	if (res > 0) {
		cout << "odczytano " << res << " pozycji" << endl;
		mybaza.wyswietl_liste();
	}
	else {
		cout << "Brak bazy danych" << endl;
	}*/

	do {
		menu();
		wybor = getch();
		switch (wybor) {
		case '1': osoba.wczytaj();
			mybaza.dodaj_osobe(&osoba);
			break;
		case '2': mybaza.wyswietl_liste(&osoba);
			break;
		case '3': cout << "Szukaj podaj pesel: ";
			cin >> pesel;
			mybaza.szukaj(pesel, &osoba);
			osoba.wyswietl();
			break;
		case '4': cout << "Usun podaj pesel: ";
			cin >> pesel;
			mybaza.usun(pesel);
			break;
		case '5': cout << "Koniec" << endl;
			return 0;
		}
	} while (1);
	cout << "Koniec" << endl;
}




//int zapisz() {
//	int file;
//	int i;
//	cout << "Elementow: " << lelem << endl;
//	file = _open("baza.dat", O_WRONLY | O_CREAT, 0666);
//	if (file < 0) {
//		perror("_open: ");
//		return 0;
//	}
//	for (i = 0; i < lelem; i++) {
//		cout << "zapis el: " << i << endl;
//		_write(file, &tab[i], sizeof(osoba_t));
//	}
//	_close(file);
//}
//
//int odczyt() {
//	int file, res;
//	int i = 0;
//	osoba_t os;
//	file = _open("baza.dat", O_RDONLY);
//	if (file < 0) {
//		perror("_open: ");
//		return 0;
//	}
//	do {
//		res = _read(file, &os, sizeof(osoba_t));
//		cout << "odczyt el: " << i << " wynik " << res << endl;
//		if (res < sizeof(osoba_t)) break;
//		cout << os.imie << " " << os.nazwisko << " " << os.pesel << endl;
//		tab[i] = os;
//		i++;
//	} while (1);
//	_close(file);
//	// Aktualizacja zm. globalnych
//	lelem = i;
//	koniec = i;
//	return i;
//}