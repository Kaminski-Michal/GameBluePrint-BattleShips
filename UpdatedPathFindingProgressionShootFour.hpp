bool _goUpFourBlockProgression = true;
bool _goDownFourBlockProgression = true;
bool _goLeftFourBlockProgression = true;;
bool _goRightFourBlockProgression = true;

int _fourProgressionPositionRow = 0;
int _fourProgressionPositionColumn = 0;
bool doesPathfinderProgressionFourHaveWay = true;


int _nextShootingRow = 0;
int _nextShootingColumn = 0;
int _nextShootingRowProgressionFour = 0;
int _nextShootingColumnProgressionFour = 0;

class ShootPathfindingProgressionFour
{
	void ValidateEdges(int startingRow, int startingColumn)
	{
		if (startingRow == 0)
		{
			_goUpFourBlockProgression = false;

		}
		if (startingRow == 9)
		{
			_goDownFourBlockProgression = false;

		}
		if (startingColumn == 0)
		{
			_goLeftFourBlockProgression = false;

		}
		if (startingColumn == 9)
		{
			_goRightFourBlockProgression = false;
		}
	}




	void ValidateRemainingPathsProgressionFour(int startingRow, int startingColumn)
	{
		if (_goDownFourBlockProgression)
		{
			if (BotShootingAray[startingRow + 1][startingColumn] != '.')
			{
				_goDownFourBlockProgression = false;
			}
		}

		if (_goUpFourBlockProgression)
		{
			if (BotShootingAray[startingRow - 1][startingColumn] != '.')
			{
				_goUpFourBlockProgression = false;
			}
		}

		if (_goRightFourBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn + 1] != '.')
			{
				_goRightFourBlockProgression = false;
			}
		}

		if (_goLeftFourBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn - 1] != '.')
			{
				_goLeftFourBlockProgression = false;
			}
		}
	}


public:



	void FourthBlockProgression(int startingRow, int startingColumn, int progressionSize)
	{
		ValidateEdges(startingRow, startingColumn);
		ValidateRemainingPathsProgressionFour(startingRow, startingColumn);



		if (_goDownFourBlockProgression)
		{
			_fourProgressionPositionRow = startingRow + 1;
			_fourProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goLeftFourBlockProgression)
		{
			_fourProgressionPositionRow = startingRow;
			_fourProgressionPositionColumn = startingColumn - 1;
			return;
		}
		if (_goRightFourBlockProgression)
		{
			_fourProgressionPositionRow = startingRow;
			_fourProgressionPositionColumn = startingColumn + 1;
			return;
		}
		if (_goUpFourBlockProgression)
		{
			_fourProgressionPositionRow = startingRow - 1;
			_fourProgressionPositionColumn = startingColumn;
			return;
		}
		if (!_goUpFourBlockProgression && !_goDownFourBlockProgression && !_goLeftFourBlockProgression && !_goRightFourBlockProgression)
		{
			doesPathfinderProgressionFourHaveWay = false;
			return;
		}


	}







};