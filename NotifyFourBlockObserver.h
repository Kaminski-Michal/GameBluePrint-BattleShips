#include<iostream>
#include <array>

class NotifyFourBlockObserver : public NotifyObservers
{
	virtual void NotifyParticularObserver(int positionOfHit);

	void SaveValueOfHitPositionInPrivateArray(std::array<int, 5>& arrayToCheck, int positionOfHit, int positionInArray);
	void RememberValueOfPreviousHit(int positionOfHit);

public:
	void setArraysOfShipsPositions(std::array<int, 5> Bot2BlockShipsInNavigationArray);



};

