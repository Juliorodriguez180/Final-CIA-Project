// Final CIA Project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =

	{
		{"Dark Souls", "A video game that is extermly hard"},
		{"Overwatch", "Filled with a diverse cast, and is a game studios first atempt at a FPS"},
		{"Call of Duty", "One of the most popular selling FPS games of all times"},
		{"Fallout", "A game centered around nuclear blast and survival"},
		{"Grand Theft Auto", "Steeling Cars, shooting people randomly on the streets, and flyinh hellicopters"}
	};

	enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
	cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels.";

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	//guess the word 
	string theHint = WORDS[choice][HINT];
	//ask for hint 

	string jumble = theWord; //jumbled version of the word 
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index2] = temp;
	}
	cout << "\t\t\tWelcome to the CIA's Enemy Decription Program recruit.\n\n";
	cout << "Since your a new recruit, we've set this program to some easy decriptions, so you can under stand how to use the program.\n";
	cout << "Enter 'hint' for a hint if you get stuck.\n";
	cout << "Enter 'quit' to exit the program.\n";
	cout << "The decription is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "That was not the message.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;

		if (guess == theWord)
		{
			cout << "\nDecription successful!\n";
		}
		cout << "\nGood Job Recruit, and Welcome to the CIA.\n";

		system("pause");

		return 0;
	}
}
		