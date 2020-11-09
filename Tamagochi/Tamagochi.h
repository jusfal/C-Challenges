#pragma once
class Tamagochi
{
public:
	Tamagochi();
	~Tamagochi();
	void Talk();
	void Eat();
	void Play();

private:
	int hunger;
	int boredom;
};

