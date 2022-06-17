#include <iostream>
#include <array>
#include "NotifyObservers.h"
#include "NotifyTwoBlockObserver.h"

std::array<int, 3> _privateFirstTwoBlockArray{ 0,-1,-1 };
std::array<int, 3> _privateSecondTwoBlockArray{ 0,-1,-1 };
std::array<int, 3> _privateThirdTwoBlockArray{ 0,-1,-1 };
std::array<int, 3> FirstTwoBlockArray{};
std::array<int, 3> SecondTwoBlockArray{};
std::array<int, 3> ThirdTwoBlockArray{};
bool _isFirstTwoBlockArrayDone = false;
bool _isSecondTwoBlockArrayDone = false;
bool _isThirdTwoBlockArrayDone = false;



void NotifyTwoBlockObserver::SaveValueOfHitPositionInPrivateArray(std::array<int, 3> &arrayToCheck ,int positionOfHit, int positionInArray)
{
	if (arrayToCheck[positionInArray] == -1)
	{
		arrayToCheck[positionInArray] = positionOfHit;
		arrayToCheck[0]++;		
	}
}



void NotifyTwoBlockObserver::RememberValueOfPreviousHit(int positionOfHit)
{
	if (FirstTwoBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstTwoBlockArray, positionOfHit, 1);
	}

	else if (FirstTwoBlockArray[2] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateFirstTwoBlockArray, positionOfHit, 2);
	} 

	else if (SecondTwoBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateSecondTwoBlockArray, positionOfHit, 1);
	}

	else if (SecondTwoBlockArray[2] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateSecondTwoBlockArray, positionOfHit, 2);
	}
	else if (ThirdTwoBlockArray[1] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateThirdTwoBlockArray, positionOfHit, 1);
	}

	else if (ThirdTwoBlockArray[2] == positionOfHit)
	{
		SaveValueOfHitPositionInPrivateArray(_privateThirdTwoBlockArray, positionOfHit, 2);
	}
}


void NotifyTwoBlockObserver::NotifyParticularObserver(int positionOfHit)
{

	RememberValueOfPreviousHit(positionOfHit);

	if (!_isFirstTwoBlockArrayDone && _privateFirstTwoBlockArray[0] == 2)
	{
		_isFirstTwoBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateFirstTwoBlockArray);
	}

	else if (!_isSecondTwoBlockArrayDone &&_privateSecondTwoBlockArray[0] == 2)
	{
		_isSecondTwoBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateSecondTwoBlockArray);
	}

	else if (!_isThirdTwoBlockArrayDone && _privateThirdTwoBlockArray[0] == 2)
	{
		_isThirdTwoBlockArrayDone = true;
		NotifyObservers::ConvertInPutArrayIntoPositionOfDrowned(_privateThirdTwoBlockArray);

	}
}


void NotifyTwoBlockObserver::setArraysOfShipsPositions(std::array<std::array<int, 3>, 3> Bot2BlockShipsInNavigationArray)
{
	for (int ParticularShipPack = 0; ParticularShipPack < 3; ParticularShipPack++)
	{
		for (int ParticularPositionOfShip = 0; ParticularPositionOfShip < 2; ParticularPositionOfShip++)
		{

			if (ParticularShipPack == 0)
			{
				FirstTwoBlockArray[(ParticularPositionOfShip + 1)] = static_cast<int>(Bot2BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1]);
			}
			else if (ParticularShipPack == 1)
			{

				SecondTwoBlockArray[ParticularPositionOfShip + 1] = Bot2BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
			}
			else
			{
				ThirdTwoBlockArray[(ParticularPositionOfShip + 1)] = Bot2BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
			}

		}

	}
}