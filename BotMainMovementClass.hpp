
class BotMainMovementClass :public BotMovementShoot
{
protected:

	



public:
BotMovementShoot BotMovementShoot;
	


	BotMainMovementClass()
	{
		GenerateEmptyShootingArray();
	}
	void BotShootingTurn()
	{
		BotMovementShoot.BotMovement();
	}

	


};
