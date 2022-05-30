array<array<char, 10>, 10> BotGeneratedArray;
array<array<char, 10>, 10> BotShootingAray;
array<array<char, 10>, 10> PlayerArray;
array<array<char, 10>, 10> PlayerShootingArray;
bool BotProgression = false;


class Shooting
{





public:

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
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			return true;
		}
		else
		{
			BotShootingAray[row][column] = '*';
			return false;//change for false when Player added
		}
	}

};
