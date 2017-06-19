#include "player.h"

      // constructors and destructors
        Player::Player()
        {
                stake = 0;
        }
        Player::Player(int	s)
        {
                stake = s;
        }
        Player::~Player()
        {
                clearHand();
        }

        //methods using BJH Variable
        bool	Player::takeCard(PlayingCard	*c)
        {
                return theHand.addCard(c);
        }
        string	Player::showHand()
        {
                return theHand.getAllCardCodes();
        }
        int	Player::getLowScore()
        {
                return theHand.getLowScore();
        }
        int	Player::getHighScore()
        {
                return theHand.getHighScore();
        }
        int	Player::getScore()
        {
                if(theHand.getHighScore()<21)
                    return theHand.getHighScore();
                else
                    return theHand.getLowScore();
        }
        bool	Player::busted()
        {
                return theHand.isBust();
        }
        bool	Player::wantCard()
        {
                return getScore()<16;
        }
        void	Player::clearHand()
        {
                return theHand.clearHand();
        }

        // methods that belongs to player
        void	Player::setStake(int	stake)
        {
                this->stake=stake;
        }
        int	Player::getStake()
        {
                return stake;
        }
        bool	Player::makeBet(int bet) // makes a bet and save it. if lost it is rest, if win, add it.
        {
                if(bet>stake)
                    return false;
                else
                {
                    this->bet = bet;
                    return true;
                }
        }
        void	Player::won()// rest the bet from the stake
        {
                stake = stake + bet;
        }
        void	Player::lost()
        {
            stake = stake - bet;
        }
