class FourBlockShip : public NextShipSegmentGenerator
{
		PathFinding pathFinding;
		bool _isPositionCorrect = false;
		bool _isShipPlaceable = false;
		int _lookingForNewShipTrials = 0;
		int _nextRowPosition;
		int _nextColumnPosition;
		int _remainingShipSegmentsPlaced = 3;
		int _shipSize = 4;
		int _remainingSegmentsToPathFind = 4;
		std::array<std::array<int,2>,4>temporartyShipPositon;

	void saveInTemporaryArray(int shipRowForTemporaryArray, int shipColumnForTemporaryArray)
	{
		temporartyShipPositon[4 - _remainingShipSegmentsPlaced][0] = shipRowForTemporaryArray;
		temporartyShipPositon[4 - _remainingShipSegmentsPlaced][1] = shipColumnForTemporaryArray;
	}




	void GenerateRest4BlockShip(std::array<std::array<char, 10>, 10> BotBoard, int StartRow, int StartColumn)
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
			_isShipPlaceable = true;//pathFinding.VerifyPossiblePatch(BotBoard, shipRow, shipColumn, _remainingSegmentsToPathFind);
			if (!_isShipPlaceable)
			{
				return;
			}
			saveInTemporaryArray(shipRow, shipColumn);
			BotBoard[(StartRow + _nextRowPosition)][(StartColumn + _nextColumnPosition)] = '4';
			
			StartRow = StartRow + _nextRowPosition;
			StartColumn = StartColumn + _nextColumnPosition;
			_remainingShipSegmentsPlaced--;
		}
		_isShipPlaceable = true;
	}
	void PlaceTemporartyShipPositon()
	{
		
		for (int i = 0; i < 4; i++)
		{
			char shipInRow = temporartyShipPositon[i][0];
			char shipInColumn = temporartyShipPositon[i][1];


		}
	}
	void PlaceShipFromTemporaryArray(std::array<std::array<char, 10>, 10>& BotBoard)
	{
		for (int i = 0; i < 4; i++)
		{
			int row = temporartyShipPositon[i][0];
			int column = temporartyShipPositon[i][1];
			BotBoard[row][column] = '4';
			Bot4BlockShipInNavigationArray[i+1] = (row * 10 + column);
		} 
	}







public:
	std::array<std::array<char, 10>, 10> CopyOfBotBoard;




	void  Generate4BlockShip(std::array<std::array<char, 10>, 10> &BotBoard)
	{
		_isShipPlaceable = false;

		while(!_isShipPlaceable)
		{ 
		again:
			if (_lookingForNewShipTrials > 20)
			{
				std::cout << "No more free space for 4-size ship\n";
				is4BlockShipPresent = true;
				return;
			}
			int randomRowStartPositon = (rand() % 10);
			int randomColumnStartPosition = (rand() % 10);
			if (BotBoard[randomRowStartPositon][randomColumnStartPosition] == '4' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '*')
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
			_remainingShipSegmentsPlaced = 3;
			CopyOfBotBoard = BotBoard;
			CopyOfBotBoard[randomRowStartPositon][randomColumnStartPosition] = '4';
			GenerateRest4BlockShip(CopyOfBotBoard, randomRowStartPositon, randomColumnStartPosition);
		}
		PlaceShipFromTemporaryArray(BotBoard);
		is4BlockShipPresent = true;
	}




};