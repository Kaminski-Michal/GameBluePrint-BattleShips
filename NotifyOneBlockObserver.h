#pragma once
class NotifyOneBlockObserver : public NotifyObservers
{


	void SaveValueOfHitPositionInPrivateArray(std::array<int, 2>& arrayToCheck, int positionOfHit, int positionInArray);
	void RememberValueOfPreviousHit(int positionOfHit);

public:
	virtual bool NotifyParticularObserver(int positionOfHit);
	void setArraysOfShipsPositions(std::array<std::array<int, 2>, 4> Bot2BlockShipsInNavigationArray);




};

