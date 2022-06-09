

#pragma region include <Library>
#pragma region SFML_Library
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma endregion
#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <fstream>
#include <stdbool.h>
#include <math.h>
#include <cstdlib>
#include <WinUser.h>
#pragma endregion

int BotTurnsToWin = 0;


#pragma region VariablesDeclaration

#pragma region ShipPresentVariables
bool is4BlockShipPresent = false;//1x
bool is3BlockShipsPresent = false;//2x
bool is2BlockShipsPresent = false;//3x
bool is1BlockShipsPresent = false;//4x
#pragma endregion

#pragma region BoolMovementVarables
bool isBotMovement = true;
bool isPlayerMovement = true;
bool PlayerHaveRemainingShips = true;
bool BotHaveRemainingShips = true;

#pragma endregion
#pragma endregion

#pragma region include Common_.h_Files
#include "Enums.hpp"
#include "GenerateNavigationsDots.hpp"
#include "Printing_Board.hpp"
#include "SettingEmptyArray.hpp"
#include "ConvertPlayerInPutLocation.hpp"
#include "ValidatePlayerInPutLocation.hpp"
#include "Shooting.hpp"
#pragma endregion

#pragma region BotFiles

#pragma region include "BotMovementFiles"
#include "UpdatedPathFindingProgressionShootFour.hpp"
#include "UpdatedPathFindingProgressionShootThree.hpp"
#include "UpdatedPathFindingProgressionStart.hpp"
#include "BotShootMovement.hpp"
#include "BotMainMovementClass.hpp"
#pragma endregion

#pragma region include BotReceiveShoot
#include "BotReceiveShoot.hpp"
#pragma endregion

#pragma region include "BotShipsFiles"
#include "PathFinding_SuccessorThree.hpp"
#include "PathFinding_SuccessorTwo.hpp"
#include "PathFinding.hpp"
#include "ValideteShipPosition.hpp"
#include "NextShipSegmentGenerator.hpp"
#include "Gemerate4BlockShip.hpp"
#include "Generate3BlockShip.hpp"
#include "Generate2BlockShip.hpp"
#include "Generate1BlockShip.hpp"
#include "ShipGenerateClass.hpp"
#include "MainBotFunction.hpp"
#pragma endregion

#pragma endregion

#pragma region PlayerFiles
#include "Board.h"
#include "PlayerShooting.hpp"


#pragma endregion






int main()
{
	Board board_1;
	//ShowWindow(GetConsoleWindow(), SW_HIDE); unset as comment to hide console (leaves only main game window)
	sf::RenderWindow window;
	window.create(sf::VideoMode{ 1024, 610 }, "Boards");
	//window.setFramerateLimit(0);
	sf::Event event;
	sf::Texture boardTexture;
	sf::Texture GridTexture;
	sf::Sprite board;
	sf::Sprite botgrid;
	sf::Sprite usergrid;

	boardTexture.loadFromFile("Plansze.png");
	window.display();
	board.setTexture(boardTexture);
	GridTexture.loadFromFile("net.png");

	usergrid.setTexture(GridTexture);
	botgrid.setTexture(GridTexture);
	usergrid.setPosition(50, 150);
	botgrid.setPosition(650, 150);



	while (true)
	{


		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		window.clear();
		window.draw(board);
		window.draw(usergrid);
		window.draw(botgrid);
		board_1.setUserGrid();
		board_1.readUserGridInfo(window);
		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window);
		board_1.gridEvent(window);
		window.display();
		/*void readUserGridInfo(sf::RenderWindow&);
	void setUserGrid();
	void addSensorsToGrid();
	//void detectBoatOnGrid(Boat&);
	void setBoatOnGrid(int&, const int&);
	bool gridEvent(sf::RenderWindow&);*/
	}
	return 0;
}





















int XDmain()
{
	BotMainMovementClass BotMainMovementClass;
	std::string testPlayerInput = "";
	Bot Bot;
	PlayerShooting PlayerShooting;
	GenerateBotShips Generate(PlayerArray); //Remove when PlayerArray added also remove isXBlockShipPresent (from file ShipGenerateClass.hpp) - made to have quick access to "Player" board and shooting at it 

		while (BotHaveRemainingShips && PlayerHaveRemainingShips)
		{

			if (isPlayerMovement)
			{
				PlayerShooting.PlayerIsShooting();
			}
			else
			{
				BotMainMovementClass.BotShootingTurn();
				Printing Printing(BotShootingAray);
			}
			
		}
		//edit
		std::cout << "Bot Needed: " << BotTurnsToWin << " turns to win\n";
		std::cin >> testPlayerInput;
		ValidatePlayerInPutLocation ValidatePlayerInputLocation(testPlayerInput);
	return 0;
}
