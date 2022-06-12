class OneBlockShipGenerator :public NextShipSegmentGenerator
{
	PathFinding pathFinding;
	bool _isPositionCorrect = false;
	bool _isShipPlaceable = false;
	int _lookingForNewShipTrials = 0;
	int _nextRowPosition;
	int _nextColumnPosition;
	int _presentShips = 0;
	int _shipSize = 1;
	
	public:
	std::array<std::array<char, 10>, 10> CopyOfBotBoard;

	void  Generate1BlockShip(std::array<std::array<char, 10>, 10>& BotBoard)
	{
		_isShipPlaceable = false;
		
		again:
			int randomRowStartPositon = (rand() % 10);
			int randomColumnStartPosition = (rand() % 10);
			if (BotBoard[randomRowStartPositon][randomColumnStartPosition] == '4' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '*' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '3' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '2' || BotBoard[randomRowStartPositon][randomColumnStartPosition] == '1')
			{
				goto again;
			}
			BotBoard[randomRowStartPositon][randomColumnStartPosition] = '1';
			_presentShips++;
			Bot1BlockShipsInNavigationArray[_presentShips-1][1] = randomRowStartPositon * 10 + randomColumnStartPosition;
		if (_presentShips == 4)
		{
			is1BlockShipsPresent = true;
		}
	}
};
