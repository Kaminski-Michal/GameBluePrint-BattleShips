#include<iostream>
#include <array>

class NotifyFourBlockObserver : public NotifyObservers
{
	virtual void NotifyParticularObserver(int positionOfHit);



	std::array<int, 5> FourBlockArray;



public:
	void setArraysOfShipsPositions(std::array<int, 5> &Bot4BlockShipInNavigationArray)
	{
		
		for (int ParticularPositionOfShip = 0; ParticularPositionOfShip < 5; ParticularPositionOfShip++)
		{
			FourBlockArray[ParticularPositionOfShip + 1] = Bot4BlockShipInNavigationArray[ParticularPositionOfShip + 1];
		}
	}


};

