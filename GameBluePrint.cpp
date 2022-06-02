
#pragma region include <Library>
#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <stdbool.h>
#include <math.h>
#include <cstdlib>
using namespace std;
#pragma endregion

#pragma region VariablesDeclaration

#pragma region ShipPresentVariables
bool is4BlockShipPresent = false;
bool is3BlockShipsPresent = false;
bool is2BlockShipsPresent = false;
bool is1BlockShipsPresent = false;
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


#pragma endregion
























int main()
{
	BotMainMovementClass BotMainMovementClass;
	string testPlayerInput = "";
	Bot Bot;
	PlayerShooting PlayerShooting;
	GenerateBotShips Generate(PlayerArray); //Remove when PlayerArray added also remove isXBlockShipPresent (from file ShipGenerateClass.hpp) - made to have quick access to "Player" board and shooting at it 

		while (BotHaveRemainingShips && PlayerHaveRemainingShips)
		{

			if (isPlayerMovement)
			{
				PlayerShooting.PlayerIsShooting();
			}
			if (isBotMovement)
			{
				BotMainMovementClass.BotShootingTurn();
				Printing Printing(BotShootingAray);
			}
			
			Sleep(100);
		}
	cin >> testPlayerInput;
	ValidatePlayerInPutLocation ValidatePlayerInputLocation(testPlayerInput);
	return 0;
}



/*
 
A - 65 J-74
a - 97 j-106
0 - 48 9-57
Genertowanie statku:
Dodaæ tablicê tymczasow¹ (jakby bot chcia³ generowaæ w rogu i szuka³ kolejnej lokacji, sam siê blokuje) (niech szuka maksylanie 4 razy nowej pozycji)
ewentualnie zamiast tablicy stringa z pozycjami zajêtymi przez generowany statek, aby móg³ generowaæ w innym kierunku (mo¿e powstaæ pêtla jeœli bêdzie generowaæ w wolnej przestrzeni 2
(a chce statek 3)


pathfinding algorytm dla 3 statków (max 2 kroki do przodu)



Movement:
Array Trafionych statków, array<array,4>,1>oneBlockShipsArray;
rand() Row
rand() Column


if(bot[row][column] == 1)
{
 bool hit =true;
 bot[row][column] = X;
 

}

if(bot[row][column] == 2)
bool hit = true;
for

	for

bool Hit = true;
	if 


	if(row ==

else

hit = false;






for(Row)
{
	for(Column)
	{
		
	}
}



jeœli w kiedunku [-1;1][-1;1] niema ju¿ ¿adnej '.' (albo s¹ same [1,2,3,4,'*'])
przeskocz do innego [X,Y] z array który ma ju¿ X jako wartoœæ, 
jeœli trafienie -> zmienæ wartoœæ "1,2,3,4" w array na 'X' pêtla if sprawdzaj¹ca
czy w danym wierszu array jest jeszcze jakaœ cyfra, jeœli nie bool shipXblock drowned;
bool botHaveMove = true;

mo¿e dodaæ 1 miejsce wiêcej w array (na pocz¹tku) jako [0,1] - Drowned/Present








*/

