	bool _goUpSecondBlockProgression = true;
	bool _goDownSecondBlockProgression = true;
	bool _goLeftSecondBlockProgression = true;;
	bool _goRightSecondBlockProgression = true;



class UpdatedShootPathfinding
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
			_goLeftSecondBlockProgression == false;
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


	


protected:
	int _SecondProgressionPositionRow = 0;
	int _SecondProgressionPositionColumn = 0;
	


public:
	void SecondBlockProgression(int startingRow, int startingColumn, int progressionSize)
	{
		ValidateEdges(startingRow, startingColumn);
		ValidateRemainingPaths(startingRow, startingColumn);

		if (_goUpSecondBlockProgression)
		{
			_SecondProgressionPositionRow = startingRow - 1;
			_SecondProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goDownSecondBlockProgression)
		{
			_SecondProgressionPositionRow = startingRow + 1;
			_SecondProgressionPositionColumn = startingColumn;
			return;
		}
		if (_goLeftSecondBlockProgression)
		{
			_SecondProgressionPositionRow = startingRow;
			_SecondProgressionPositionColumn = startingColumn - 1;
			return;
		}
		if (_goRightSecondBlockProgression)
		{
			_SecondProgressionPositionRow = startingRow;
			_SecondProgressionPositionColumn = startingColumn + 1;
			return;
		}
		else
		{
			progressionSize--;
		}




	}



};
