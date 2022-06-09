

#pragma region include <Library>
#pragma region SFML_Library
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma endregion
#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <stdbool.h>
#include <math.h>
#include <cstdlib>
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
#include "PlayerShooting.hpp"
#include "PlayerGeneratedArray.hpp"

#pragma endregion








int main()
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
