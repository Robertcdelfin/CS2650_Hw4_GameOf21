#include "Die.h"
// Implememtation file for the Die class from the book
#include <cstdlib> // For rand and srand
#include <ctime> // For the time function
#include <iostream>
using namespace std;

 //*******************************************************
 // The constructor accepts an argument for the number *
 // of sides for the die, and performs a roll. *
 //*******************************************************
 Die::Die(int numSides)
 { 	
	 // Seed the random number generator.
	 srand(time(0));
	 // Set the number of sides.	
	 sides = numSides;	
	 // Perform an initial roll.	
	 roll();
 }
 //*******************************************************
 // The roll member function simulates the rolling of *
 // the die. *
 //*******************************************************
 void Die::roll()
 {
	 // Constant for the minimum die value
	 const int MIN_VALUE = 1; // Minimum die vale
	// Get a random value for the die
	 value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}
 //*******************************************************
 // The getSides member function returns the number of *
 // for this die. *
 //*******************************************************
 
int Die::getSides() 
{
	return sides;	 
}

//********************************************************
// The getValue member function returns the die's value.*
//********************************************************
 
int Die::getValue()
{
	 return value;
}

int main() {
	//sets the random function
	//Computer
	Die dice1 (6);
	//User die
	Die dice2 (6);

	//player value
	int playerValue = 0;
	//computer value
	int computerValue = 0;

	//loop to keep the game going
	while (playerValue <= 21) {

		int userInput;

		cout << "Do you want to roll? (Enter 1 for yes 0 for no): ";
		cin >> userInput;

		//when the user wants out of the game
		if (userInput != 1) break;
		dice1.roll();
		dice2.roll();
		//Gets the new total for computer
		computerValue += dice1.getValue() + dice2.getValue();
		//Gets the new total for player
		dice1.roll();
		dice2.roll();
		playerValue += dice1.getValue() + dice2.getValue();

		cout << "Your current total is " << playerValue << "\n";
	}

	cout << "User roll value: " << playerValue << "\n";
	cout << "Computer roll value: " << computerValue << "\n";

	//If player is larger than computer
	if (playerValue <= 21 && playerValue > computerValue && computerValue <= 21) {
		cout << "You win\n";
	}
	//if player is less than computer
	else if (playerValue <= 21 && playerValue < computerValue && computerValue <= 21) {
		cout << "You lost \n";
	}
	//if player is tied with the computer
	else if (playerValue <= 21 && playerValue == computerValue) {
		cout << "Match is a tie\n";
	}
	else {
		cout << "You bust. Your card value is over 21\n";
	}
	return 0;
}