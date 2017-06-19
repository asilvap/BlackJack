#ifndef DEALER_H
#define DEALER_H

#include <string>
#include <iostream>
#include "player.h"
#include "playingcarddeck.h"
#include "blackjackhand.h"
using namespace std;


class Dealer : public Player
{
    private:

        PlayingCardDeck* theDeck;

    public:
        Dealer();
        ~Dealer();
        Dealer(int shuffles);

        string	showHand() ;
        string	fullHand();

        PlayingCard	*	dealCard();
        int cardsLeft();
        void	shuffle();

};

#endif // DEALER_H
