
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

#pragma region GlobalVariables
bool is4BlockShipPresent = false;
bool is3BlockShipsPresent = false;
bool is2BlockShipsPresent = false;
bool is1BlockShipsPresent = false;
#pragma endregion


#pragma region include Common_.h_Files
#include "Enums.h"
#include "Printing_Board.h"
#include "SettingEmptyArray.h"
#pragma endregion

#pragma region include"BotFiles"
#include "GenerateNavigationsDots.h"
#include "PathFinding_SuccessorThree.h"
#include"PathFinding_SuccessorTwo.h"
#include "PathFinding.h"
#include "ValideteShipPosition.h"
#include "NextShipSegmentGenerator.h"
#include "Gemerate4BlockShip.h"
#include "Generate3BlockShip.h"
#include "Generate2BlockShip.h"
#include "Generate1BlockShip.h"
#pragma endregion
























int main()
{
	array<array<char, 10>, 10>BotGeneratedArray;
	FourBlockShip fourBlockShipGenerator;
	ThreeBlockShipGenerator threeBlockShipGenerator;
	TwoBlockShipGenerator twoBlockShipGenerator;
	OneBlockShipGenerator oneBlockShipGenerator;
	GenerateNavigationDots generateNavigationDots;

	GenerateEmptyArray(BotGeneratedArray);

	while (!is4BlockShipPresent || !is3BlockShipsPresent || !is2BlockShipsPresent || !is1BlockShipsPresent)
	{
		if (!is4BlockShipPresent)
		{
			fourBlockShipGenerator.Generate4BlockShip(BotGeneratedArray);
			generateNavigationDots.GenerateDots(BotGeneratedArray);
		}
		if (!is3BlockShipsPresent)
		{
			threeBlockShipGenerator.Generate3BlockShip(BotGeneratedArray);
			generateNavigationDots.GenerateDots(BotGeneratedArray);
		}
		if (!is2BlockShipsPresent)
		{
			twoBlockShipGenerator.Generate2BlockShip(BotGeneratedArray);
			generateNavigationDots.GenerateDots(BotGeneratedArray);

		}
		if (!is1BlockShipsPresent)
		{
			oneBlockShipGenerator.Generate1BlockShip(BotGeneratedArray);
			generateNavigationDots.GenerateDots(BotGeneratedArray);

		}
		PrintBoard(BotGeneratedArray);
		//Sleep(10000);
		cout << "\n\n\n" << endl;
		//system("CLS");
		}
	return 0;
}



/*
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

