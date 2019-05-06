#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//prototypes
int dealcard();
int dealer();
void showcards();
void acecard1();
void acecard2();
void results();
void SorH();
void again();

int card1, card2, dealerCV, bet;
int playerCV = 0; //cv = card value
int cash = 500; // starting cash

int main()
{
	srand(time(NULL)); //keeping cash
	showcards();
}

int dealcard()
{
	int x;

	x = 1 + rand() % 15; //getting your cards

	if (x >= 12)
		return 10;
	else
		return x;
  
}

//seeing what your cards are + winning or losing game + blackjack
void showcards()
{
	int flag1, flag2; // flags for aces

	playerCV = 0;
	flag1 = 0;
	flag2 = 0;
	card1 = dealcard();
	card2 = dealcard();
	
	cout << "Cash: $" << cash << endl << endl;
// lost all money
	if (cash <= 0){
		cout << "Your bankrupt, GAME OVER!" << endl;
		cash = 500;
		again();
		showcards();
	}
	// winning the game
	if (cash >= 10000){
		cout << "You Win!" << endl;
		cash = 500;
		again();
		showcards();
	}

	if (card1 == 11){
		cout << "Your first card is: " << "ACE";
		flag1 = 1;
	}
	else if (card1 == 1){
		cout << "Your first card is: " << "ACE";
		flag1 = 1;
	}
	else
		cout << "Your first card is: " << card1;
	
	cout << endl << endl << "Place your bet: $";
	cin >> bet;

	if (bet > cash){
		cout << endl;
		cout << "You cannot bet more than you have" << endl;
		again();
		showcards();
	}

	cout << endl;

	if (card2 == 11){
		cout << "Your second card is: " << "ACE" << endl;
		flag2 = 1;
	}
	else if (card2 == 1){
		cout << "Your second card is: " << "ACE" << endl;
		flag2 = 1;
	}
	else
		cout << "Your second card is: " << card2 << endl;

	cout << endl;

	if (flag1 == 1){
		cout << "(Q)First card is 1 | (W)First card is 11" << endl;
		acecard1();
	}

	if (flag2 == 1){
		cout << "(Z)Second card is 1 | (X)Second card is 11" << endl;
		acecard2();
	}
// getting total cv value
	playerCV = card1 + card2;
	
	cout << "Your total card value is " << playerCV << endl;
	
	if (playerCV == 21){
		cout << endl << "BLACKJACK!!!" << endl;
		cash = cash + bet * 5;
		again();
		showcards();
	}
	
	cout << endl;

	SorH();

}
// deciding first card ace is 11 or 1
void acecard1()
{

	char choice;
	cout << endl;

	cin >> choice;

	switch (choice) {
	case 'q':
			card1 = 1;
			break;
	case 'w':
			card1 = 11;
			break;
	}
		
}
// deciding second card ace is 11 or 1
void acecard2()
{

	char choice;
	cout << endl;

	cin >> choice;

	switch (choice) {
	case 'z':
			card2 = 1;
			break;
	case 'x':
			card2 = 11;
			break;
	}
		
}

//getting another card or getting your total card value
void SorH()
{
	char choice;

	cout << "(S)stand | (H)hit" << endl;
	
	cout << endl;
	cin >> choice;
  //getting another card or getting your total card value
	switch (choice) {
	case 'h':
			playerCV = playerCV + dealcard();
			if (playerCV > 21){
			cout << "Your total card value is " << playerCV << endl;
			cout << "You bust" << endl;
			cash = cash - bet;
			again();
			showcards();	
			}
			cout << "Your total card value is " << playerCV << endl << endl;
			SorH();
			break;
	case 's':
			results();
			break;
	}
	
}

void results() //seeing who wins
{
	dealerCV = dealer();
  // card total
	cout << "Your total card value is " << playerCV << endl;
	if (playerCV > 21){
		cout << "You bust" << endl;
		cash = cash - bet;
		again();
		showcards();
		}
	else
		cout << "Dealer's total card value is " << dealerCV << endl << endl;
	if (dealerCV > 21){
		cout << "Dealer busts" << endl;
		cash = cash + bet;
		again();
		showcards();
		}
	else {
		if (playerCV > dealerCV){
		cout << "You win" << endl;
		cash = cash + bet;
		}
	if (playerCV == dealerCV)
		cout << "It's a draw" << endl;
	if (playerCV < dealerCV){
		cout << "You lose" << endl;
		cash = cash - bet;	
		}
	again();
	showcards();
	}
}
//dealer cards
int dealer()
{
	int c1, c2, cv, f1, f2;
//getting their cards
	c1 = dealcard();
	c2 = dealcard();
	//ace choice
	if (c1 == 11)
		f1 = 1;
	
	if (c2 == 11)
		f2 = 1;

	cv = c1 + c2;
	//decided 16 lowest to continue to hit
	while (cv <= 16)
		cv = cv + dealcard();
	
	if (cv > 21 & f1 == 1){
		while (cv <= 16)
		cv = 1 + c2 + dealcard();
	}

	if (cv > 21 & f2 == 1){
		while (cv <= 16)
		cv = c1 + 1 + dealcard();
	}

	return cv; 

}
//playing again
void again()
{
	char key;
	cout << endl;
	cout << "Press R to restart game" << endl;
	cin >> key;
}
