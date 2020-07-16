//Ian Maze
//COP2000.0M1
//Random Generator Game Program


//Game class declaration


#include<iostream>
#include <cstdlib>
using namespace std;

class Game {
private:
	int balance;
	int rolled;
	char hold;
	bool evenOdd;
	void validateAgain(); //validates the answer if the user wants to roll again(y or n entered)

public:
	bool validateBalance(int); //validates the input balance value from the user
	void RollTheDice(); //constructor to seed the random generator and set the balance to zero
	int setBalance(int); //reads in the starting balance entered from the user
	int roll(int); //call the random generator to return a value between 1 and 6
	bool display(int); //display the results of the roll(odd or even) and the user's balance
	void again(); //determine if the user wants to roll again or quit the game
};

int main() {
	Game RTD;
	int bal, rol = 0, mon = 0;
	char h = 'h';
	bool flip = 0;


	cout << "\n\n---------------------------------- Roll The Dice Game! -----------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------\n\n";

	cout << "Welcome \n\nPlace your bets! ";
	cout << "\n(Minimum bet is : $1)\n";
	cout << "Bets: $";
	cin >> bal;
	while (!RTD.validateBalance(bal)) {
		cout << "\n\nOnly numbers above zero please. Please Try again: $ ";
		cin.clear();	//reset to a good read
		fseek(stdin, 0, SEEK_END);  //flush the input buffer
		cin >> bal;
	}
	cout << "\n\nStarting Balance :$" << bal << endl;
	RTD.roll(bal);
	cout << "\n\nRolling The Dice!!.......";
	cout << "\nYou Rolled A " << RTD.roll(bal) << "!" << endl;

	cout << "\n-------------------------------------------------------------------------------------------";
	cout << "\n-------------------------------------------------------------------------------------------\n\n";
	return 0;
}

// Validate balance input
bool Game::validateBalance(int x) {
	while ((!x) || (x < 0)) {
		return false;
	}
	return true;

};

int Game::roll(int x) {
	for (int count = 0; count < x; count++) {
		int num = x;
		num = balance;
		num = rand() % 6 + 1;
		display(num);
		return num;
	}

};

bool Game::display(int x) {
	if (x % 2 == 0) {
		cout << "\nYou Won! You Get A Dollar! ";
		x += 1;
		return x;
	}
	else {
		cout << "\nYou Lost! You Lose A Dollar! ";
		x -= 1;
		return x;
	}

} 