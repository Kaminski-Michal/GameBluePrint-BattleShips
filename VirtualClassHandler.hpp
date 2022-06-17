#include "NotifyObservers.h"
#include "NotifyOneBlockObserver.h"
#include "NotifyTwoBlockObserver.h"
#include "NotifyThreeBlockObserver.h"
#include "NotifyFourBlockObserver.h"
#include "PlaceHolder.hpp"

class ChooseVirtualObserverToNotify
{
	bool _observerChangeStance;

public:
	bool PassValueToChoosenObserver(NotifyObservers& thisOne, int positionOfHit)
	{
		_observerChangeStance = thisOne.NotifyParticularObserver(positionOfHit);
		return _observerChangeStance;
	}
	int getSizeOfVector()
	{
		return 0;
	}
};

bool ChooseObserverToNotify(char kindOfShipHit, int positionOfHit)
{
	NotifyOneBlockObserver oneBlock;
	NotifyTwoBlockObserver twoBlock;
	NotifyThreeBlockObserver threeBlock;
	NotifyFourBlockObserver fourBlock;
	Placeholder placeholder;
	ChooseVirtualObserverToNotify Observer;
	bool ObserverChangeStance;
	switch (kindOfShipHit)
	{
	case '1':

		ObserverChangeStance = Observer.PassValueToChoosenObserver(oneBlock, positionOfHit);
		return ObserverChangeStance;

		break;
	case'2':

		ObserverChangeStance = Observer.PassValueToChoosenObserver(twoBlock, positionOfHit);
		return ObserverChangeStance;

		break;
	case '3':

		ObserverChangeStance = Observer.PassValueToChoosenObserver(threeBlock, positionOfHit);
		return ObserverChangeStance;
		break;
	case '4':

		ObserverChangeStance = Observer.PassValueToChoosenObserver(fourBlock, positionOfHit);
		return ObserverChangeStance;
		break;

	case NULL:
		Observer.PassValueToChoosenObserver(placeholder, positionOfHit);
		return false;
		break;

	default:

		return false;
		break;
	}
}

static void PassLocationOfTwoSizedArray(std::array<std::array<int, 3>, 3>& Bot2BlockShipsInNavigationArray)
{
	NotifyTwoBlockObserver twoBlock;
	twoBlock.setArraysOfShipsPositions(Bot2BlockShipsInNavigationArray);
}

static void PassLocationOfThreeSizedArray(std::array<std::array<int, 4>, 2>& Bot3BlockShipsInNavigationArray)
{
	NotifyThreeBlockObserver threeBlock;
	threeBlock.setArraysOfShipsPositions(Bot3BlockShipsInNavigationArray);
}

static void PassLocationOfFourSizedArray(std::array<int, 5>& Bot4BlockShipInNavigationArray)
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