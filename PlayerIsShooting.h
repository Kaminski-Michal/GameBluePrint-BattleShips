#include <iostream>
#include <array>




class BoardShooting
{
	const int size_point = 16;
	const int size_tile = 32;
	const int location_botGrid_X = 650;
	const int location_botGrid_Y = 155;
	const static int _boardSize = 10;
	std::array<bool, 100>_shootPositon = { false };
	std::array<bool, 100>_hitArray = { false };
	std::array<bool, 100>_drownArray = { false };
	std::array<std::array<char, 10>, 10> BotArray;
	std::array<std::array<char, 10>, 10> _playerShootingArray;
	//std::array<std::array <char, 10>, 10> botGridArray;
	std::vector<sf::FloatRect> square_grid_bot;
	bool _playerHaveAcceptablePosition = false;
	bool isBotMovement = true;
	bool isPressed;
	int location_square_bot_X;
	int location_square_bot_Y;
	int BotTurnsToWin = 0;
	int _column = 0;
	int _row = 0;
	void ValidatePlayerInPutPosition(int positionToCheck, bool& isPlayerMovement);


public:

	void GenerateArrayOfExceptionsAroundDronwedShips();
	void takeBotGeneratedArray(std::array<std::array<char, 10>, 10> TakenbotArray);
	void SetUp();
	void addSensorsToGrid();
	bool gridEvent(sf::RenderWindow&, bool &isPlayerMovement, sf::Sprite &currentInstriction);
	void addBoxToSquare(sf::RenderWindow&);
	void playerShootHereAfterValidation(int position, bool& isPlayerMovement);
	void pass2BlockArray(std::array<std::array<int, 3>, 3> &twoBlockArray);
	void pass3BlockArray(std::array<std::array<int, 4>, 2> &threeBlockArray);
	void pass4BlockArray(std::array<int, 5> &fourBlockArray);

};

