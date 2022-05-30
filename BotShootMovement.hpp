	

class BotMovementShoot : public Shooting
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
			GenerateRandomRowTarget();
			GenerateRandomColumnTarget();



			if (BotShootingAray[_rowTarget][_columnTarget] == '.')
			{
				PositionPossible = true;
			}

		}
		if (true)
		{

		}
		
		isBotMovement = BotShootingAtCoordinates(_rowTarget,_columnTarget);
	}



};
