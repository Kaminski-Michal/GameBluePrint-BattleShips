class PathFinding_SuccessorThree
{
private:
	bool _successorFourHavePath = true;
	bool _successorThreeHavePath = true;
	int _pathFindingTries = 0;
	int _updatedRowPosition = 0;
	int _updatedColumnPosition = 0;
	int randomHorizontalVector = 0;
	int randomVerticalVector = 0;
	int currentSuccessor = 1;

public:

	bool VerifyPossbilePatchs_SuccessorThree(std::array<std::array<char, 10>, 10>& BotArray, int startingRow, int startingColumn, int shipSize,int previousHorizontalVector,int previousVerticalVector)
	{
		_pathFindingTries = 0;

		if (currentSuccessor <= shipSize)
		{
		chooseRandomAgain:

			randomHorizontalVector = (rand() % 3) - 1;
			randomVerticalVector = (rand() % 3) - 1;
			_updatedRowPosition = startingRow + randomVerticalVector;
			_updatedColumnPosition = startingColumn + randomHorizontalVector;

			if (_pathFindingTries > 100)
			{
				return false;
			}
			if (randomHorizontalVector == previousHorizontalVector && randomVerticalVector == previousVerticalVector)
			{
				_pathFindingTries++;
				goto chooseRandomAgain;
			}
			if ((randomVerticalVector == 0 && randomHorizontalVector == 0) || (randomVerticalVector == 1 && randomHorizontalVector == 1) || (randomVerticalVector == -1 && randomHorizontalVector == -1) || (randomVerticalVector == 1 && randomHorizontalVector == -1) || (randomVerticalVector == -1 && randomHorizontalVector == 1))
			{
				_pathFindingTries++;
				goto chooseRandomAgain;
			}

			if (_updatedRowPosition > 9 || _updatedColumnPosition > 9 || _updatedRowPosition < 0 || _updatedColumnPosition < 0)
			{
				_pathFindingTries++;
				goto chooseRandomAgain;
			}
			if (BotArray[_updatedRowPosition][_updatedColumnPosition] == '4' || BotArray[_updatedRowPosition][_updatedColumnPosition] == '3' || BotArray[_updatedRowPosition][_updatedColumnPosition] == '2' || BotArray[_updatedRowPosition][_updatedColumnPosition] == '1' || BotArray[_updatedRowPosition][_updatedColumnPosition] == '*')
			{
				_pathFindingTries++;
				goto chooseRandomAgain;
			}
			return true;
		}
	}
};