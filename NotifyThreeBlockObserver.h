#pragma once
#include <array>
#include <iostream>
class NotifyThreeBlockObserver : public NotifyObservers
{
	virtual void NotifyParticularObserver(int posiontOfThatHit);

	std::array<int, 4> FirstThreeBlockArray;
	std::array<int, 4> SecondThreeBlockArray;

	

public:
	void setArraysOfShipsPositions(std::array<std::array<int, 4>, 2> &Bot3BlockShipsInNavigationArray)
	{
		for (int ParticularShipPack = 0; ParticularShipPack < 2; ParticularShipPack++)
		{
			std::cout << std::endl;
			for (int ParticularPositionOfShip = 0; ParticularPositionOfShip < 3; ParticularPositionOfShip++)
			{
				if (ParticularShipPack == 0)
				{
					FirstThreeBlockArray[ParticularPositionOfShip + 1] = Bot3BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
				}
				else  
				{
					SecondThreeBlockArray[ParticularPositionOfShip + 1] = Bot3BlockShipsInNavigationArray[ParticularShipPack][ParticularPositionOfShip + 1];
				}

			}

		}

	}


};

