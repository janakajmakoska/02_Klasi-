#include <iostream>
#include <vector>

using namespace std;

class Kvadar {
    private:
        double dolzina;
        double sirina;
        double visina;
    public:
        Kvadar(double d, double s, double v) {
            dolzina = d;
            sirina = s;
            visina = v;
        }
        
        double plostina() {
            return 2 * (dolzina * sirina + dolzina * visina + sirina * visina);
        }
        
        double volumen() {
            return dolzina * sirina * visina;
        }
        
        double Dolzina() {
            return dolzina;
        }
        
        double Sirina() {
            return sirina;
        }
        
        double Visina() {
            return visina;
        }
};

int main() {
    vector<Kvadar> kvadari;
    int n;
    cout << "Vnesi broj na kvadari:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double d, s, v;
        cout << "Vnesi dolzina, sirina i visina na kvadar " << i+1 << ":" << endl;
        cin >> d >> s >> v;
        Kvadar k(d, s, v);
        kvadari.push_back(k);
    }
    double minPlostina = -1;
    int minIndex = -1;
    for (int i = 0; i < kvadari.size(); i++) {
        double p = kvadari[i].plostina();
        if ((p < minPlostina || minPlostina == -1) && kvadari[i].Dolzina() != kvadari[i].Sirina() && kvadari[i].Sirina() != kvadari[i].Visina() && kvadari[i].Visina() != kvadari[i].Dolzina()) {
            minPlostina = p;
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        cout << "Kvadarot so najmala plostina koj ne e kocka e kvadar " << minIndex+1 << " so plostina " << minPlostina << endl;
    } else {
        cout << "Ne postoi kvadar so najmala plostina koj ne e kocka." << endl;
    }
    return 0;
}
