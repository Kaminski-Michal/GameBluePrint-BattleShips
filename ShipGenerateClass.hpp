

class GenerateBotShips
{
public:
	GenerateBotShips(array<array<char, 10>, 10>&BotGeneratedArray)
	{
		FourBlockShip fourBlockShipGenerator;
		ThreeBlockShipGenerator threeBlockShipGenerator;
		TwoBlockShipGenerator twoBlockShipGenerator;
		OneBlockShipGenerator oneBlockShipGenerator;
		GenerateNavigationDots generateNavigationDots;
		GenerateEmptyArray(BotGeneratedArray);
		is4BlockShipPresent = false;//Also remove this when PlayerArray added
		is3BlockShipsPresent = false;//Also remove this when PlayerArray added
		is2BlockShipsPresent = false;//Also remove this when PlayerArray added
		is1BlockShipsPresent = false;//Also remove this when PlayerArray added

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
		}
		Printing Printing(BotGeneratedArray);
	}
};
