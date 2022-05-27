

class PathFinding : public PathFinding_SuccessorTwo
{
private:
	bool _successorTwoHavePath = true;
	bool _successorHavePath = true;
	int _pathFindingTries = 0;
	int _updatedRowPosition = 0;
	int _updatedColumnPosition = 0;
	int randomHorizontalVector = 0;
	int randomVerticalVector = 0;
	int currentSuccessor = 1;


protected:


	


	



	
public:
	
	bool VerifyPossiblePatch(array<array<char, 10>, 10>& BotArray, int startingRow, int startingColumn, int shipSize)
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
				cout << "Path notFound" << endl;
				return false;
				
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
			_successorHavePath = true;
			shipSize--;
			_successorTwoHavePath =	VerifyPossbilePatchs_SuccessorTwo(BotArray, _updatedRowPosition, _updatedColumnPosition, shipSize,randomHorizontalVector,randomVerticalVector);
			if (_successorTwoHavePath && _successorHavePath)
			{
				return true;
			}
			return false;
		}
	}







};
