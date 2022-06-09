class Printing
{
	void PrintMainRow()
	{
		std::cout << "     ";
		for (int i: RowOfLetter)
		{
			std::cout << (char)i << " ";
		}
		std::cout << "\n\n";
	}

	void PrintColumn(std::array<std::array<char, 10>, 10>playerBoard, int Row)
	{
		for (int Column = 0; Column < 10; Column++)
		{
			std::cout << playerBoard[Row][Column] << " ";
		}
	}

	void PrintRow(std::array<std::array<char, 10>, 10>playerBoard)
	{
		for (int Row = 0; Row < 10; Row++)
		{
			std::cout << Row << "    ";
			PrintColumn(playerBoard, Row);
			std::cout << std::endl;
		}
	}

public:
	Printing(std::array<std::array<char, 10>, 10>playerBoard)
	{
		PrintMainRow();
		PrintRow(playerBoard);
		std::cout << "\n\n\n";
	}
	
};