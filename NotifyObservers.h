#include <iostream>
#include <array>
#include <vector>



class RetunObserverValues
{
public:
	void setSize(int size);
	void setArray(std::array<int, 5> VectorToReturn);
	int getSize();
	int GetArrayValueInThisPosition(int positionToTake);
};

class NotifyObservers
{
	std::array<int, 5> _temporaryArray;

public:
	virtual void NotifyParticularObserver(int positionOfHit) = 0;
	template<typename Type,size_t sizeOfArray>
	void ConvertInPutArrayIntoPositionOfDrowned(std::array<Type, sizeOfArray>&TakenArray)
	{
		
		std::array<Type, sizeOfArray>ArrayToPass;
		for (int i = 0; i < sizeOfArray; i++)
		{
			_temporaryArray[i] = TakenArray[i+1];
		}
		

		RetunObserverValues ReturnValues;
		ReturnValues.setSize(sizeOfArray);
		ReturnValues.setArray(_temporaryArray);
	}
	
};


