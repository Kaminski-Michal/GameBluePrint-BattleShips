
class BotMovementShoot //: public BotMainMovementClass
{
	
	int _rowTarget = 0;
	int _columnTarget = 0;
	bool PositionPossible = false;


	void GenerateRandomRowTarget()
	{
		_rowTarget = (rand() % 10);
		_columnTarget = (rand() % 10);

	}
	void GenerateRandomColumnTarget()
	{

	}
protected:
	array<array<char, 10>, 10> BotShootingAray;


public:

	BotMovementShoot()
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



};
