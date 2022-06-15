#include <iostream>
#include <array>

class BoardShooting
{
	std::array<bool, 100>_shootPositon = { false };
	std::array<bool, 100>_hitArray = { false };
	std::array<std::array<char, 10>, 10> BotArray;
	bool _playerHaveAcceptablePosition = false;
	const int location_botGrid_X = 650;
	const int location_botGrid_Y = 155;
	int location_square_bot_X;
	int location_square_bot_Y;
	std::array<std::array <char, 10>, 10> botGridArray;
	bool isBotMovement = true;
	bool isPlayerMovement = true;
	int BotTurnsToWin = 0;
	const int size_tile = 32;
	std::vector<sf::FloatRect> square_grid_bot;
	const int size_point = 16;
	bool isPressed;
	void ValidatePlayerInPutPosition(int positionToCheck);
	int _column = 0;
	int _row = 0;



public:
	const static int _boardSize = 10;
	void takeBotGeneratedArray(std::array<std::array<char, 10>, 10> TakenbotArray);
	void SetUp();
	void setUserGrid();
	void addSensorsToGrid();
	bool gridEvent(sf::RenderWindow&, bool &isPlayerMovement, sf::Sprite &currentInstriction);
	void addBoxToSquare(sf::RenderWindow&);
	void playerShootHereAfterValidation(int position);



};

