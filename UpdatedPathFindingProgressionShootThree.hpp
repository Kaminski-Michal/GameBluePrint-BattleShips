bool _goUpThirdBlockProgression = true;
bool _goDownThirdBlockProgression = true;
bool _goLeftThirdBlockProgression = true;
bool _goRightThirdBlockProgression = true;


int _thirdProgressionPositionRow = 0;
int _thirdProgressionPositionColumn = 0;
bool doesPathfinderProgressionThreeHaveWay = true;

class ShootPathfindingProgressionThree
{

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
		ValidateRemainingPathsProgressionThree(startingRow, startingColumn);





		if (_goUpThirdBlockProgression)
		{
			_thirdProgressionPositionRow = startingRow - 1;
			_thirdProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goDownThirdBlockProgression)
		{
			_thirdProgressionPositionRow = startingRow + 1;
			_thirdProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goLeftThirdBlockProgression)
		{
			_thirdProgressionPositionRow = startingRow;
			_thirdProgressionPositionColumn = startingColumn - 1;
			return;
		}
		if (_goRightThirdBlockProgression)
		{
			_thirdProgressionPositionRow = startingRow;
			_thirdProgressionPositionColumn = startingColumn + 1;
			return;
		}
		if (!_goUpThirdBlockProgression && !_goDownThirdBlockProgression && !_goLeftThirdBlockProgression && !_goRightThirdBlockProgression)
		{
			doesPathfinderProgressionThreeHaveWay = false;
			return;
		}


	}







};
