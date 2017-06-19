#include "dealer.h"


       Dealer::Dealer()
        {
                theDeck = new PlayingCardDeck();
        }

        Dealer::~Dealer()
        {
                delete theDeck;
        }

        Dealer::Dealer(int shuffles)
        {
             theDeck  = new PlayingCardDeck(shuffles);
        }
        // BlackJack

       string	Dealer::showHand()
        {
                return theHand.getAllCardCodesXX(); // variation of getallcardcodes from BJH class that returns a string hiding the first card with CC.
        }

        string	Dealer::fullHand()
        {
                return theHand.getAllCardCodes();
        }
        //pcd
        PlayingCard	*	Dealer::dealCard()
        {
                return theDeck->dealCard();
        }

        int	Dealer::cardsLeft()
        {
            return theDeck->getCountRemain(); // fix the PCD method. Now it rest the count to zero so doesnt keep it adding everytime is called.
        }

        void	Dealer::shuffle()
        {
            theDeck->reset();

            theDeck->shuffle(10);
        }
