class BotMainMovementClass :public BotMovementShoot
{
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
		if (_oneBlockRemaining == 0)
		{
			areAllOneBlockShopDrowned = true;
		}
		if (_twoBlockRemaining == 0)
		{
			areAllTwoBlockShopDrowned = true;
		}
		if (_threeBlockRemaining == 0)
		{
			areAllThreeBlockShopDrowned = true;
		}
		if (_fourBlockRemaining ==0)
		{
			isFourBlockShopDrowned = true;
		}
		if (areAllOneBlockShopDrowned && areAllTwoBlockShopDrowned && areAllThreeBlockShopDrowned && isFourBlockShopDrowned)
		{
			PlayerHaveRemainingShips = false;
		}
	#pragma endregion
	}
	
	


};
