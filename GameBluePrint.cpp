

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
#pragma region PlayerShipPresentVariables
bool isPlayer4BlockShipPresent = false;//1x
bool isPlayer3BlockShipsPresent = false;//2x
bool isPlayer2BlockShipsPresent = false;//3x
bool isPlayer1BlockShipsPresent = false;//4x
#pragma endregion
#pragma region BotShipPresentVariables
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
#include "InstructionPrintingClass.h"
#include "Printing_Board.hpp"
//#include "ConvertPlayerInPutLocation.hpp"
#include "Shooting.hpp"
#include "SettingEmptyArray.hpp"
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

void GlobalConfirmIfShipsArePresent()
{
	Board board;
	if (!isPlayer1BlockShipsPresent)
	{
	is1BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::OneBlockShips));
	}
	else if (!isPlayer2BlockShipsPresent)
	{
		is2BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::TwoBlockShips));
	}
	else if (!isPlayer3BlockShipsPresent)
	{
		is3BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::ThreeBlockShips));
	}
	else if (isPlayer4BlockShipPresent)
	{
		is4BlockShipPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::FourBlockShips));
	}
}




int main()
{
	Board board_1;
	board_1.setUserGrid();
	bool TypesOfShipsPresent = false;
	InstructionPrintingClass Print();
	//ShowWindow(GetConsoleWindow(), SW_HIDE); unset as comment to hide console (leaves only main game window)
	sf::RenderWindow window;
	window.create(sf::VideoMode{ 1024, 610 }, "Boards");
	//window.setFramerateLimit(0);
	sf::Event event;
	sf::Texture boardTexture;
	sf::Texture GridTexture;
	sf::Sprite board;
	sf::Sprite botgrid;
	sf::Texture instruction;
	sf::Sprite currentInstriction;
	sf::Sprite usergrid;

	boardTexture.loadFromFile("Plansze.png");
	window.display();
	board.setTexture(boardTexture);
	GridTexture.loadFromFile("net.png");

	instruction.loadFromFile("InstructionPlace4BlockShipNow.png");
	currentInstriction.setTexture(instruction);
	currentInstriction.setPosition(190,520);
	window.display();

	usergrid.setTexture(GridTexture);
	botgrid.setTexture(GridTexture);
	usergrid.setPosition(50, 150);
	botgrid.setPosition(650, 150);
	do
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
		if (!isPlayer4BlockShipPresent)
		{
			instruction.loadFromFile("InstructionPlace4BlockShipNow.png");
			currentInstriction.setTexture(instruction);
		}
		else if (!isPlayer3BlockShipsPresent)
		{
			instruction.loadFromFile("InstructionPlace3BlockShipNow.png");
			currentInstriction.setTexture(instruction);
		}
		else if (!isPlayer2BlockShipsPresent)
		{
			instruction.loadFromFile("InstructionPlace2BlockShipNow.png");
			currentInstriction.setTexture(instruction);
		}
		else if (!isPlayer1BlockShipsPresent)
		{
			instruction.loadFromFile("InstructionPlace1BlockShipNow.png");
			currentInstriction.setTexture(instruction);
		}
		window.draw(currentInstriction);
		board_1.readUserGridInfo(window);
		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window);
		window.display();
		board_1.gridEvent(window);
		
		GlobalConfirmIfShipsArePresent();


		/*void readUserGridInfo(sf::RenderWindow&);
	void setUserGrid();
	void addSensorsToGrid();
	//void detectBoatOnGrid(Boat&);
	void setBoatOnGrid(int&, const int&);
	bool gridEvent(sf::RenderWindow&);*/
	} while (!is1BlockShipsPresent && !is2BlockShipsPresent && !is3BlockShipsPresent && !is4BlockShipPresent);
	PlayerArray = board_1.GetCompletetPlayerArray();

	return 0;
}





















int XDmain()
{
	BotMainMovementClass BotMainMovementClass;
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
		std::cout << "Bot Needed: " << BotTurnsToWin << " turns to win\n";
	return 0;
}
