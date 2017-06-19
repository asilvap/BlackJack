#ifndef BLACKJACKHAND_H
#define BLACKJACKHAND_H

#include "PlayingCard.h"
#include <string>
#include <iostream>
using namespace std;

class BlackJackHand
{
    private:

        const static int HAND = 5; // max number of cards
        PlayingCard *card[HAND];// array of pointers
        int contar = 0; // count cards
        int clearData = 0; // clear where pointers point and clear count card.
        const static int MAXVALUE = 21;

    public:

        BlackJackHand();
        BlackJackHand(PlayingCard *c1, PlayingCard *c2);
        ~BlackJackHand();
        bool addCard(PlayingCard *card);
        int getCardCount();
        int getHighScore();
        int getLowScore();
        void clearHand();
        bool isBust();
        bool isFull();
        bool canTakeCard();
        string getAllCardCodes();
        int getCount() {return contar;};
        string getAllCardCodesXX() ;// variation of getallcardcodes that return a string with a XX;
};

#endif // BLACKJACKHAND_H
