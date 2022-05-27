class Bot
{
	array<array<char, 10>, 10>BotGeneratedArray;



public:

	Bot()
	{
		GenerateBotShips GenerateBotShips(BotGeneratedArray);
		Printing Printing(BotGeneratedArray);
		BotMainMovementClass BotMainMovement;
		//system("CLS");
	}


};
