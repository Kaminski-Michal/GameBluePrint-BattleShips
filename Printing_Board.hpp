class Printing
{
	void PrintMainRow()
	{
		cout << "     ";
		for (int i: RowOfLetter)
		{
			cout << (char)i << " ";
		}
		cout << "\n\n";
	}

	void PrintColumn(array<array<char, 10>, 10>playerBoard, int Row)
	{
		for (int Column = 0; Column < 10; Column++)
		{
			cout << playerBoard[Row][Column] << " ";
		}
	}

	void PrintRow(array<array<char, 10>, 10>playerBoard)
	{
		for (int Row = 0; Row < 10; Row++)
		{
			cout << Row << "    ";
			PrintColumn(playerBoard, Row);
			cout << endl;
		}
	}

public:
	Printing(array<array<char, 10>, 10>playerBoard)
	{
		PrintMainRow();
		PrintRow(playerBoard);
	}
	
};