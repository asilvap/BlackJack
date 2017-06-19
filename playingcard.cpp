#include "PlayingCard.h"


    PlayingCard::PlayingCard(char myValue, char mySuit)// constructor with parameters.
    {
            switch(myValue)
            {
            case 'A':
                value = myValue;
                break;
            case '2':
                value = myValue;
                break;
            case '3':
                value = myValue;
                break;
            case '4':
                value = myValue;
                break;
            case '5':
                value = myValue;
                break;
            case '6':
                value = myValue;
                break;
            case '7':
                value = myValue;
                break;
            case '8':
                value = myValue;
                break;
            case '9':
                value= myValue;
                break;
            case 'T':
                value = myValue;
                break;
            case 'J':
                value = myValue;
                break;
            case 'Q':
                value = myValue;
                break;
            case 'K':
                value = myValue;
                break;
            case 'Z':
                value = myValue;
                break;
            default:
                value = '0';
            }

        if(value == '0') // if value is 0, suit is set to 0 and return invalid card.
            {
                suit = '0';
            }
        else
            {
              switch(mySuit)
            {
            case 'C':
                suit = mySuit;
                break;
            case 'D':
                suit = mySuit;
                break;
            case 'S':
                suit = mySuit;
                break;
            case 'H':
                suit = mySuit;
                break;
            case 'B':
                suit = mySuit;
                break;
            case 'R':
                suit = mySuit;
                break;
            default:
                suit = '0';
            }
            }
        }

        bool PlayingCard::setCard(char value_p, char suit_p)// checks if card can be added.
        {
        char verifyValue;
        char verifySuit;

        switch(value_p)
            {
            case 'A':
                verifyValue = value_p;
                break;
            case '2':
                verifyValue = value_p;
                break;
            case '3':
                verifyValue = value_p;
                break;
            case '4':
                verifyValue = value_p;
                break;
            case '5':
                verifyValue = value_p;
                break;
            case '6':
                verifyValue = value_p;
                break;
            case '7':
                verifyValue = value_p;
                break;
            case '8':
                verifyValue = value_p;
                break;
            case '9':
                verifyValue = value_p;
                break;
            case 'T':
                verifyValue = value_p;
                break;
            case 'J':
                verifyValue = value_p;
                break;
            case 'Q':
                verifyValue = value_p;
                break;
            case 'K':
                verifyValue = value_p;
                break;
            case 'Z':
                verifyValue = value_p;
            default:
                verifyValue = '0';
            }


                switch(suit_p)
                {
                case 'C':
                verifySuit = suit_p;
                break;
                case 'D':
                verifySuit = suit_p;
                break;
                case 'S':
                verifySuit = suit_p;
                break;
                case 'H':
                verifySuit = suit_p;
                break;
                case 'R':
                verifySuit = suit_p;
                break;
                case 'B':
                verifySuit = suit_p;
                break;
                default:
                verifySuit = '0';
                }

            if (verifySuit == '0' || verifyValue == '0')
            {
                return false;
            }
            else if (verifySuit != 'R' and verifyValue == 'Z')
            {
                return false;
            }
            else if (verifySuit != 'B' and verifyValue == 'Z')
            {
                return false;
            }
            else if (verifySuit == 'R'  and verifyValue != 'Z')
            {
                return false;
            }
            else if (verifySuit == 'B' and verifyValue != 'Z')
            {
                return false;
            }
            else// only if no wrong combination is made, the temporal variables are pass to the class variables.
            {
                suit = verifySuit;
                value = verifyValue;
                return true;
            }
        }


        string PlayingCard::getCardCode()
        {
            code = string() + getValue() + getSuit();

            return code;
        }

        bool PlayingCard::isValid()
        {
            if (suit == '0' and value == '0')
            {
                return false;
            }
            else if (suit != 'R' and value == 'Z')
            {
                return false;
            }
            else if (suit != 'B' and value == 'Z')
            {
                return false;
            }
            else if (suit == 'R'  and value != 'Z')
            {
                return false;
            }
            else if (suit == 'B' and value != 'Z')
            {
                return false;
            }
            else
            {
                return true;
            }

        }




