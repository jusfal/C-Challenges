#include <iostream>
#include <string>
#include "Tamagochi.h"

using namespace std;

Tamagochi mochi;

bool gameOver = false;
string response; 

//Identifier
void WelcomeText();
void PlayerResponse();

void AskQuestion();

int main()
{
	WelcomeText();
	while (!gameOver)
	{
		AskQuestion();
	}
}

void WelcomeText()
{
	cout << "Welcome To Tamagochi!" << endl;
}

void AskQuestion()
{
	cout << "Type Play/Talk/Eat to interact with your Tamagochi" << endl;
	cin >> response;
	PlayerResponse();
}

void PlayerResponse()
{
	if (response == "play" || response ==  "Play" || response == "PLAY")
	{
		mochi.Play();
	}
	else if (response == "talk" || response ==  "Talk" || response ==  "TALK")
	{
		mochi.Talk();
	}
	else if (response == "eat" || response == "Eat" || response == "EAT")
	{
		mochi.Eat();
	}
}