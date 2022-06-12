#include <array>


class BoardShooting
{
public:


	void SetUp();
	void setUserGrid();
	void addSensorsToGrid();
	bool gridEvent(sf::RenderWindow&);
	void addBoxToSquare(sf::RenderWindow&);


private:
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
};

