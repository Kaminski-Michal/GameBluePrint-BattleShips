#include <iostream>
#include "NotifyObservers.h"
#include "NotifyThreeBlockObserver.h"



std::array<int, 4> _privateFirstThreeBlockArray{ 0,(-1),(-1),(-1) };
std::array<int, 4> _privateSecondThreeBlockArray{ 0,(-1),(-1),(-1) };

std::array<int, 4> FirstThreeBlockArray;
std::array<int, 4> SecondThreeBlockArray;

bool _isFirstThreeBlockArrayDone = false;
bool _isSecondThreeBlockArrayDone = false;




void NotifyThreeBlockObserver::SaveValueOfHitPositionInPrivateArray(std::array<int, 4>& arrayToCheck, int positionOfHit, int positionInArray)
{
	if (arrayToCheck[positionInArray] == -1)
	{
		arrayToCheck[positionInArray] = positionOfHit;
		arrayToCheck[0] ++;
	}
}



void NotifyThreeBlockObserver::RememberValueOfPreviousHit(int positionOfHit)
{
	if (FirstThreeBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstThreeBlockArray, positionOfHit, 1);
	}
	else if (FirstThreeBlockArray[2] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstThreeBlockArray, positionOfHit, 2);
	}
	else if (FirstThreeBlockArray[3] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstThreeBlockArray, positionOfHit, 3);
	}



	if (SecondThreeBlockArray[1] == positionOfHit)
	{

		SaveValueOfHitPositionInPrivateArray(_privateSecondThreeBlockArray, positionOfHit, 1);
	}
	else if (SecondThreeBlockArray[2] == positionOfHit)
	{

		SaveValueOfHitPositionInPrivateArray(_privateSecondThreeBlockArray, positionOfHit, 2);
	}
	else if (SecondThreeBlockArray[3] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateSecondThreeBlockArray, positionOfHit, 3);
	}
}


bool NotifyThreeBlockObserver::NotifyParticularObserver(int positionOfHit)
{

	RememberValueOfPreviousHit(positionOfHit);

	if (!_isFirstThreeBlockArrayDone && _privateFirstThreeBlockArray[0] == 3)
	{
		_isFirstThreeBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateFirstThreeBlockArray);
		return true;
	}

	else if (!_isSecondThreeBlockArrayDone && _privateSecondThreeBlockArray[0] >= 3)
	{
		_isSecondThreeBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateSecondThreeBlockArray);
		return true;
	}
	return false;

	
}


void NotifyThreeBlockObserver::setArraysOfShipsPositions(std::array<std::array<int, 4>, 2> Bot3BlockShipsInNavigationArray)
{
	for (int ParticularShipPack = 0; ParticularShipPack < 2; ParticularShipPack++)
	{
		for (int ParticularPositionOfShip = 0; ParticularPositionOfShip < 3; ParticularPositionOfShip++)
		{

			if (ParticularShipPack == 0)
			{
				FirstThreeBlockArray[(ParticularPositionOfShip + 1)] = Bot3BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
			}
			else if (ParticularShipPack == 1)
			{
				SecondThreeBlockArray[ParticularPositionOfShip + 1] = Bot3BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
			}

		}

	}


}