#ifndef PLAYER_H
#define PLAYER_H

#include "blackjackhand.h"
#include <string>
#include <iostream>

using namespace std;

class Player // parent
{
    protected:

        BlackJackHand theHand;
        int stake;
        int  bet;

    public:

        // constructors and destructors
        Player();
        Player(int	s);
        ~Player();

        //methods using BJH Variable
        bool	takeCard(PlayingCard	*c);
        string showHand();
        int	getLowScore();
        int	getHighScore();
        int	getScore();
        bool	busted();
        bool	wantCard();
        void	clearHand();

        // methods that belongs to player
        void	setStake(int	stake);
        int	getStake();
        bool	makeBet(int	bet);
        void	won();
        void	lost();

};

#endif // PLAYER_H
