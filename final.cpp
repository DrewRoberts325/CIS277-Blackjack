#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;
//prototypes
void bjack(void);
int dealCards(int, string);
void winner(int, int);
void hit(int &);
int Random(int, int);
int main()
{
  char keepPlaying = 'n'; //control
  do 
  {
    bjack(); //keep playing loop?
    cout << "Do you want to play anouther hand (y/n)?";
    cin >> keepPlaying;
  } 
 while(keepPlaying == 'Y' || keepPlaying == 'y');
}
 
void bjack(void){ //the game
 //randomize cards for each play
  srand((int) time(0));
       // deal the cards
         int player = dealCards(2, "Your hand");
         cout << " = " << player << endl;
         int house = dealCards(2, "Dealers Cards: ");
         cout << " = " << house << endl;
        // Ask if human wants a hit and keep hitting
        hit(player);
        cout << endl;
       //Determine if computer takes a hit
       while ((house < player) && (house <= 21) && (player <= 21)) {
         house += dealCards(1, "The Dealers takes a card ");
         cout << endl;
        }
   //show who won....
   winner(player, house);
}

int dealCards(int numberOfCards, string mes){
  int ret_val = 0, val;
  int cards = numberOfCards;
  while(cards--)
    cout << mes;
    {
     // Values from 1 to 14
     val = Random(0,14);
    if( val > 10 ) 
      val = 10;
    if( val == 1 ) 
      val = 11;
      cout << val;
    if(cards)
      cout << ",";
      ret_val+=val;
    }
return ret_val;
}

void hit(int &playerScore)
{
	int cardCount = 0;
	char wantCard = "y" || "n";
	int cardTotal = 0;
	cardTotal = playerScore;
	cout << "Would you like another card?"; 
	while (wantCard == 'Y' || wantCard == 'y')
	{
		if ((cardTotal > 0 ) && (cardTotal < 21))
		cardCount += 1;
		cardTotal += Random(0,10); 
		cout << "Your total is: " << cardTotal;
		cout << "Do you want another card?";
		cin >> wantCard;
		if (wantCard == 'Y' || wantCard == 'y')
			cout << cardTotal + dealCards(1, "You take a card."); // adds humanScore to dealCard()
		else 
			cout << "You decide to stand";
			
		if (cardTotal > 21) 
			cout << "You have gone over 21, You Lose";
	}
}

void winner(int humanScore, int houseScore) { //best cards
  if (humanScore == 21)
			cout << "You have 21. You win!" << endl;
		else if ((humanScore < 21) && (humanScore > houseScore))
			cout << "You win!" << endl;
		else 
			cout << "Dealer wins" << endl;
}

int Random(int lowerLimit, int upperLimit) {
//returns a random number within the given boundary
 return 1 + rand() % (upperLimit - lowerLimit + 1);
}
