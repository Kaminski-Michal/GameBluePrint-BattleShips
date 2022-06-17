#pragma once
#include <iostream>
#include <array>

class NotifyTwoBlockObserver : public NotifyObservers
{
private:

	void SaveValueOfHitPositionInPrivateArray(std::array<int, 3>& arrayToCheck, int positionOfHit, int positionInArray);
	void RememberValueOfPreviousHit(int positionOfHit);
public:

	virtual bool NotifyParticularObserver(int positionOfHit);
	void setArraysOfShipsPositions(std::array<std::array<int, 3>, 3> Bot2BlockShipsInNavigationArray);
};
