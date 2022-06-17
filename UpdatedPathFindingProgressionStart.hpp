bool _goUpSecondBlockProgression = true;
bool _goDownSecondBlockProgression = true;
bool _goLeftSecondBlockProgression = true;;
bool _goRightSecondBlockProgression = true;
bool doesPathfinderProgressionTwoHaveWay = true;

int _SecondProgressionPositionRow = 0;
int _SecondProgressionPositionColumn = 0;

class UpdatedShootPathfinding : public ShootPathfindingProgressionThree
{
	void ValidateEdges(int startingRow, int startingColumn)
	{
		if (startingRow == 0)
		{
			_goUpSecondBlockProgression = false;

		}
		if (startingRow == 9)
		{
			_goDownSecondBlockProgression = false;

		}
		if (startingColumn == 0)
		{
			_goLeftSecondBlockProgression = false;
			
		}
		if (startingColumn == 9)
		{
			_goRightSecondBlockProgression = false;
		}
	}

	void ValidateRemainingPaths(int startingRow, int startingColumn)
	{
		if (_goDownSecondBlockProgression)
		{
			if (BotShootingAray[startingRow + 1][startingColumn] != '.')
			{
				_goDownSecondBlockProgression = false;
			}
		}

		if (_goUpSecondBlockProgression)
		{
			if (BotShootingAray[startingRow - 1][startingColumn] != '.')
			{
				_goUpSecondBlockProgression = false;
			}
		}

		if (_goRightSecondBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn + 1] != '.')
			{
				_goRightSecondBlockProgression = false;
			}
		}

		if (_goLeftSecondBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn - 1] != '.')
			{
				_goLeftSecondBlockProgression = false;
			}
		}
	}
public:
	
void SecondBlockProgression(int startingRow, int startingColumn, int progressionSize)
{

	if (BotProgressionHitThree)
	{
		ThirdBlockProgression(_SecondProgressionPositionRow, _SecondProgressionPositionColumn, progressionSize);
		if (BotProgressionHitFour)
		{
			_nextShootingRow = _fourProgressionPositionRow;
			_nextShootingColumn = _fourProgressionPositionColumn;
			return;
		}
		if (!doesPathfinderProgressionThreeHaveWay)
		{
			BotProgressionHitThree = false;
		}
		else
		{
			_nextShootingRow = _thirdProgressionPositionRow ;
			_nextShootingColumn =  _thirdProgressionPositionColumn ;
			return;
		}
	}
	ValidateEdges(startingRow, startingColumn);
	ValidateRemainingPaths(startingRow, startingColumn);

	if (_goUpSecondBlockProgression)
	{
		_nextShootingRow = _SecondProgressionPositionRow = startingRow - 1;
		_nextShootingColumn = _SecondProgressionPositionColumn = startingColumn;
		return;
	}
	if (_goDownSecondBlockProgression)
	{
		_nextShootingRow = _SecondProgressionPositionRow = startingRow + 1;
		_nextShootingColumn = _SecondProgressionPositionColumn = startingColumn;
		return;
	}
	if (_goLeftSecondBlockProgression)
	{
		_nextShootingRow = _SecondProgressionPositionRow = startingRow;
		_nextShootingColumn = _SecondProgressionPositionColumn = startingColumn - 1;
		return;
	}
	if (_goRightSecondBlockProgression)
	{
		_nextShootingRow = _SecondProgressionPositionRow = startingRow;
		_nextShootingColumn = _SecondProgressionPositionColumn = startingColumn + 1;
		return;
	}



	if (!_goRightSecondBlockProgression && !_goLeftSecondBlockProgression && !_goUpSecondBlockProgression && !_goDownSecondBlockProgression)
	{
		doesPathfinderProgressionTwoHaveWay = false;
		return;
	}

}
};
