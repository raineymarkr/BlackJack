#include <iostream>
#include <string>
#include <vector>

//create suites and names
    enum class CardSuites
    {
        Hearts,
        Diamonds,
        Clubs,
        Spades
    };

    enum class CardNames
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Jack,
        Queen,
        King
    };

    //create card
    struct Card
    {
        CardNames name;
        CardSuites suite;
        int value;
        bool used = false;
        bool faceup;

        //print value as string
        std::string PrintName()
        {
            std::string n;
            if(name == CardNames::Jack)
            {
              n = "J";
            }
            else
            if(name == CardNames::Queen)
            {
              n = "Q";
            }
            else
            if(name == CardNames::King)
            {
              n = "K";
            }
            else
            if(name == CardNames::Ace)
            {
              n = "A";
            }
            else
            {
            n = std::to_string(value);
            }

            return n;
        }

        //print suite as symbol
        std::string PrintSuite()
        {
            std::string s;
            if (suite == CardSuites::Hearts)
            {
                s = "♥";
            }
            else
            if (suite == CardSuites::Diamonds)
            {
                s = "♦";
            }
            else
            if (suite == CardSuites::Clubs)
            {
                s = "♣";
            }
            else
            if (suite == CardSuites::Spades)
            {
                s = "♠";
            }
            return s;
        }

    };

    //create the deck
    struct Deck
    {
        //deck of cards
        Card arrCards[52];

        //player and opponent hands
        std::vector<Card> drawnPlayer;
        std::vector<Card> drawnOpp;

        //set trackers to zero
        int pdrawn = 0;
        int odrawn = 0;
        int ptotal = 0;
        int ototal = 0;
        bool gend = false;
        bool phold = false;

        //initiate the 52 cards, 13 of each suite
        void SetupCards()
        {
          for (int col = (int)CardSuites::Hearts; col <= (int)CardSuites::Spades; col++)
          {
              for (int row = (int)CardNames::Ace; row <= (int)CardNames::King; row++)
              {
                  Card c;
                  c.suite = (CardSuites)col;
                  c.name = (CardNames)row;

                  if (c.name == CardNames::Jack)
                  {
                      c.value = 10;
                  }
                  else
                    if (c.name == CardNames::Queen)
                  {
                      c.value = 10;
                  }
                  else
                    if (c.name == CardNames::King)
                  {
                      c.value = 10;
                  }
                  else
                  {
                      c.value = (int)c.name;
                  }
                  int index = (13 * col) + row - 1;
                  arrCards[index] = c;
              }
          }
        }

        void nodrawP()
        {
            phold = true;
        }

        //Draw a card for the player
        void drawP()
        {
            Card c;
            int randn;

            //set random number
            randn = (rand() % (52)) +1;

            //check if multiple of 13, if so minus one
            if (randn%13 == 12)
            {
                randn--;
            }

            //set card c from deck at randn location
            c = arrCards[randn];

            //check if card has been drawn, if so redraw. if not, add to table.
            if (c.used == false)
                {
                c.used = true;
                drawnPlayer.push_back(c);
                pdrawn ++;
                }
            else
                {
                drawP();
                }
        }

        //draw a card for the opponent
        void drawO()
        {
            Card c;
            int randn;

            //set random number
            randn = (rand() % (52)) +1;

            //check if multiple of 13, if so minus one
            if (randn%13 == 12)
            {
                randn--;
            }

            //set card c from deck at randn location
            c = arrCards[randn];

            //check if card has been drawn, if so redraw. if not, add to table.
            if (c.used == false)
                {
                c.used = true;
                drawnOpp.push_back(c);
                odrawn ++;
                }
            else
                {
                    drawCardsO();
                }
        }

        //Deal hands
        void drawCardsP()
        {
            for (int row = 1; row <= 2; row++)
            {
            drawP();
            }
        }

        void drawCardsO()
        {
            for (int row = 1; row <= 2; row++)
            {
            drawO();
            }
        }

        //Print facing cards for opponent
         void PrintASCIIFO()
        {
            std::string lines[9];

            std::string top ="┌─────────┐";
            std::string top2a= "|";
            std::string top2b = "        │";
            std::string middle = "│         │";
            std::string middlea = "│   ";
            std::string middleb = "     │";
            std::string bottom2a= "│        ";
            std::string bottom2b = "|";
            std::string bottom = "└─────────┘";
            if (odrawn == 2)
            {
                for (int row = 1; row <= 1; row++)
                {


                    lines[0] = top + " " + top;
                    lines[1] = top2a + drawnOpp[0].PrintName() + top2b  + " " + top2a + drawnOpp[1].PrintName() + top2b;
                    lines[2] = middle + " " + middle;
                    lines[3] = middle + " " + middle;
                    lines[4] = middlea + drawnOpp[0].PrintSuite() + middleb +" " + middlea + drawnOpp[1].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle;
                    lines[6] = middle + " " + middle;
                    lines[7] = bottom2a + drawnOpp[0].PrintName() + bottom2b + " " + bottom2a + drawnOpp[1].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom;

                    for (int i = 0; i <= 8; i++)
                    {
                    std::cout << lines[i] << std::endl;
                    }
                }
            } else if(odrawn == 3)
            {
              for (int row = 1; row <= 1; row++)
                {


                    lines[0] = top + " " + top + " " + top;
                    lines[1] = top2a + drawnOpp[0].PrintName() + top2b  + " " + top2a + drawnOpp[1].PrintName() + top2b+ " " + top2a + drawnOpp[2].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnOpp[0].PrintSuite() + middleb +" " + middlea + drawnOpp[1].PrintSuite() + middleb +" " + middlea + drawnOpp[2].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnOpp[0].PrintName() + bottom2b + " " + bottom2a + drawnOpp[1].PrintName() + bottom2b + " " + bottom2a + drawnOpp[2].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom;

                    for (int i = 0; i <= 8; i++)
                    {
                    std::cout << lines[i] << std::endl;
                    }
                }
            } else if(odrawn == 4)
            {
              for (int row = 1; row <= 1; row++)
                {


                    lines[0] = top + " " + top + " " + top + " " + top;
                    lines[1] = top2a + drawnOpp[0].PrintName() + top2b  + " " + top2a + drawnOpp[1].PrintName() + top2b+ " " + top2a + drawnOpp[2].PrintName() + top2b+ " " + top2a + drawnOpp[3].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnOpp[0].PrintSuite() + middleb +" " + middlea + drawnOpp[1].PrintSuite() + middleb +" " + middlea + drawnOpp[2].PrintSuite() + middleb +" " + middlea + drawnOpp[3].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnOpp[0].PrintName() + bottom2b + " " + bottom2a + drawnOpp[1].PrintName() + bottom2b + " " + bottom2a + drawnOpp[2].PrintName() + bottom2b + " " + bottom2a + drawnOpp[3].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom + " " + bottom;

                    for (int i = 0; i <= 8; i++)
                    {
                    std::cout << lines[i] << std::endl;
                    }
                }
            } else if(odrawn == 5)
            {
              for (int row = 1; row <= 1; row++)
                {


                    lines[0] = top + " " + top + " " + top + " " + top + " " + top;
                    lines[1] = top2a + drawnOpp[0].PrintName() + top2b  + " " + top2a + drawnOpp[1].PrintName() + top2b+ " " + top2a + drawnOpp[2].PrintName() + top2b+ " " + top2a + drawnOpp[3].PrintName() + top2b + " " + top2a + drawnOpp[4].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnOpp[0].PrintSuite() + middleb +" " + middlea + drawnOpp[1].PrintSuite() + middleb +" " + middlea + drawnOpp[2].PrintSuite() + middleb +" " + middlea + drawnOpp[3].PrintSuite() + middleb +" " + middlea + drawnOpp[4].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnOpp[0].PrintName() + bottom2b + " " + bottom2a + drawnOpp[1].PrintName() + bottom2b + " " + bottom2a + drawnOpp[2].PrintName() + bottom2b + " " + bottom2a + drawnOpp[3].PrintName() + bottom2b + " " + bottom2a + drawnOpp[4].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom + " " + bottom + " " + bottom;

                    for (int i = 0; i <= 8; i++)
                    {
                    std::cout << lines[i] << std::endl;
                    }
                }
            }

        }
        //Print facing cards for player
         void PrintASCIIFP()
        {
            std::string lines[9];

            std::string top ="┌─────────┐";
            std::string top2a= "|";
            std::string top2b = "        │";
            std::string middle = "│         │";
            std::string middlea = "│   ";
            std::string middleb = "     │";
            std::string bottom2a= "│        ";
            std::string bottom2b = "|";
            std::string bottom = "└─────────┘";

            if(pdrawn == 2)
            {
                for (int row = 1; row <= 1; row++)
            {

                    lines[0] = top + " " + top;
                    lines[1] = top2a + drawnPlayer[0].PrintName() + top2b  + " " + top2a + drawnPlayer[1].PrintName() + top2b;
                    lines[2] = middle + " " + middle;
                    lines[3] = middle + " " + middle;
                    lines[4] = middlea + drawnPlayer[0].PrintSuite() + middleb +" " + middlea + drawnPlayer[1].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle;
                    lines[6] = middle + " " + middle;
                    lines[7] = bottom2a + drawnPlayer[0].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
            }
            } else
            if(pdrawn == 3)
            {
                for (int row = 1; row <= 1; row++)
            {

                    lines[0] = top + " " + top + " " + top;
                    lines[1] = top2a + drawnPlayer[0].PrintName() + top2b  + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnPlayer[0].PrintSuite() + middleb +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnPlayer[0].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
            }
            }else
            if(pdrawn == 4)
            {
                for (int row = 1; row <= 1; row++)
            {

                    lines[0] = top + " " + top + " " + top + " " + top;
                    lines[1] = top2a + drawnPlayer[0].PrintName() + top2b  + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b  + " " + top2a + drawnPlayer[3].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnPlayer[0].PrintSuite() + middleb +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb +" " + middlea + drawnPlayer[3].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnPlayer[0].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[3].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom + " " + bottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
            }
            } else if(pdrawn == 5)
            {
                for (int row = 1; row <= 1; row++)
            {

                    lines[0] = top + " " + top + " " + top + " " + top + " " + top;
                    lines[1] = top2a + drawnPlayer[0].PrintName() + top2b  + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b  + " " + top2a + drawnPlayer[3].PrintName() + top2b  + " " + top2a + drawnPlayer[4].PrintName() + top2b;
                    lines[2] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[3] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[4] = middlea + drawnPlayer[0].PrintSuite() + middleb +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb +" " + middlea + drawnPlayer[3].PrintSuite() + middleb +" " + middlea + drawnPlayer[4].PrintSuite() + middleb;
                    lines[5] =  middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[6] = middle + " " + middle + " " + middle + " " + middle + " " + middle;
                    lines[7] = bottom2a + drawnPlayer[0].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[3].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[4].PrintName() + bottom2b;
                    lines[8] = bottom  + " " + bottom + " " + bottom + " " + bottom + " " + bottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
            }
            }

        }


        //Print back cards
                void PrintASCIIB()
        {
            std::string blines[9];

            std::string btop = "┌─────────┐";
            std::string bmid = "|*********|";
            std::string bbottom = "└─────────┘";

            if(odrawn == 2)
            {
                blines[0] = btop + " " + btop;
                blines[1] = bmid + " " + bmid;
                blines[2] = bmid + " " + bmid;
                blines[3] = bmid + " " + bmid;
                blines[4] = bmid + " " + bmid;
                blines[5] = bmid + " " + bmid;
                blines[6] = bmid + " " + bmid;
                blines[7] = bmid + " " + bmid;
                blines[8] = bbottom  + " " + bbottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << blines[i] << std::endl;
                }
            } else
            if(odrawn == 3)
            {
                blines[0] = btop + " " + btop + " " + btop;
                blines[1] = bmid + " " + bmid + " " + bmid;
                blines[2] = bmid + " " + bmid + " " + bmid;
                blines[3] = bmid + " " + bmid + " " + bmid;
                blines[4] = bmid + " " + bmid + " " + bmid;
                blines[5] = bmid + " " + bmid + " " + bmid;
                blines[6] = bmid + " " + bmid + " " + bmid;
                blines[7] = bmid + " " + bmid + " " + bmid;
                blines[8] = bbottom  + " " + bbottom + " " + bbottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << blines[i] << std::endl;
                }
            }else
            if(odrawn == 4)
            {
                blines[0] = btop + " " + btop + " " + btop + " " + btop;
                blines[1] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[2] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[3] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[4] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[5] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[6] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[7] = bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[8] = bbottom  + " " + bbottom + " " + bbottom + " " + bbottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << blines[i] << std::endl;
                }
            }else
            if(odrawn == 5)
            {
                blines[0] = btop + " " + btop + " " + btop + " " + btop + " " + btop;
                blines[1] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[2] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[3] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[4] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[5] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[6] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[7] = bmid + " " + bmid + " " + bmid + " " + bmid + " " + bmid;
                blines[8] = bbottom  + " " + bbottom + " " + bbottom + " " + bbottom + " " + bbottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << blines[i] << std::endl;
                }
            }

        }

        //Print mixed cards for player
        void PrintASCIIM()
        {
            std::string lines[9];
            std::string blines[9];

            std::string btop = "┌─────────┐";
            std::string bmid = "|*********|";
            std::string bbottom = "└─────────┘";

            std::string top ="┌─────────┐";
            std::string top2a= "|";
            std::string top2b = "        │";
            std::string middle = "│         │";
            std::string middlea = "│   ";
            std::string middleb = "     │";
            std::string bottom2a= "│        ";
            std::string bottom2b = "|";
            std::string bottom = "└─────────┘";

            if (pdrawn == 2)
            {
                for (int row = 1; row <= 1; row++)
                {
                    lines[0] = btop + " " + top;
                    lines[1] = bmid  + " " + top2a + drawnPlayer[1].PrintName() + top2b;
                    lines[2] = bmid + " " + middle;
                    lines[3] = bmid + " " + middle;
                    lines[4] = bmid +" " + middlea + drawnPlayer[1].PrintSuite() + middleb;
                    lines[5] = bmid + " " + middle;
                    lines[6] = bmid + " " + middle;
                    lines[7] = bmid + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b;
                    lines[8] = bbottom  + " " + bottom;

                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
                }
            } else

            if (pdrawn == 3)
            {
                for (int row = 1; row <= 1; row++)
                {
                    if (row == 1)
                    {
                        lines[0] = top + " " + top + " " + top;
                        lines[1] = bmid + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b;
                        lines[2] = bmid + " " + middle + " " + middle;
                        lines[3] = bmid + " " + middle + " " + middle;
                        lines[4] = bmid +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb;
                        lines[5] = bmid + " " + middle + " " + middle;
                        lines[6] = bmid + " " + middle + " " + middle;
                        lines[7] = bmid + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b;
                        lines[8] = bbottom  + " " + bottom  + " " + bottom;
                    }
                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
                }

            }else
            if (pdrawn == 4)
            {
                for (int row = 1; row <= 1; row++)
                {
                    if (row == 1)
                    {
                        lines[0] = top + " " + top + " " + top  + " " + top;
                        lines[1] = bmid + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b + " " + top2a + drawnPlayer[3].PrintName() + top2b;
                        lines[2] = bmid + " " + middle + " " + middle + " " + middle;
                        lines[3] = bmid + " " + middle + " " + middle + " " + middle;
                        lines[4] = bmid +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb +" " + middlea + drawnPlayer[3].PrintSuite() + middleb;
                        lines[5] = bmid + " " + middle + " " + middle + " " + middle;
                        lines[6] = bmid + " " + middle + " " + middle + " " + middle;
                        lines[7] = bmid + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[3].PrintName() + bottom2b;
                        lines[8] = bbottom  + " " + bottom  + " " + bottom + " " + bottom;
                    }
                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
                }

            } else if (pdrawn == 5)
            {
                for (int row = 1; row <= 1; row++)
                {
                    if (row == 1)
                    {
                        lines[0] = top + " " + top + " " + top  + " " + top + " " + top;
                        lines[1] = bmid + " " + top2a + drawnPlayer[1].PrintName() + top2b  + " " + top2a + drawnPlayer[2].PrintName() + top2b + " " + top2a + drawnPlayer[3].PrintName() + top2b + " " + top2a + drawnPlayer[4].PrintName() + top2b;
                        lines[2] = bmid + " " + middle + " " + middle + " " + middle + " " + middle;
                        lines[3] = bmid + " " + middle + " " + middle + " " + middle + " " + middle;
                        lines[4] = bmid +" " + middlea + drawnPlayer[1].PrintSuite() + middleb +" " + middlea + drawnPlayer[2].PrintSuite() + middleb +" " + middlea + drawnPlayer[3].PrintSuite() + middleb +" " + middlea + drawnPlayer[4].PrintSuite() + middleb;
                        lines[5] = bmid + " " + middle + " " + middle + " " + middle + " " + middle;
                        lines[6] = bmid + " " + middle + " " + middle + " " + middle + " " + middle;
                        lines[7] = bmid + " " + bottom2a + drawnPlayer[1].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[2].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[3].PrintName() + bottom2b + " " + bottom2a + drawnPlayer[4].PrintName() + bottom2b;
                        lines[8] = bbottom  + " " + bottom  + " " + bottom + " " + bottom + " " + bottom;
                    }
                for (int i = 0; i <= 8; i++)
                {
                std::cout << lines[i] << std::endl;
                }
                }

            }


            }

    void CalcPoints()
    {
        ResetPoints();

        for(int i = 1; i <= drawnPlayer.size(); i++)
        {
         ptotal += drawnPlayer[i-1].value;
        }

        for(int i = 1; i <= drawnOpp.size(); i++)
        {
         ototal += drawnOpp[i-1].value;
        }
    }

    void ResetPoints()
    {
        ptotal = 0;
        ototal = 0;
    }

    //evaluate win conditions, starting with player and ending with opponent
    void CheckWin()
    {
        ResetPoints();
        CalcPoints();


        if(ptotal > 21)
        {
         PrintASCIIFO();
         PrintASCIIFP();
         std::cout << "You bust with " << ptotal <<".\nYou Lose!\n";
         gend = true;

        } else
        if(ptotal == 21)
        {
         PrintASCIIFO();
         PrintASCIIFP();
         std::cout << "You scored " << ptotal <<".\nYou win!\n";
         gend = true;
        } else
        {
         if(ototal > 21)
         {
            PrintASCIIFO();
            PrintASCIIFP();
             std::cout << "Opponent busts with " <<ototal << "\nYou win!\n";
             gend = true;
         } else
         if(ototal == 21)
         {
             PrintASCIIFO();
             PrintASCIIFP();
             std::cout << "Opponent scores 21!\nYou lose!\n"<<std::endl;
             gend = true;
         } else
         if (phold)
         {
            PrintASCIIFO();
            PrintASCIIFP();
            if(ptotal > ototal)
            {
                std::cout << "Player scores " << ptotal <<". Computer scores " << ototal << ".\nYou Win!";
                gend=true;
            } else
            {
                std::cout << "Player scores " << ptotal <<". Computer scores " << ototal << ".\nYou Lose!";
                gend=true;
            }
         }else
         {
             ResetPoints();
             TakeTurn();
         }

     }

    }

    void CheckBlackJack()
    {
        //check player blackjack
         if (drawnPlayer[0].value == 10)
         {
            if (drawnPlayer[1].value == 1)
            {
                PrintASCIIFO();
                PrintASCIIFP();
                std::cout << "You drew 21! You win!" << std::endl;
            }
         } else if (drawnPlayer[0].value == 1)
         {
             if (drawnPlayer[1].value == 10)
         {
            PrintASCIIFO();
            PrintASCIIFP();
            std::cout << "You drew 21! You win!" << std::endl;
         }
        }


        //check computer blackjack
         if (drawnOpp[0].value == 10)
         {
            if (drawnOpp[1].value == 1)
            {
                PrintASCIIFO();
                PrintASCIIFP();
                std::cout << "Computer drew 21! You lose!" << std::endl;
            }
         } else if (drawnOpp[0].value == 1)
         {
             if (drawnOpp[1].value == 10)
            {
            PrintASCIIFO();
            PrintASCIIFP();
            std::cout << "Computer drew 21! You lose!" << std::endl;
            }
        }
    }

    //Opponent AI
    void OppTurn()
    {
        int randn;
        ResetPoints();

        CalcPoints();

        if(ototal < 15)
        {
            drawO();
        } else if (ototal >= 15 && ototal <= 17)
        {
            randn = rand() % (100) +1;
            if (randn >= 50)
            {
                ototal = 0;
                drawO();
            } else if (ototal >= 18 && ototal <= 12)
        {
            randn = rand() % (100) +1;
            if (randn >= 75)
            {
                ototal = 0;
                drawO();
            } else
            ototal = 0;
            if(phold)
            {
                CheckWin();
            }
        }
        }
    }

    //Player turn
    void TakeTurn()
    {
        int input;


        std::cout << "Press 1 to flip first card, Press 2 to draw, Press 3 to hold." << std::endl;
        std::cin >> input;

        if(input == 1)
        {
            ResetPoints();
            PrintASCIIB();
            PrintASCIIFP();
            TakeTurn();
        } else
        if(input == 2)
        {
            ResetPoints();
            drawP();
            OppTurn();
            PrintASCIIB();
            PrintASCIIM();
            CheckWin();
            if (!gend)
            {
                TakeTurn();
            }

        } else
        if(input == 3)
        {
            ResetPoints();
            nodrawP();
            OppTurn();
            PrintASCIIB();
            PrintASCIIM();
            CheckWin();

            if (!gend)
            {
                TakeTurn();
            }

        }
    }

    };


int main()
{
    srand(time(0));
    Deck deck;

    deck.SetupCards();

    deck.drawCardsP();
    deck.drawCardsO();

    deck.PrintASCIIB();
    deck.PrintASCIIM();
    deck.CheckBlackJack();
    deck.TakeTurn();


return 0;
}
