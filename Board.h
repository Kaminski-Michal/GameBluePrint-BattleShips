#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <array>



//#include "Boat.h"
class Board
{
public:
	Board();
	void SetUp();
	void readUserGridInfo(sf::RenderWindow&);
	void setUserGrid();
	void addSensorsToGrid();
	//void detectBoatOnGrid(Boat&);
	void setBoatOnGrid(int&, const int&);
	bool gridEvent(sf::RenderWindow&);
	//bool setBoat(int&,const char&);
	void addBoxToSquare(sf::RenderWindow&);
	std::array<std::array <char, 10>, 10> GetCompletetPlayerArray();
	bool GetConfirmationIfAllShipsArePresent(int ShipSizeToCheck);


private:
	
	std::array<std::array <char, 10>, 10> userGridArray;
	int p_x; //positionX
	int p_y; //positionY
	const int size_tile = 32; //TILESIZE
	const int location_userGrid_X = 50;//USERGRID_OFFSET_X
	const int location_userGrid_Y = 155;
	int location_square_X;//squarePositionX
	int location_square_Y;//squarePositionY
	std::vector<sf::FloatRect> square_grid; //gridSquare
	const int size_point = 16;//SENSOR_SIZE
	int x;
	int y;
	bool isPressed;
	char filled = '@';
	bool _isPlacingProgression = false;
	bool _isPlayer4BlockShipPresent = false;
	bool _isPlayer3BlockShipsPresent = false;
	bool _isPlayer2BlockShipsPresent = false;
	bool _isPlayer1BlockShipsPresent = false;

	int _Player3BlockShipsRemaining = 0;
	int _Player2BlockShipsRemaining = 0;
	int _Player1BlockShipsRemaining = 0;

	

	int _typesOfShipsPresent = 0;
	int _previousRow = 0;
	int _previousColumn = 0;
	int _PlayerprogressionRemaining = 0;
	char _shipTypeInProgression = 0;
	void ValidateInPut(int row, int column);
	void ValidatePlayerInPut(int location);
	void PlaceShipHere(int row, int column,int size);
	void StartProgressionFunction(int previousRow, int previousColumn, int size);
	bool PlaceWithProgression(int row, int column);
	void EndProgresssion();
};