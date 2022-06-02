array<array<char, 10>, 10> BotGeneratedArray;
array<array<char, 10>, 10> BotShootingAray;
array<array<char, 10>, 10> PlayerArray;
array<array<char, 10>, 10> PlayerShootingArray;
bool BotProgression = false;
bool BotStartProgression = false;
bool BotProgressionHitThree = false;
int _sizeOfShipInProgression = 0;
int _oneBlockRemaining = 4;
int _twoBlockRemaining = 3;
int _threeBlockRemaining = 2;
int _fourBlockRemaining = 1;



class Shooting
{





public:

	bool BotShootingUsingProgression(int row, int column)
	{
		if (PlayerArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			_sizeOfShipInProgression--;
			BotProgression = false;
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			_sizeOfShipInProgression--;
			BotProgressionHitThree = true;
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			//_sizeOfShipInProgression--;
			//BotProgressionHitThree = true;
			return true;
		}
		else
		{
			BotShootingAray[row][column] = '*';
			return false;
		}

	}



	bool BotShootingAtCoordinates(int row, int column)
	{
		GenerateNavigationDots Generate;
		if (PlayerArray[row][column] == '1')
		{
			_oneBlockRemaining--;
			BotShootingAray[row][column] = 'X';
			Generate.GenerateDots(BotShootingAray);
			return true;
		}
		if (PlayerArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			BotStartProgression = true;
			_sizeOfShipInProgression = 1;
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			BotStartProgression = true;
			_sizeOfShipInProgression = 2;
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			//BotStartProgression = true;
			_sizeOfShipInProgression = 3;
			return true;
		}
		else
		{
			BotShootingAray[row][column] = '*';
			return false;
		}
	}

};
