
#include "NotifyObservers.h"
#include "NotifyOneBlockObserver.h"
#include "NotifyTwoBlockObserver.h"
#include "NotifyThreeBlockObserver.h"
#include "NotifyFourBlockObserver.h"






class ChooseObserverToNotify
{
public:
	void static PassValueToChoosenObserver(NotifyObservers& thisOne, int positionOfHit)
	{
		thisOne.NotifyParticularObserver(positionOfHit);
		
	}
	int getSizeOfVector()
	{
		
		return 0;
	}

};


static void ChooseObserverToNotify(char kindOfShipHit, int positionOfHit)
{
	NotifyOneBlockObserver oneBlock;
	NotifyTwoBlockObserver twoBlock;
	NotifyThreeBlockObserver threeBlock;
	NotifyFourBlockObserver fourBlock;

	switch (kindOfShipHit)
	{
	case '1':

		ChooseObserverToNotify::PassValueToChoosenObserver(oneBlock, positionOfHit);
		break;
	case'2':

		ChooseObserverToNotify::PassValueToChoosenObserver(twoBlock, positionOfHit);
		break;
	case '3':

		ChooseObserverToNotify::PassValueToChoosenObserver(threeBlock, positionOfHit);
		break;
	case '4':

		ChooseObserverToNotify::PassValueToChoosenObserver(fourBlock, positionOfHit);
		break;
	default:
		break;
	}

}



static void PassLocationOfTwoSizedArray(std::array<std::array<int, 3>, 3> &Bot2BlockShipsInNavigationArray)
{
	NotifyTwoBlockObserver twoBlock;
	twoBlock.setArraysOfShipsPositions(Bot2BlockShipsInNavigationArray);
}



static void PassLocationOfThreeSizedArray(std::array<std::array<int, 4>, 2> &Bot3BlockShipsInNavigationArray)
{
	NotifyThreeBlockObserver threeBlock;
	threeBlock.setArraysOfShipsPositions(Bot3BlockShipsInNavigationArray);

}


static void PassLocationOfFourSizedArray(std::array<int, 5> &Bot4BlockShipInNavigationArray)
{
	NotifyFourBlockObserver fourBlock;
	fourBlock.setArraysOfShipsPositions(Bot4BlockShipInNavigationArray);
	
}

	RetunObserverValues ReturnValues;
int GetSizeOfVector()
{
	int size = ReturnValues.getSize();
	return size;
}
int GetValueOfVector(int position)
{
	int valueHere = ReturnValues.GetArrayValueInThisPosition(position);
	return valueHere;
}