void GenerateEmptyArray(array<array<char, 10>, 10>& ArrayToEmpty)
{
	for (int row = 0; row < ArrayToEmpty.size(); row++)
	{
		for (int column = 0; column < ArrayToEmpty.size();column++)
		{
			ArrayToEmpty[row][column] = '.';
		}
	}
}