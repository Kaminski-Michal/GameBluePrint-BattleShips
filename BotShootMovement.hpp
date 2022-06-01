
GenerateNavigationDots generateNavigationDots;
int _progressionRowStart = 0;
int _progressionColumnStart = 0;


class BotMovementShoot : public Shooting, UpdatedShootPathfinding
{
	int _rowTarget = 0;
	int _columnTarget = 0;
	bool PositionPossible = false;
	
	void GenerateRandomRowTarget()
	{
		_rowTarget = (rand() % 10);
	}
	void GenerateRandomColumnTarget()
	{
		_columnTarget = (rand() % 10);
	}
	void changePlusForX()
	{
		for (int Row = 0; Row < 10; Row++)
		{
			for (int Column = 0; Column < 10; Column++)
			{
				if (BotShootingAray[Row][Column] == '+')
				{
					BotShootingAray[Row][Column] = 'X';
				}
			}
		}
	}
	



	void shootWithProgression()
	{

		SecondBlockProgression(_progressionRowStart, _progressionColumnStart, _sizeOfShipInProgression);
		_rowTarget = _SecondProgressionPositionRow;
		_columnTarget = _SecondProgressionPositionColumn;
		PositionPossible = true;
		isBotMovement = BotShootingUsingProgression(_rowTarget, _columnTarget);
		isPlayerMovement != isBotMovement;

		if (!BotProgression)
		{
			changePlusForX();
			generateNavigationDots.GenerateDots(BotShootingAray);
			_goUpSecondBlockProgression = true;
			_goDownSecondBlockProgression = true;
			_goLeftSecondBlockProgression = true;;
			_goRightSecondBlockProgression = true;

		}

	}



protected:
	int oneBlockShipDrowned = 0;
	int TwoblockShopDrowned = 0;
	int threeBlockShipDrowned = 0;
	bool areAllOneBlockShopDrowned = false;
	bool areAllTwoBlockShopDrowned = false;
	bool areAllThreeBlockShopDrowned = false;
	bool isFourBlockShopDrowned = false;

public:
	void GenerateEmptyShootingArray()
	{
		GenerateEmptyArray(BotShootingAray);
	}


	void BotMovement()
	{
		PositionPossible = false;
		
		while (!PositionPossible)
		{

			if (BotProgression)
			{
				shootWithProgression();

			}
			else 
			{
				GenerateRandomRowTarget();
				GenerateRandomColumnTarget();

				if (BotShootingAray[_rowTarget][_columnTarget] == '.')
				{
					PositionPossible = true;
					isBotMovement = BotShootingAtCoordinates(_rowTarget,_columnTarget);
				}
			}

		}
		if (BotStartProgression)
		{
			_progressionRowStart = _rowTarget;
			_progressionColumnStart = _columnTarget;
			BotProgression = true;
			BotStartProgression = false;
		}

		isPlayerMovement = !isBotMovement;
		
	}
	


};
