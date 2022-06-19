class NextShipSegmentGenerator : public ValideateShipPosition
{
protected:
	int _pushRowLocation = 0;
	int _pushColumnLocation = 0;
	int _nextRowLocation = 0;
	int _nextColumnLocation = 0;
	std::string _returningString = "";
public:

	std::string GenerateNextPositon(std::array<std::array<char, 10>, 10> &BotArray, int previousRow, int previousColumn)
	{
		do
		{
			_newPositionsAllowed = false;
			
			GenerateRandomNumber:
			_pushRowLocation = (rand() % 3 - 1);
			_pushColumnLocation = (rand() % 3 - 1);
			_nextRowLocation = previousRow + _pushRowLocation;
			_nextColumnLocation = previousColumn + _pushColumnLocation;


			if ((_pushRowLocation == 1 && _pushColumnLocation == 1) ||  (_pushRowLocation == 0 && _pushColumnLocation ==0) || (_pushRowLocation == -1 && _pushColumnLocation == -1) || (_pushRowLocation == 1 && _pushColumnLocation == -1)||(_pushRowLocation == -1 && _pushColumnLocation == 1))
			{
				goto GenerateRandomNumber;
			}
			ValidateCurrentRow(BotArray,_nextRowLocation, _nextColumnLocation);			
		} while (!_newPositionsAllowed);
		_returningString = (int)_pushRowLocation;
		_returningString += (int)_pushColumnLocation;
		return _returningString;
	}
};
