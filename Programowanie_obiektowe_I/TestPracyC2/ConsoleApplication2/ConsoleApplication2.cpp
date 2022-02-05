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
	Osoba(const char* im, const char* nazw, int pes);
	Osoba();
	/*wczytaj();
	wyswietl();*/
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
	Baza();
	//dodaj_osobe(Osoba *os);
	int szukaj(int pesel, Osoba *os);
	void wyswietl_liste();
	int usun(int pesel);
};


typedef struct {
	char imie[MAXLEN];
	char nazwisko[MAXLEN];
	int pesel;
} osoba_t;

osoba_t tab[MAX]; // Tablica zawierajaca struktury typu osoba_t
int lelem = 0;    // aktualna liczba elementow tablicy
int koniec = 0;    // pozycja na ktorej wstawic nastepny element

int   wczytaj_osobe(osoba_t* osoba);
int   dodaj_osobe(osoba_t* osoba);
int   szukaj_osobe(int pesel, osoba_t* osoba);
void  wyswietl_osobe(osoba_t* osoba);
void  wyswietl_liste(osoba_t tab[]);
int   usun_osobe(int pesel);
void  menu(void);
int   zapisz(void);
int   odczyt(void);

int main() {
	koniec = 0;
	lelem = 0;
	int pesel;
	int wybor, res;
	osoba_t osoba;
	cout << "Baza danych osob" << endl;

	res = odczyt();
	if (res > 0) {
		cout << "odczytano " << res << " pozycji" << endl;
		wyswietl_liste(tab);
	}
	else {
		cout << "Brak bazy danych" << endl;
	}


	/*
	osoba_t os1 = {"Adam","Kon",11};
	osoba_t os2 = {"wieslaw","Wilk",22};
	osoba_t os3 = {"Ewa","Koza",33};
	wczytaj_osobe(&osoba);
	wyswietl_osobe(&osoba);
	dodaj_osobe(&os1);
	dodaj_osobe(&os2);
	dodaj_osobe(&os3);
	wyswietl_liste(tab);
	szukaj_osobe(22,&osoba);
	usun_osobe(22);
	wyswietl_liste(tab);
	*/

	do {
		menu();
		wybor = _getch();
		// cout << "wybrano " << wybor << endl;
		switch (wybor) {
		case '1': wczytaj_osobe(&osoba); dodaj_osobe(&osoba); break;
		case '2': wyswietl_liste(tab); break;
		case '3': cout << "Szukaj - podaj pesel ";
			cin >> pesel;
			szukaj_osobe(pesel, &osoba);
			break;
		case '4': cout << "Usun - podaj pesel ";
			cin >> pesel;
			usun_osobe(pesel);
			break;
		case '5': zapisz(); break;
		case '6': cout << "Koniec" << endl;
			return 0;
		}
	} while (1);
	cout << "Koniec" << endl;
}


int dodaj_osobe(osoba_t* osoba) {
	int i = 0;
	int przed = 0;
	if (koniec == MAX) { // Tablica pelna
		cout << "Brak miejsca" << endl;
		return 0;
	}
	tab[koniec] = *osoba;
	cout << "dodano na pozycji:" << koniec << " " << osoba->nazwisko << endl;
	koniec++;
	lelem++;
	return koniec;
}


int wczytaj_osobe(osoba_t* osoba) {
	int cnt = 0;
	cout << "Podaj imie: ";
	cin >> osoba->imie;
	cnt++;
	cout << "Podaj nazwisko: ";
	cin >> osoba->nazwisko;
	cnt++;
	cout << "Podaj pesel: ";
	cin >> osoba->pesel;
	cnt++;
	return cnt;
}

void wyswietl_osobe(osoba_t* osoba) {
	int cnt = 0;
	cout << osoba->imie << " ";
	cout << osoba->nazwisko << " ";
	cout << osoba->pesel << endl;
	return;
}

void wyswietl_liste(osoba_t tab[]) {
	int i = 0;
	if (lelem == 0) {
		cout << "Lista jest pusta" << endl;
		return;
	}
	cout << "Wyswietl - koniec: " << koniec << endl;
	for (i = 0; i < koniec; i++) {
		wyswietl_osobe(&tab[i]);
	}
	return;
}

int szukaj_osobe(int pesel, osoba_t* osoba) {
	int i = 0;
	cout << "Szukaj, koniec: " << koniec << endl;
	for (i = 0; i < koniec; i++) {
		if (tab[i].pesel == pesel) {
			cout << "znaleziono poz: " << i << endl;
			*osoba = tab[i];
			wyswietl_osobe(&tab[i]);
			return i;
		}
	}
	return -1;
}

int usun_osobe(int pesel) {
	int i = 0;
	int found = -1;
	cout << "Usun, koniec: " << koniec << endl;
	// Najpierw szukamy osoby
	for (i = 0; i < koniec; i++) {
		if (tab[i].pesel == pesel) {
			cout << "znaleziono poz: " << i << endl;
			wyswietl_osobe(&tab[i]);
			found = i;
		}
	}
	// Sprawdzamy czy znaleziono ---
	if (found < 0) {
		cout << "Nie znaleziono osoby" << endl;
		return 0;
	}
	// Usuwamy osobe ---------------
	cout << "usuwamy z pozycji: " << found << endl;
	for (i = found; i < koniec; i++) {
		tab[i] = tab[i + 1];
	}
	koniec--;
	lelem--;
	return koniec;
}

void menu(void) {
	cout << "1 dodaj, 2 lista, 3 szukaj, 4 usun, 5 zapisz, 6 koniec\n";
}

int zapisz() {
	int file;
	int i;
	cout << "Elementow: " << lelem << endl;
	file = _open("baza.dat", O_WRONLY | O_CREAT, 0666);
	if (file < 0) {
		perror("_open: ");
		return 0;
	}
	for (i = 0; i < lelem; i++) {
		cout << "zapis el: " << i << endl;
		_write(file, &tab[i], sizeof(osoba_t));
	}
	_close(file);
}

int odczyt() {
	int file, res;
	int i = 0;
	osoba_t os;
	file = _open("baza.dat", O_RDONLY);
	if (file < 0) {
		perror("_open: ");
		return 0;
	}
	do {
		res = _read(file, &os, sizeof(osoba_t));
		cout << "odczyt el: " << i << " wynik " << res << endl;
		if (res < sizeof(osoba_t)) break;
		cout << os.imie << " " << os.nazwisko << " " << os.pesel << endl;
		tab[i] = os;
		i++;
	} while (1);
	_close(file);
	// Aktualizacja zm. globalnych
	lelem = i;
	koniec = i;
	return i;
}