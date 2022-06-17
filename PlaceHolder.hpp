class Placeholder : public NotifyObservers
{
	std::array<int, 1> PlaceHolderBlockArray;

	bool _isPlaceHolderBlockArrayDone = false;
	virtual bool NotifyParticularObserver(int positionOfHit)
	{
		return false;
	}

	bool RememberValueOfPreviousHit(int positionOfHit)
	{

		if (!_isPlaceHolderBlockArrayDone && PlaceHolderBlockArray[0] == 1)
		{
			_isPlaceHolderBlockArrayDone = true;
			ConvertInPutArrayIntoPositionOfDrowned(PlaceHolderBlockArray);
			return true;
		}
		return false;
	}

public:



private:
};
