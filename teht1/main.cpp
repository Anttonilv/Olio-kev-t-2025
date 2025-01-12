#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum);

int main() {
    int maxnum = 40;
    std::cout << "Peli alkaa! Arvaa luku valilta 1-" << maxnum << ".\n";

    int arvaustenMaara = game(maxnum);
    std::cout << "Pelasit pelin loppuun " << arvaustenMaara << " arvauksella.\n";

    return 0;
}

int game(int maxnum) {
    std::srand(std::time(0));
    int satunnainenLuku = std::rand() % maxnum + 1;
    int arvaus = 0;
    int arvaustenLkm = 0;

    while (arvaus != satunnainenLuku) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> arvaus;
        arvaustenLkm++;

        if (arvaus < satunnainenLuku) {
            std::cout << "Luku on suurempi.\n";
        } else if (arvaus > satunnainenLuku) {
            std::cout << "Luku on pienempi.\n";
        } else {
            std::cout << "Oikea vastaus! Luku oli " << satunnainenLuku << ".\n";
        }
    }

    return arvaustenLkm;
}
