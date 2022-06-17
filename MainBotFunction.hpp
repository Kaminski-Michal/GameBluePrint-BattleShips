class Bot : public Shooting
{
public:

	Bot()
	{
		GenerateBotShips GenerateBotShips(BotGeneratedArray);
		Printing Printing(BotGeneratedArray);
	}
};
