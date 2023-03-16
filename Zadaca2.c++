#include <iostream>
using namespace std;

class Stedac
{
public:
void vnesi_podatoci();
void prikazi_podatoci();
void uplata(unsigned long i);
void isplata(unsigned long i);
long sostojba();

private:
int broj;
char imeprezime[30], adresa[50];
long saldo;
};

void Stedac::vnesi_podatoci()
{
cout << "Vnesi broj na stedac: ";
cin >> broj;
cout << "Vnesi ime i prezime: ";
cin.ignore();
cin.getline(imeprezime, 30);
cout << "Vnesi adresa: ";
cin.getline(adresa, 50);
saldo = 0;
}

void Stedac::prikazi_podatoci()
{
cout << "Broj: " << broj << endl;
cout << "Ime i prezime: " << imeprezime << endl;
cout << "Adresa: " << adresa << endl;
cout << "Saldo: " << saldo << endl;
}

void Stedac::uplata(unsigned long i)
{
saldo += i;
}

void Stedac::isplata(unsigned long i)
{
if (saldo >= i) {
saldo -= i;
} else {
cout << "Nema dovolno sredstva na racunot!" << endl;
}
}

long Stedac::sostojba()
{
return saldo;
}

int main()
{
Stedac stedac;
char izbor;
do {
    cout << endl;
    cout << "A - Vnesuvanje na nov stedac" << endl;
    cout << "B - Prikaz na podatoci za stedac" << endl;
    cout << "C - Uplata na sredstva" << endl;
    cout << "D - Isplata na sredstva" << endl;
    cout << "E - Prikaz na saldo" << endl;
    cout << "X - Izlez" << endl;

    cout << "Izbor: ";
    cin >> izbor;

    switch (izbor) {
        case 'A':
        case 'a':
            stedac.vnesi_podatoci();
            break;
        case 'B':
        case 'b':
            stedac.prikazi_podatoci();
            break;
        case 'C':
        case 'c':
            unsigned long i;
            cout << "Vnesi iznos za uplata: ";
            cin >> i;
            stedac.uplata(i);
            break;
        case 'D':
        case 'd':
            unsigned long j;
            cout << "Vnesi iznos za isplata: ";
            cin >> j;
            stedac.isplata(j);
            break;
        case 'E':
        case 'e':
            cout << "Sostojba: " << stedac.sostojba() << endl;
            break;
        case 'X':
        case 'x':
            cout << "Blagodarime sto go koristevte programata!" << endl;
            break;
        default:
            cout << "Nevaliden izbor!" << endl;
            break;
    }
} while (izbor != 'X' && izbor != 'x');

return 0;
}