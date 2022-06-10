



class ValidatePlayerInPutPosition : public Board
{








public:

	ValidatePlayerInPutPosition(){}
	void ValidatePlayerInPut(int Row, int Column)
	{
		if (userGridArray[Row][Column] == '.')
		{
			std::cout << "Great Spot Nigga\n";
		}
		else
		{
			std::cout << "I'm gonna stop you right there\n";
		}




	}










};
