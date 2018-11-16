#pragma once
class Magazine
{
public:
	Magazine(int capacity, int loaded);
	~Magazine();

	bool loadRound();
	bool removeRound();

	int maximumCapacity;
	int roundsLoaded;
};