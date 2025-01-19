#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Konstruktorin toteutus
Game::Game(int maxNumber) : maxNumber(maxNumber), playerGuess(0), randomNumber(0), numOfGuesses(0) {
    srand(static_cast<unsigned int>(time(0))); // Satunnaislukugeneraattorin siemen
    randomNumber = 1 + rand() % maxNumber;     // Arvotaan satunnainen luku väliltä 1 - maxNumber
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

// Destruktorin toteutus
Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

// play()-jäsenfunktion toteutus
void Game::play() {
    cout << "Starting the game!" << endl;
    cout << "Guess the number between 1-" << maxNumber << endl;

    do {
        cout << "Give your guess between 1-" << maxNumber << ": ";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Your guess is too small" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Your guess is too big" << endl;
        } else {
            cout << "Your guess is right = " << playerGuess << endl;
        }
    } while (playerGuess != randomNumber);

    printGameResult();
}

// printGameResult()-jäsenfunktion toteutus
void Game::printGameResult() const {
    cout << "You guessed the right answer = " << randomNumber
         << " with " << numOfGuesses << " guesses" << endl;
}
