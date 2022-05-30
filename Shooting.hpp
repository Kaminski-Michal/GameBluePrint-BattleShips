array<array<char, 10>, 10> BotGeneratedArray;
array<array<char, 10>, 10> BotShootingAray;
array<array<char, 10>, 10> PlayerArray;
array<array<char, 10>, 10> PlayerShootingArray;


class Shooting
{





public:

	bool BotShootingAtCoordinates(int row, int column)
	{
		if (BotGeneratedArray[row][column] == '1')
		{
			BotShootingAray[row][column] = 'X';
			return true;
		}
		if (BotGeneratedArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			return true;
		}
		if (BotGeneratedArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			return true;
		}
		if (BotGeneratedArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			return true;
		}


		else
		{
			BotShootingAray[row][column] = '*';
			return true;//change for false
		}
	}

};
