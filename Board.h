#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <array>

class Board
{
public:
	std::array<std::array <char, 10>, 10> GetCompletetPlayerArray();
	Board();
	void SetUp();
	void readUserGridInfo(sf::RenderWindow&);
	void addBoxToSquare(sf::RenderWindow& window, bool gameInProcess, std::array<bool, 100> BotHitThatShip, std::array<bool, 100> BotShotHere);
	void setUserGrid();
	void addSensorsToGrid();
	void setBoatOnGrid(int&, const int&);
	void addBoxToSquare(sf::RenderWindow&);
	bool gridEvent(sf::RenderWindow&);
	bool GetConfirmationIfAllShipsArePresent(int ShipSizeToCheck);
private:
	
	const int size_tile = 32;
	const int location_userGrid_X = 50;
	const int location_userGrid_Y = 155;
	const int size_point = 16;
	bool _isPlacingProgression = false;
	bool _isPlayer4BlockShipPresent = false;
	bool _isPlayer3BlockShipsPresent = false;
	bool _isPlayer2BlockShipsPresent = false;
	bool _isPlayer1BlockShipsPresent = false;
	bool canChangeColour = false;
	bool isPressed;
	int _Player1BlockShipsRemaining = 0;
	int _Player2BlockShipsRemaining = 0;
	int _Player3BlockShipsRemaining = 0;
	int _typesOfShipsPresent = 0;
	int _previousRow = 0;
	int _previousColumn = 0;
	int _PlayerprogressionRemaining = 0;
	int p_x; 
	int p_y; 
	int location_square_X;
	int location_square_Y;
	int x;
	int y;
	char _shipTypeInProgression = 0;
	char filled = '@';
	std::array<bool, 100> _playerPlacedShipHere = { false };
	std::array<bool, 100> _playerCanNotPlaceShipHere = { false };
	std::array<std::array <char, 10>, 10> userGridArray;
	std::vector<sf::FloatRect> square_grid;

	void CheckEachRowAndColumnsForNavigationDots();
	void ValidateInPut(int row, int column);
	void ValidatePlayerInPut(int location);
	void PlaceShipHere(int row, int column,int size);
	void StartProgressionFunction(int previousRow, int previousColumn, int size);
	bool PlaceWithProgression(int row, int column);
	void EndProgresssion();
	void ChangeColourForThisBox(sf::RenderWindow& window, int pos);
};