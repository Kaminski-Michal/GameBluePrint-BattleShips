	

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
		
		if (BotProgression)
		{

		}
		else
		{

			while (!PositionPossible)
			{
				GenerateRandomRowTarget();
				GenerateRandomColumnTarget();

				if (BotShootingAray[_rowTarget][_columnTarget] == '.')
				{
					PositionPossible = true;
				}

			}
		}
		
		isBotMovement = BotShootingAtCoordinates(_rowTarget,_columnTarget);
		PlayerMovement = !isBotMovement;
	}



};
