#pragma once
#include <array>
#include <iostream>
class NotifyThreeBlockObserver : public NotifyObservers
{
	void SaveValueOfHitPositionInPrivateArray(std::array<int, 4>& arrayToCheck, int positionOfHit, int positionInArray);
	void RememberValueOfPreviousHit(int positionOfHit);

public:
	virtual bool NotifyParticularObserver(int posiontOfThatHit);
	void setArraysOfShipsPositions(std::array<std::array<int, 4>, 2> Bot3BlockShipsInNavigationArray);
};
