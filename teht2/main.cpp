#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    int maxNumber;

    cout << "Enter the maximum number for the guessing game: ";
    cin >> maxNumber;

    Game game(maxNumber); // Luodaan Game-olio
    game.play();          // Aloitetaan peli

    return 0;
}
