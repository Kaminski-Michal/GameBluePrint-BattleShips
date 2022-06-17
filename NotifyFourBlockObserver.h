#include<iostream>
#include <array>
class NotifyFourBlockObserver : public NotifyObservers
{
	void SaveValueOfHitPositionInPrivateArray(std::array<int, 5>& arrayToCheck, int positionOfHit, int positionInArray);
	void RememberValueOfPreviousHit(int positionOfHit);
public:

	virtual bool NotifyParticularObserver(int positionOfHit);
	void setArraysOfShipsPositions(std::array<int, 5> Bot2BlockShipsInNavigationArray);
};