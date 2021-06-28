#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

const int MAX_OS = 50;          // maksymalna liczba osób w tablicy 


struct osoba {
    string tel;
    string imie;
    string nazwisko;
};

// Wczytanie osob z pliku:
void wczytanie(osoba L[], int &ile_osob) {
    fstream plik;
    plik.open("ksiazka_tel.txt");
    osoba wczytanie;
    for (int i = 0; plik.eof() != 1; i++) {
        getline(plik, wczytanie.imie);
        getline(plik, wczytanie.nazwisko);
        getline(plik, wczytanie.tel);
        L[i] = wczytanie;
        ile_osob++;
    }
    plik.close();
}
// Dodanie osoby:
void dodanie_osoby(osoba L[], int &ile_osob){
    fstream plik;
    plik.open("ksiazka_tel.txt");
    osoba wpisanie;
    if (ile_osob >= MAX_OS)
        cout << "PRZEKROCZONO MAX LICZBE OSOB" << endl;
    else {
        cout << "Imie: ";
        cin >> wpisanie.imie;
        cout << "Nazwisko: ";
        cin >> wpisanie.nazwisko;
        cout << "Telefon: ";
        cin >> wpisanie.tel;
        L[ile_osob] = wpisanie;
        ile_osob++;
        for (int i = 0; i <= ile_osob-1; i++) {
            plik << L[i].imie << endl;
            plik << L[i].nazwisko << endl;
            plik << L[i].tel << endl;
        }
        plik << L[ile_osob].imie << endl;
        plik << L[ile_osob].nazwisko << endl;
        plik << L[ile_osob].tel;
    }
    plik.close();
}

// ------------------------------------------------------------- PISANIE
void lista_osob(osoba L[], int ile_osob)
{
    cout << " imie     |   nazwisko    |      numer telefonu       " << endl;
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < ile_osob; i++) {
        cout << L[i].imie << " ";
        cout << L[i].nazwisko << " ";
        cout << L[i].tel << " ";
        cout << endl;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "#osob = " << ile_osob << endl;
}

// ------------------------------------------------------------- Sortowanie
void sort(osoba L[], int ile_osob) {
    int wybor;
    cout << "Co chcesz posortowac?" << endl;
    cout << "1.Imie" << endl;
    cout << "2.Nazwisko" << endl;
    cout << "3.Numer telefonu" << endl;
    cin >> wybor;
    switch (wybor) {
    case 1:
        for (int i = 0; i < ile_osob; i++)
            for (int j = 1; j < ile_osob; j++)
                if (L[j - 1].imie > L[j].imie)
                    swap(L[j], L[j - 1]);
        break;
    case 2:
        for (int i = 0; i < ile_osob; i++)
            for (int j = 1; j < ile_osob; j++)
                if (L[j - 1].nazwisko > L[j].nazwisko)
                    swap(L[j], L[j - 1]);
        break;
    case 3:
        for (int i = 0; i < ile_osob; i++)
            for (int j = 1; j < ile_osob; j++)
                if (L[j - 1].tel > L[j].tel)
                    swap(L[j], L[j - 1]);
        
        break;
    }
}

void pisz_menu(){
        cout << "MENU glowne" << endl;
        cout << "----------------------" << endl;
        cout << "1 - dodanie osoby" << endl;
        cout << "2 - sortowanie" << endl;
        cout << "3 - lista osob " << endl;
        cout << "0 - koniec pracy" << endl;
        cout << "> ";
};

void menu_main(osoba L[], int ile_osob){
    int wybor;
    wczytanie(L, ile_osob);
    do {
        pisz_menu();
        cin >> wybor;
        switch (wybor){
            case 1:
                dodanie_osoby(L, ile_osob);
                break;
            case 2: 
                sort(L, ile_osob);
                break;
            case 3:
                lista_osob(L, ile_osob);
                break;
        }
    } 
    while (wybor != 0);
}

int main()
{
    osoba L[MAX_OS];    // tablica zawierająca struktury typu osoba  - główna struktura danych
    int ile_osob = 0;
    menu_main(L, ile_osob);
}