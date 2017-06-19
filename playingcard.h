#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H
#include <string>
#include <iostream>

using namespace std;

class PlayingCard
{
    private:
        char value;
        char suit;
        string code;

    public:
        PlayingCard() : value('0'), suit('0'),code("") {}; //constructor default
        PlayingCard(char myValue, char mySuit);// constructor with parameters.
        bool setCard(char value_p, char suit_p);
        char getValue(){return value;};
        char getSuit(){return suit;};
        string getCardCode();
        bool isValid();

};

#endif // PLAYINGCARD_H
