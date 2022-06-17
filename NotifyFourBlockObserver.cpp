#include <iostream>
#include "NotifyObservers.h"
#include "NotifyFourBlockObserver.h"




std::array<int, 5> _privateFirstFourBlockArray{ 0,-1,-1,-1,-1 };
std::array<int, 3> FirstFourBlockArray{};

bool _isFirstFourBlockArrayDone = false;




void NotifyFourBlockObserver::SaveValueOfHitPositionInPrivateArray(std::array<int, 5>& arrayToCheck, int positionOfHit, int positionInArray)
{
	if (arrayToCheck[positionInArray] == -1)
	{
		arrayToCheck[positionInArray] = positionOfHit;
		arrayToCheck[0]++;
	}
}



void NotifyFourBlockObserver::RememberValueOfPreviousHit(int positionOfHit)
{
	if (FirstFourBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstFourBlockArray, positionOfHit, 1);
	}
	else if(FirstFourBlockArray[2] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstFourBlockArray, positionOfHit, 2);
	}
	else if (FirstFourBlockArray[3] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstFourBlockArray, positionOfHit, 3);
	}
	else if (FirstFourBlockArray[4] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstFourBlockArray, positionOfHit, 4);
	}
}


bool NotifyFourBlockObserver::NotifyParticularObserver(int positionOfHit)
{
	RememberValueOfPreviousHit(positionOfHit);

	if (!_isFirstFourBlockArrayDone && _privateFirstFourBlockArray[0] >= 4)
	{
		_isFirstFourBlockArrayDone = true;
		NotifyFourBlockObserver::ConvertInPutArrayIntoPositionOfDrowned(_privateFirstFourBlockArray);
		return true;
	}
	return false;
}


void NotifyFourBlockObserver::setArraysOfShipsPositions(std::array<int, 5> Bot4BlockShipsInNavigationArray)
{
	for (int ParticularPositionOfShip = 0; ParticularPositionOfShip < 5; ParticularPositionOfShip++)
	{
			FirstFourBlockArray[(ParticularPositionOfShip + 1)] = static_cast<int>(Bot4BlockShipsInNavigationArray[ParticularPositionOfShip + 1]);
			
	}
}