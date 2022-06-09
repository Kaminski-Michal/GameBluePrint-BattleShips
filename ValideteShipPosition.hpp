class ValideateShipPosition
{
private:
	

	
	






protected:
	bool _newPositionsAllowed = false;


public:





	
	



	void ValidateCurrentRow(std::array<std::array<char, 10>, 10> &BotArray,int row, int column)
	{
		if (row > 9 || column > 9 || row < 0 || column < 0)
		{
			_newPositionsAllowed = false;
		}
		else
		{
			if ((BotArray[row][column] != '.') || (BotArray[row][column] == '4'|| BotArray[row][column] == '3'|| BotArray[row][column] == '2'|| BotArray[row][column] == '1'))
			{
				_newPositionsAllowed = false;
			}
			else
			{
				_newPositionsAllowed = true;
			}
		}
	}
};
	
