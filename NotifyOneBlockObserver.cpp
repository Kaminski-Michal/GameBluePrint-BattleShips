#include <iostream>
#include "NotifyObservers.h"
#include "NotifyOneBlockObserver.h"



std::array<int, 2> _privateFirstOneBlockArray{0,-1};
std::array<int, 2> _privateSecondOneBlockArray{0,-1};
std::array<int, 2> _privateThirdOneBlockArray{0,-1};
std::array<int, 2> _privateFourthOneBlockArray{0,-1};

std::array<int, 2> FirstOneBlockArray;
std::array<int, 2> SecondOneBlockArray;
std::array<int, 2> ThirdOneBlockArray;
std::array<int, 2> FourthOneBlockArray;

bool _isFirstOneBlockArrayDone = false;
bool _isSecondOneBlockArrayDone = false;
bool _isThirdOneBlockArrayDone = false;
bool _isFourthOneBlockArrayDone = false;



void NotifyOneBlockObserver::SaveValueOfHitPositionInPrivateArray(std::array<int, 2>& arrayToCheck, int positionOfHit, int positionInArray)
{
	if (arrayToCheck[positionInArray] == -1)
	{
		arrayToCheck[positionInArray] = positionOfHit;
		(int)arrayToCheck[0]++;
	}
}



void NotifyOneBlockObserver::RememberValueOfPreviousHit(int positionOfHit)
{
	if (FirstOneBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstOneBlockArray, positionOfHit, 1);
	}

	else if (SecondOneBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateSecondOneBlockArray, positionOfHit, 1);
	}

	else if (ThirdOneBlockArray[1] == positionOfHit)
	{

		SaveValueOfHitPositionInPrivateArray(_privateThirdOneBlockArray, positionOfHit, 1);
	}

	else if (FourthOneBlockArray[1] == positionOfHit)
	{

		SaveValueOfHitPositionInPrivateArray(_privateFourthOneBlockArray, positionOfHit, 1);
	}
}

bool NotifyOneBlockObserver::NotifyParticularObserver(int positionOfHit)
{

	RememberValueOfPreviousHit(positionOfHit);

	if (!_isFirstOneBlockArrayDone && _privateFirstOneBlockArray[0] == 1)
	{
		_isFirstOneBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateFirstOneBlockArray);
		return true;
	}

	else if (!_isSecondOneBlockArrayDone && _privateSecondOneBlockArray[0] == 1)
	{
		_isSecondOneBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateSecondOneBlockArray);
		return true;
	}

	else if (!_isThirdOneBlockArrayDone && _privateThirdOneBlockArray[0] == 1)
	{
		_isThirdOneBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateThirdOneBlockArray);
		return true;
	}
	else if (!_isFourthOneBlockArrayDone && _privateFourthOneBlockArray[0] == 1)
	{
		_isThirdOneBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateFourthOneBlockArray);
		return true;
	}

	return false;
}


void NotifyOneBlockObserver::setArraysOfShipsPositions(std::array<std::array<int, 2>, 4> Bot1BlockShipsInNavigationArray)
{
	for (int ParticularShipPack = 0; ParticularShipPack < 4; ParticularShipPack++)
	{
			if (ParticularShipPack == 0)
			{
				FirstOneBlockArray[1] = Bot1BlockShipsInNavigationArray[ParticularShipPack][1];
			}
			else if (ParticularShipPack == 1)
			{
				SecondOneBlockArray[1] = Bot1BlockShipsInNavigationArray[ParticularShipPack][1];
			}
			else if (ParticularShipPack == 2)
			{
				ThirdOneBlockArray[1] = Bot1BlockShipsInNavigationArray[ParticularShipPack][1];
			}
			else if (ParticularShipPack == 3)
			{
				FourthOneBlockArray[1] = Bot1BlockShipsInNavigationArray[ParticularShipPack][1];
			}
	}
}