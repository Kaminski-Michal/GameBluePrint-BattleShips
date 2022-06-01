class BotMainMovementClass :public BotMovementShoot
{
protected:

	



public:
BotMovementShoot BotMovementShoot;
GenerateNavigationDots generateNavigationDots;


	BotMainMovementClass()
	{
		GenerateEmptyShootingArray();
	}
	void BotShootingTurn()
	{
		BotMovementShoot.BotMovement();

	#pragma region Verify if ships remain
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
	#pragma endregion

	}
	
	


};
