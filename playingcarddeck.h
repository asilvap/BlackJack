#ifndef PLAYINGCARDDECK_H
#define PLAYINGCARDDECK_H
#include "playingcard.h"
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>

using namespace std;
class PlayingCardDeck
{
    private:
        static const int DECK_SIZE  = 52;
        static const int NUM_SUITS= 4;
        static const int SUIT_SIZE = 13;
        PlayingCard *deck[DECK_SIZE];
        char values[SUIT_SIZE] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
        char suits[NUM_SUITS] = {'C','H','D','S'};
        int contar = DECK_SIZE-1;
        int countDealt =0 ;
        int countRemaining = 0;

    public:
        PlayingCardDeck();
        PlayingCardDeck(int	numShuffles);
        ~PlayingCardDeck();
        PlayingCard*	dealCard();
        bool	shuffle(int numShuffles);
        void	reset();
        string getAllCardCodes();
        int getCountUsed();
        int getCountRemain();



};

#endif // PLAYINGCARDDECK_H
