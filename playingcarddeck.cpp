#include "playingcarddeck.h"





       PlayingCardDeck::PlayingCardDeck()
       {
            for(int i = 0; i < NUM_SUITS; i++) // creates an array of dynamic pointer
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                    {
                    deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
                    }
                }
                contar = DECK_SIZE-1; // reset counters to zero.
                countDealt = 0;
                countRemaining = 0;
       }


       PlayingCardDeck:: PlayingCardDeck(int numShuffles)
        {
            srand(time(NULL)); // random generator
            int random; // save the random number
            bool correcto;
            int numero = 0;

            do // shuffles the array numShuffles times
            {

                for(int i = 0; i < DECK_SIZE; i++) //delete deck and prepare it for next shuffle. It shuffles numShuffles times. // fix!
                    {
                    deck[i] = nullptr;
                    }

                  for(int i = 0; i < NUM_SUITS; i++)
                    {
                        for(int j = 0; j < SUIT_SIZE; j++)
                        {

                        do{

                            correcto = true;
                            random  = rand()%DECK_SIZE;
                            if(deck[random] == nullptr) // if doesnt happens, generates another random number and tries again
                                {
                                deck[random] =   new PlayingCard(values[j], suits[i]);// create different cards.
                                correcto = false;
                                }

                            }while(correcto);

                        }
                    }

                    numero++;

            }while(numero == numShuffles);

                contar = DECK_SIZE-1; // reset values to zero.
                countDealt = 0;
                countRemaining = 0;

        }

        PlayingCardDeck::~PlayingCardDeck()
        {
                bool dealt = false;
                for(int i = 0; i < DECK_SIZE; i++) // checks if it has been dealt already, if it does, does not delete them.
                {
                    if(deck[i]==nullptr)
                        dealt = true;
                }

                if(dealt == false)
                {
                     for(int i = 0; i < DECK_SIZE; i++)
                    {
                        delete deck [i];
                    }
                }
        }

       PlayingCard* PlayingCardDeck::dealCard()
        {
                    PlayingCard * carta;
                    if(deck[contar]!=NULL)   // starts from the last card, it adds the last one to the array carta and delete it from the deck.
                    {
                    carta = deck[contar];
                    deck[contar] = NULL;
                    contar--; // starts from the last card (51 position )and goes backwards till 0
                    }
                    else // if there is no more cards, return null.
                    {
                        return NULL;
                    }
                    return carta;
        }


        bool	PlayingCardDeck::shuffle(int numShuffles) // delete all the array as long as the cards have been not deal. if there if one null means it has been dealt.
        {
            srand(time(0));

            for(int i = 0; i < NUM_SUITS; i++)
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                        {
                        if(deck[i * SUIT_SIZE + j]==nullptr)
                            {
                        return false; // return false if one of the arrays is null, sinceit would mean the deck have been dealt.
                            }
                        }
                }

            int random;
            bool correcto;
            int numero = 0;

            do // set up the cards randomly
            {
                for(int i = 0; i < DECK_SIZE; i++)
                        {
                        deck[i] = nullptr;
                        }

                for(int i = 0; i < NUM_SUITS; i++)
                    {
                        for(int j = 0; j < SUIT_SIZE; j++)
                        {

                        do{
                            correcto = true;
                            random  = rand()%DECK_SIZE;
                            if(deck[random] == nullptr)
                                {
                                deck[random] =   new PlayingCard(values[j], suits[i]);
                                correcto = false;
                                }
                            }while(correcto);
                        }
                    }
                    numero++;

            }while(numero == numShuffles);
            return true;

        }

        void PlayingCardDeck::reset() // delete the deck and create another one unshuffled.
        {
            for(int i = 0; i < DECK_SIZE; i++)
                 delete deck[i];

            for(int i = 0; i < NUM_SUITS; i++)
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                    {
                    deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
                    }
                }


                contar = DECK_SIZE-1;
                countDealt = 0;
                countRemaining = 0;

        }

        string PlayingCardDeck::getAllCardCodes()  // add code for the cards.
        {
            string codeTogether = "";

             for(int i = 0; i < NUM_SUITS; i++)
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                    {

                        if(deck[i * SUIT_SIZE + j]!=nullptr)
                        {

                            codeTogether = codeTogether + deck[i * SUIT_SIZE + j] ->getCardCode() + " " ;
                        }
                        else
                            return codeTogether;

                    }
                    codeTogether = codeTogether + "\n";
                }

                return codeTogether;
        }

        int PlayingCardDeck::getCountUsed()  // checks how many null there are so we can know the number of cards dealt.
        {


            for(int i = 0; i < NUM_SUITS; i++)
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                    {
                     if(deck[i * SUIT_SIZE + j]  == nullptr)
                        countDealt++;
                    }
                }

                return countDealt;

        }
        int PlayingCardDeck::getCountRemain() // counts how many cards are not null to know the cards left.
        {

            countRemaining = 0;// fix, now the count goes back to zero everytime is called.

            for(int i = 0; i < NUM_SUITS; i++)
                {
                    for(int j = 0; j < SUIT_SIZE; j++)
                    {
                     if(deck[i * SUIT_SIZE + j]  != nullptr)
                        countRemaining++;
                    }
                }

                return countRemaining;
        }


