#include <iostream>
#include <string>
using namespace std;

// Seuraaja-luokka
class Seuraaja {
private:
    string nimi;
    Seuraaja* next;

public:

    Seuraaja(string n) : nimi(n), next(nullptr) {}

    string getNimi() const {
        return nimi;
    }
    void paivitys(const string& viesti) {
        cout << "Seuraaja " << nimi << " sai viestin: " << viesti << endl;
    }

    friend class Notifikaattori;
};

// Notifikaattori-luokka
class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:

    Notifikaattori() : seuraajat(nullptr) {}

    void lisaa(Seuraaja* uusi) {
        uusi->next = seuraajat;
        seuraajat = uusi;
        cout << "Notifikaattori lisasi seuraajan " << uusi->getNimi() << endl;
    }

    void poista(Seuraaja* poistettava) {
        Seuraaja* edellinen = nullptr;
        Seuraaja* nykyinen = seuraajat;

        while (nykyinen != nullptr) {
            if (nykyinen == poistettava) {
                if (edellinen == nullptr) {

                    seuraajat = nykyinen->next;
                } else {
                    edellinen->next = nykyinen->next;
                }
                cout << "Notifikaattori poisti seuraajan " << nykyinen->getNimi() << endl;
                return;
            }
            edellinen = nykyinen;
            nykyinen = nykyinen->next;
        }
    }

    void tulosta() {
        cout << "Notifikaattorin seuraajat:" << endl;
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            cout << "Seuraaja " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }


    void postita(const string& viesti) {
        cout << "Notifikaattori postittaa viestin: " << viesti << endl;
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
};


int main() {
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    n.postita("Tama on viesti 1");
    n.poista(&b);
    n.postita("Tama on viesti 2");

    return 0;
}
