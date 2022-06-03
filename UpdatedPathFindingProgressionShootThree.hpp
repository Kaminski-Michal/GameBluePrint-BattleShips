bool _goUpThirdBlockProgression = true;
bool _goDownThirdBlockProgression = true;
bool _goLeftThirdBlockProgression = true;
bool _goRightThirdBlockProgression = true;


int _thirdProgressionPositionRow = 0;
int _thirdProgressionPositionColumn = 0;
bool doesPathfinderProgressionThreeHaveWay = true;

class ShootPathfindingProgressionThree : public ShootPathfindingProgressionFour
{

	void ValidateEdges(int startingRow, int startingColumn)
	{
		if (startingRow == 0)
		{
			_goUpThirdBlockProgression = false;

		}
		if (startingRow == 9)
		{
			_goDownThirdBlockProgression = false;

		}
		if (startingColumn == 0)
		{
			_goLeftThirdBlockProgression = false;

		}
		if (startingColumn == 9)
		{
			_goRightThirdBlockProgression = false;
		}
	}


	void ValidateRemainingPathsProgressionThree(int startingRow, int startingColumn)
	{
	
		if (_goDownThirdBlockProgression)
		{
			if (BotShootingAray[startingRow + 1][startingColumn] != '.')
			{
				_goDownThirdBlockProgression = false;
			}
		}

		if (_goUpThirdBlockProgression)
		{
			if (BotShootingAray[startingRow - 1][startingColumn] != '.')
			{
				_goUpThirdBlockProgression = false;
			}
		}

		if (_goRightThirdBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn + 1] != '.')
			{
				_goRightThirdBlockProgression = false;
			}
		}

		if (_goLeftThirdBlockProgression)
		{
			if (BotShootingAray[startingRow][startingColumn - 1] != '.')
			{
				_goLeftThirdBlockProgression = false;
			}
		}
	}
protected:
	

public:


	
	void ThirdBlockProgression(int startingRow, int startingColumn, int progressionSize)
	{

		ShootPathfindingProgressionFour shootProgressionFour;

		if (BotProgressionHitFour)
		{
			shootProgressionFour.FourthBlockProgression(_thirdProgressionPositionRow, _thirdProgressionPositionColumn, progressionSize);
			if (!doesPathfinderProgressionFourHaveWay)
			{
				BotProgressionHitFour = false;
			}
			else
			{
				_nextShootingRow  = _fourProgressionPositionRow;
				_nextShootingColumn = _fourProgressionPositionColumn;
				return;
			}
			return;
		}

		ValidateEdges(startingRow, startingColumn);
		ValidateRemainingPathsProgressionThree(startingRow, startingColumn);
		doesPathfinderProgressionThreeHaveWay = true;

		if (_goUpThirdBlockProgression)
		{
		_nextShootingRow = _thirdProgressionPositionRow = startingRow - 1;
		_nextShootingColumn = _thirdProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goDownThirdBlockProgression)
		{
		_nextShootingRow = _thirdProgressionPositionRow = startingRow + 1;
		_nextShootingColumn = _thirdProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goLeftThirdBlockProgression)
		{
			_nextShootingRow = _thirdProgressionPositionRow = startingRow;
			_nextShootingColumn = _thirdProgressionPositionColumn = startingColumn - 1;
			return;
		}
		if (_goRightThirdBlockProgression)
		{
			_nextShootingRow = _thirdProgressionPositionRow = startingRow;
			_nextShootingColumn = _thirdProgressionPositionColumn = startingColumn + 1;
			return;
		}
		if (!_goUpThirdBlockProgression && !_goDownThirdBlockProgression && !_goLeftThirdBlockProgression && !_goRightThirdBlockProgression)
		{
			doesPathfinderProgressionThreeHaveWay = false;
			return;
		}


	}







};
