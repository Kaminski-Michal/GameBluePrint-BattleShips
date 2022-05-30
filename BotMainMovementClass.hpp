
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

		if (oneBlockShipDrowned == 4)
		{
			areAllOneBlockShopDrowned = true;
		}
		if (TwoblockShopDrowned == 3)
		{
			areAllTwoBlockShopDrowned = true;
		}
		if (threeBlockShipDrowned == 2)
		{
			areAllThreeBlockShopDrowned = true;
		}
		if (areAllOneBlockShopDrowned || areAllTwoBlockShopDrowned || areAllThreeBlockShopDrowned || isFourBlockShopDrowned)
		{
			PlayerHaveRemainingShips = false;
		}

	}

	


};
