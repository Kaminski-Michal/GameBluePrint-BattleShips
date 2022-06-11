void GlobalConfirmIfShipsArePresent()
{
	Board board;
	if (!isPlayer1BlockShipsPresent)
	{
		is1BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::OneBlockShips));
	}
	else if (!isPlayer2BlockShipsPresent)
	{
		is2BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::TwoBlockShips));
	}
	else if (!isPlayer3BlockShipsPresent)
	{
		is3BlockShipsPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::ThreeBlockShips));
	}
	else if (isPlayer4BlockShipPresent)
	{
		is4BlockShipPresent = board.GetConfirmationIfAllShipsArePresent(static_cast<int>(PlayersPlacedShips::FourBlockShips));
	}
}