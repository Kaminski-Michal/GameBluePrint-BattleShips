
std::array<std::array<char, 10>, 10> BotGeneratedArray;
std::array<std::array<char, 10>, 10> BotShootingAray;
std::array<std::array<char, 10>, 10> PlayerArray;
std::array<std::array<char, 10>, 10> PlayerShootingArray;
std::array<bool, 100> BotHitThatShip = { false };
std::array<bool, 100> BotShotHere = { false };



std::array<int, 5> Bot4BlockShipInNavigationArray = {0, 0 , 0 , 0 , 0 };// [0] - how many segments got hit  [rest] - int value of position = column * 10 + row 
std::array<std::array<int, 4>, 2> Bot3BlockShipsInNavigationArray = 
{
	{
	{0, 0, 0, 0},
	{0, 0, 0, 0}
	}
};
std::array<std::array<int, 3>, 3> Bot2BlockShipsInNavigationArray =
{
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}
};
std::array<std::array<int, 2>, 4> Bot1BlockShipsInNavigationArray=
{
	{
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0}
	}
};

bool BotProgression = false;
bool BotStartProgression = false;
bool BotProgressionHitThree = false;
bool BotProgressionHitFour = false;
int _sizeOfShipInProgression = 0;
int _oneBlockRemaining = 4;
int _twoBlockRemaining = 3;
int _threeBlockRemaining = 2;
int _fourBlockRemaining = 1;


	




class Shooting
{
	int _position = 0;
public:

#pragma region BotShooting Functions
	bool BotShootingUsingProgression(int row, int column)
	{
		_position = (row * 10) + column;
		if (PlayerArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			_sizeOfShipInProgression--;
			_twoBlockRemaining--;
			BotProgression = false;
			BotHitThatShip[_position] = true;
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			_sizeOfShipInProgression--;
			if (_sizeOfShipInProgression == 0)
			{
				_threeBlockRemaining--;
			}
			BotProgressionHitThree = true;
			BotHitThatShip[_position] = true;
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			if (_sizeOfShipInProgression == 2)
			{
				BotProgressionHitFour = true;
			
			}
			BotProgressionHitThree = true;
			_sizeOfShipInProgression--;
			if (_sizeOfShipInProgression == 0)
			{
				_fourBlockRemaining--;
			}
			BotHitThatShip[_position] = true;
			return true;
		}
		else
		{
			BotShootingAray[row][column] = '*';
			BotShotHere[_position] = true;
			return false;
		}
	}
	bool BotShootingAtCoordinates(int row, int column)
	{
		_position = (row * 10) + column;
		GenerateNavigationDots Generate;
		if (PlayerArray[row][column] == '1')
		{
			_oneBlockRemaining--;
			BotShootingAray[row][column] = 'X';
			PlayerArray[row][column] = 'X';
			Generate.GenerateDots(BotShootingAray);
			BotHitThatShip[_position] = true;
			return true;
		}
		if (PlayerArray[row][column] == '2')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			BotStartProgression = true;
			_sizeOfShipInProgression = 1;
			BotHitThatShip[_position] = true;
			return true;
		}
		if (PlayerArray[row][column] == '3')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			BotStartProgression = true;
			_sizeOfShipInProgression = 2;
			BotHitThatShip[_position] = true;
			return true;
		}
		if (PlayerArray[row][column] == '4')
		{
			BotShootingAray[row][column] = '+';
			PlayerArray[row][column] = '+';
			BotStartProgression = true;
			_sizeOfShipInProgression = 3;
			BotHitThatShip[_position] = true;
			return true;
		}
		else
		{
			BotShootingAray[row][column] = '*';
			BotShotHere[_position] = true;
			return false;
		}
	}
#pragma endregion
};
