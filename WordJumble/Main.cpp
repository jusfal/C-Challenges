#include <iostream>
#include <array>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string guess;
	bool wrongChoice = true;
	const int MAX_WORDS = 5;
	array<string, MAX_WORDS> word{ "wolf", "headphones","cake", "watermelon", "quick" };
	//array<array<char, 4> ,MAX_WORDS> words 
	//{ {
	//	/*{"q", "u", "i","c", "k"},
	//	{"h", "e", "a","d", "p","h","o","n","e"},
	//	{"w", "a", "t","e", "r","m","e","l","o","n"},*/
	//	{'w','o','l','f'},
	//	{'c', 'a', 'k','e'},
	//	{'s', 'h', 'o','e'},
	//	
	//} };
	srand(time(0));
	/*int randomWord = rand() % MAX_WORDS;
	int wordLength = words[randomWord].size();*/

	string randomWord = word[rand() % MAX_WORDS];
	string jumble = randomWord;
	int wordLength = jumble.size();



	for (int i = 0; i < wordLength; i++)
	{
		int letter1 = rand() % wordLength; //Index
		int letter2 = rand() % wordLength; //Index
		char tempLetter;

		tempLetter = jumble[letter1];
		jumble[letter1] = jumble[letter2];
		jumble[letter2] = tempLetter;
		/*tempLetter = words[randomWord][letter1];
		words[randomWord][letter1] = words[randomWord][letter2];
		words[randomWord][letter2] = tempLetter;*/
	}
	//string jumbledWord(begin(words[randomWord]), end(words[randomWord]));
	cout << "Welcome to Word Jumble! Please enter your name" << endl;
	cout << "Guess the word below!" << endl;
	cout << jumble << endl;
	cin >> guess;
	while (wrongChoice)
	{
		if (guess == randomWord)
		{
			cout << "Correct! Thanks for playing!" << endl;
			wrongChoice = false;
		}
		else
		{
			cout << "WRONG! Guess again!" << endl;
			cin >> guess;
			continue;
		}
	}

	return 0;
}

