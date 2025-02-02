#include <iostream>
#include <string>

// Pankkitili-luokka
class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(const std::string& omistaja) : omistaja(omistaja), saldo(0) {
        std::cout << "Pankkitili luotu " << omistaja << ":lle\n";
    }

    virtual bool deposit(double amount) {
        if (amount <= 0) return false;
        saldo += amount;
        std::cout << "Pankkitili: talletus " << amount << " tehty\n";
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || amount > saldo) return false;
        saldo -= amount;
        std::cout << "Pankkitili: nosto " << amount << " tehty\n";
        return true;
    }

    double getBalance() const {
        return saldo;
    }

    virtual ~Pankkitili() {}
};

// Luottotili-luokka
class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(const std::string& omistaja, double luottoRaja)
        : Pankkitili(omistaja), luottoRaja(luottoRaja) {
        std::cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << "\n";
    }

    bool deposit(double amount) override {
        if (amount <= 0) return false;
        saldo += amount;
        if (saldo > 0) saldo = 0;
        std::cout << "Luottotili: talletus " << amount << " tehty\n";
        return true;
    }

    bool withdraw(double amount) override {
        if (amount <= 0 || saldo - amount < -luottoRaja) return false;
        saldo -= amount;
        std::cout << "Luottotili: nosto " << amount << " tehty, luottoa jaljella "
                  << luottoRaja + saldo << "\n";
        return true;
    }

    ~Luottotili() {}
};

// Asiakas-luokka
class Asiakas {
private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& nimi, double luottoRaja)
        : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {
        std::cout << "Asiakkuus luotu " << nimi << "\n";
    }

    void showSaldo() const {
        std::cout << nimi << "\n";
        std::cout << "Kayttotilin saldo " << kayttotili.getBalance() << "\n";
        std::cout << "Luottotilin saldo " << luottotili.getBalance() << "\n";
    }

    bool talletus(double amount) {
        return kayttotili.deposit(amount);
    }

    bool nosto(double amount) {
        return kayttotili.withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili.deposit(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili.withdraw(amount);
    }

    bool tiliSiirto(double amount, Asiakas& vastaanottaja) {
        if (amount <= 0) {
            std::cout << "Virhe: Siirron summa ei voi olla negatiivinen tai nolla.\n";
            return false;
        }

        if (kayttotili.withdraw(amount)) {
            std::cout << "Pankkitili: " << nimi << " siirtaa " << amount
                      << " " << vastaanottaja.getNimi() << ":lle\n";
            if (vastaanottaja.kayttotili.deposit(amount)) {
                std::cout << "Bertta Pankkitili: talletus " << amount << " tehty\n";
                return true;
            } else {
                kayttotili.deposit(amount);
            }
        }

        std::cout << "Siirto epaonnistui.\n";
        return false;
    }

    std::string getNimi() const {
        return nimi;
    }
};

int main() {
    Asiakas asiakas1("Aapeli", 1000.0);
    Asiakas asiakas2("Bertta", 1000.0);

    asiakas1.talletus(250);
    asiakas1.luotonNosto(150);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    asiakas1.tiliSiirto(50, asiakas2);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
