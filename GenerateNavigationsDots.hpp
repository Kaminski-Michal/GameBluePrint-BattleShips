class GenerateNavigationDots 
{
	int _putDotInThisRow = 0;
	int _putDotInThisColumn = 0;
	void generateDotHere(array<array<char, 10>, 10>& generateDotsOnThisBoard)
	{
		if (generateDotsOnThisBoard[_putDotInThisRow][_putDotInThisColumn] == '.')
		{
		generateDotsOnThisBoard[_putDotInThisRow][_putDotInThisColumn] = '*';
		}
	}



	void GenerateDotsAround(array<array<char, 10>, 10>& generateDotsOnThisBoard, int rowToDotsAround, int columnToDotsAround)
	{
		for (int threeRowPositionsAbove = -1; threeRowPositionsAbove < 2; threeRowPositionsAbove++)
		{
			for (int threeColumnPositionsAbove = -1;threeColumnPositionsAbove < 2;threeColumnPositionsAbove++)
			{
				_putDotInThisRow = rowToDotsAround + threeRowPositionsAbove;
				_putDotInThisColumn = columnToDotsAround + threeColumnPositionsAbove;
				if ((_putDotInThisRow >= 0 && _putDotInThisRow <= 9) && (_putDotInThisColumn >= 0 && _putDotInThisColumn <= 9))
				{
				generateDotHere(generateDotsOnThisBoard);
				}
			}
		}

	}
	void CheckEachRow(array<array<char, 10>, 10>&lookForShipsOnThisBoard)
	{
		for (int dotingRow = 0; dotingRow < 10; dotingRow++)
		{
			CheckEachColumn(lookForShipsOnThisBoard, dotingRow);
		}
	}
	void CheckEachColumn(array<array<char, 10>, 10>&lookForShipsOnThisBoard, int dotingRow)
	{
		for (int dotingColumn = 0; dotingColumn < 10; dotingColumn++)
		{
			if (lookForShipsOnThisBoard[dotingRow][dotingColumn] == '1'|| lookForShipsOnThisBoard[dotingRow][dotingColumn] == '2'|| lookForShipsOnThisBoard[dotingRow][dotingColumn] == '3'|| lookForShipsOnThisBoard[dotingRow][dotingColumn] == '4')
			{
				GenerateDotsAround(lookForShipsOnThisBoard, dotingRow, dotingColumn);
			}


		}
	}



public:
	void GenerateDots(array<array<char, 10>, 10>&generateDotsOnThisBoard)
	{
		CheckEachRow(generateDotsOnThisBoard);



	}




};
