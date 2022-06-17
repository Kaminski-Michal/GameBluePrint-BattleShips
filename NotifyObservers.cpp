#include <iostream>
#include <array>
#include "NotifyObservers.h"

std::array<int, 5>_PrivateArray{ 0 };
int _privateSize = 0;

void RetunObserverValues::setSize(int size)
{
	_privateSize = size;
}
void RetunObserverValues::setArray(std::array<int, 5> ArrayToReturn)
{
	_PrivateArray = ArrayToReturn;
}

int RetunObserverValues::getSize()
{
	return _privateSize;
}
int RetunObserverValues::GetArrayValueInThisPosition(int positionToTake)
{
	int value = _PrivateArray[positionToTake];
	return value;
}