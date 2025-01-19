#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game(int maxNumber);         // Konstruktorin julistus
    ~Game();                     // Destruktorin julistus

    void play();                 // Pelin toteuttava jäsenfunktio
    void printGameResult() const; // Tulostaa pelin tuloksen

private:
    int maxNumber;               // Maksimiarvo arvattavalle luvulle
    int playerGuess;             // Pelaajan nykyinen arvaus
    int randomNumber;            // Satunnaisesti arvottu luku
    int numOfGuesses;            // Arvausten määrä
};

#endif // GAME_H

