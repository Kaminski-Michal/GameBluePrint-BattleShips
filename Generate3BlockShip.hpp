class ThreeBlockShipGenerator :public NextShipSegmentGenerator
{
	PathFinding pathFinding;
	bool _isPositionCorrect = false;
	bool _isShipPlaceable = false;
	int _lookingForNewShipTrials = 0;
	int _nextRowPosition;
	int _nextColumnPosition;
	int _remainingShipSegmentsPlaced = 2;
	int _shipSize = 3;
	int _remainingSegmentsToPathFind = 3;
	int _presentShips = 0;
	std::array<std::array<int, 2>, 3>temporartyShipPositon;

	void saveInTemporaryArray(int shipRowForTemporaryArray, int shipColumnForTemporaryArray)
	{
		temporartyShipPositon[3 - _remainingShipSegmentsPlaced][0] = shipRowForTemporaryArray;
		temporartyShipPositon[3 - _remainingShipSegmentsPlaced][1] = shipColumnForTemporaryArray;
	}

	void GenerateRest3BlockShip(std::array<std::array<char, 10>, 10> BotBoard, int StartRow, int StartColumn)
	{
		std::string newPositionValues;

		while (!(_remainingShipSegmentsPlaced == 0))
		{
			newPositionValues = GenerateNextPositon(BotBoard, StartRow, StartColumn);
			_nextRowPosition = newPositionValues[0];
			_nextColumnPosition = newPositionValues[1];
			int shipRow = StartRow + _nextRowPosition;
			int shipColumn = StartColumn + _nextColumnPosition;
			_remainingSegmentsToPathFind = _shipSize - _remainingShipSegmentsPlaced;
			_isShipPlaceable = true; //pathFinding.VerifyPossiblePatch(BotBoard, shipRow, shipColumn, _remainingSegmentsToPathFind);
			if (!_isShipPlaceable)
			{
				return;
			}
			saveInTemporaryArray(shipRow, shipColumn);
			BotBoard[StartRow + _nextRowPosition][StartColumn + _nextColumnPosition] = '3';
			StartRow = StartRow + _nextRowPosition;
			StartColumn = StartColumn + _nextColumnPosition;
			_remainingShipSegmentsPlaced--;
		}
		_isShipPlaceable = true;
	}
	void PlaceTemporartyShipPositon()
	{
		for (int i = 0; i < 3; i++)
		{
			char shipInRow = temporartyShipPositon[i][0];
			char shipInColumn = temporartyShipPositon[i][1];
		}
	}
	void PlaceShipFromTemporaryArray(std::array<std::array<char, 10>, 10>& BotBoard)
	{
		for (int i = 0; i < 3; i++)
		{
			int row = temporartyShipPositon[i][0];
			int column = temporartyShipPositon[i][1];
			BotBoard[row][column] = '3';
			Bot3BlockShipsInNavigationArray[_presentShips - 1][i + 1] = row * 10 + column;
		}
	}

public:
	std::array<std::array<char, 10>, 10> CopyOfBotBoard;

	void  Generate3BlockShip(std::array<std::array<char, 10>, 10>& BotBoard)
	{
		_isShipPlaceable = false;

		while (!_isShipPlaceable)
		{
		again:
			if (_lookingForNewShipTrials > 20)
			{
				std::cout << "No more free space for 3-size ship\n";
				is4BlockShipPresent = true;
				return;
			}
			int randomRowStartPositon = (rand() % 10);
			int randomColumnStartPosition = (rand() % 10);
			if (BotBoard[randomRowStartPositon][randomColumnStartPosition] == '4' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '*' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '3' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '2' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '1')
			{
				goto again;
			}

			_isShipPlaceable = true;//pathFinding.VerifyPossiblePatch(BotBoard, randomRowStartPositon, randomColumnStartPosition, _shipSize);
			if (!_isShipPlaceable)
			{
				_lookingForNewShipTrials++;
				goto again;
			}
			temporartyShipPositon[0][0] = randomRowStartPositon;
			temporartyShipPositon[0][1] = randomColumnStartPosition;
			_remainingShipSegmentsPlaced = 2;
			CopyOfBotBoard = BotBoard;
			CopyOfBotBoard[randomRowStartPositon][randomColumnStartPosition] = '3';
			GenerateRest3BlockShip(CopyOfBotBoard, randomRowStartPositon, randomColumnStartPosition);
		}
		_presentShips++;
		PlaceShipFromTemporaryArray(BotBoard);
		if (_presentShips == 2)
		{
			is3BlockShipsPresent = true;
		}
	}
};
