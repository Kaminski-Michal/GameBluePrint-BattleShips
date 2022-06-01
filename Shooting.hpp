array<array<char, 10>, 10> BotGeneratedArray;
array<array<char, 10>, 10> BotShootingAray;
array<array<char, 10>, 10> PlayerArray;
array<array<char, 10>, 10> PlayerShootingArray;
bool BotProgression = false;
bool BotStartProgression = false;
int _sizeOfShipInProgression = 0;

class Shooting
{





public:

	bool BotShootingUsingProgression(int row, int column)
	{
		if (PlayerArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			BotProgression = false;
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			_sizeOfShipInProgression = 1;
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			_sizeOfShipInProgression = 2;
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
		if (PlayerArray[row][column] == '1')
		{
			BotShootingAray[row][column] = 'X';
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
			//BotStartProgression = true;
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
