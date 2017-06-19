#include "BlackJackhand.h"

    BlackJackHand::BlackJackHand()// constructor without arguments, clear everything.
    {
        for (int i=0; i<HAND; i++)
        {
            card[i] = nullptr;
        }
        contar = clearData;
    }

    BlackJackHand::~BlackJackHand()// destructor, clear hands and counter
    {
        for (int i=0; i<HAND; i++)
        {
           if(card[i]!=nullptr)
            delete card[i];
        }
        contar = clearData;
    }

    BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2) // constructor with two parameters.
    {
        for(int i=0; i<HAND; i++)
        {
            card[i] = nullptr;
        }
        contar = clearData;

        card[contar] = c1;
        contar++;
        card[contar] = c2;
        contar++;
    }

    bool BlackJackHand::addCard(PlayingCard *valor)
    {
        if(getLowScore() > MAXVALUE || isBust() || isFull())
        {
            return false;
        }
        else
        {
            card[contar] = valor;// if correct, add card and add 1 to counter.
            contar++;
            return true;
        }
    }

    int BlackJackHand::getCardCount()// returns counter cards.
    {
        return contar;
    }

    int BlackJackHand::getHighScore() // get high score.
    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        char valueHigh = ' ';
        int valueTotal=0;
        bool once = true;

        for(int i = 0; i<contar; i++)
        {
            valueHigh = card[i]->getValue();
            switch(valueHigh)
                {
                    case 'A':
                        if(once)// Checks that the first A gets 11 points and second one just 1
                        {
                            valueTotal += 11;
                            once = false;
                            break;
                        }
                        else
                        {
                            valueTotal += 1;
                            break;
                        }
                    case '2':
                        valueTotal += 2;
                        break;
                    case '3':
                        valueTotal += 3;
                        break;
                    case '4':
                        valueTotal += 4;
                        break;
                    case '5':
                        valueTotal += 5;
                        break;
                    case '6':
                        valueTotal += 6;
                        break;
                    case '7':
                        valueTotal += 7;
                        break;
                    case '8':
                        valueTotal += 8;
                        break;
                    case '9':
                        valueTotal += 9;
                        break;
                    case 'T':
                        valueTotal += 10;
                        break;
                    case 'J':
                        valueTotal += 10;
                        break;
                    case 'Q':
                        valueTotal += 10;
                        break;
                    case 'K':
                        valueTotal += 10;
                        break;
                    default:
                        return 0;

                }
        }
        return valueTotal;


    }
    int BlackJackHand::getLowScore() // get low score
    {
        char valueHigh = ' ';
        int valueTotal = 0;

        for(int i = 0; i<contar; i++)
        {
            valueHigh = card[i]->getValue(); // gets che character with the value.


            switch(valueHigh)
                {
                    case 'A':
                        valueTotal += 1;
                        break;
                    case '2':
                        valueTotal += 2;
                        break;
                    case '3':
                        valueTotal += 3;
                        break;
                    case '4':
                        valueTotal += 4;
                        break;
                    case '5':
                        valueTotal += 5;
                        break;
                    case '6':
                        valueTotal += 6;
                        break;
                    case '7':
                        valueTotal += 7;
                        break;
                    case '8':
                        valueTotal += 8;
                        break;
                    case '9':
                        valueTotal += 9;
                        break;
                    case 'T':
                        valueTotal += 10;
                        break;
                    case 'J':
                        valueTotal += 10;
                        break;
                    case 'Q':
                        valueTotal += 10;
                        break;
                    case 'K':
                        valueTotal += 10;
                        break;
                    default:
                        return 0;
                }
        }
        return valueTotal;

    }
    void BlackJackHand::clearHand()// cleans data of the hand.
    {
        for ( int i = 0; i < HAND; i++ )
        {
                    delete card[i];
        }
        contar = clearData;
    }

    bool BlackJackHand::isBust() // check is the hand is 21 or over.
    {
        if (getLowScore()> MAXVALUE)
            return true;
        else
            return false;
    }

    bool BlackJackHand::isFull()// checks if it have been draw 5 cards or more
    {
        if(contar>= HAND)
            return true;
        else
            return false;
    }

    bool BlackJackHand::canTakeCard() // checks if more cards can be draw
    {
        if(contar < HAND and getLowScore() < MAXVALUE)
            return true;
        else
            return false;
    }

    string BlackJackHand::getAllCardCodesXX()
    {
        string codigo;

        for ( int i = 0; i < contar ; i++ )
        {
            if (i != 0)
            {
            codigo += card[i]->getCardCode();// accesing Playing card by pointer
            codigo += " "; // space betweenodes.
            }
            else
            {
                codigo += "XX ";
            }


        }
        return codigo;
    }

        string BlackJackHand::getAllCardCodes()
    {
        string codigo;

        for ( int i = 0; i < contar ; i++ )
        {
        codigo += card[i]->getCardCode();// accesing Playing card by pointer
        codigo += " "; // space betweenodes.
        }
        return codigo;
    }



