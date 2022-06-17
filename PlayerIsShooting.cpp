#pragma region SFML_Library
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "PlayerIsShooting.h"
#include "VirtualClassHandler.hpp"





void BoardShooting::pass2BlockArray(std::array<std::array<int, 3>, 3> &twoBlockArray)
{
    PassLocationOfTwoSizedArray(twoBlockArray);
}
void BoardShooting::pass3BlockArray(std::array<std::array<int, 4>, 2> &threeBlockArray)
{
    PassLocationOfThreeSizedArray(threeBlockArray);
}
void BoardShooting::pass4BlockArray(std::array<int, 5> &fourBlockArray)
{
    PassLocationOfFourSizedArray(fourBlockArray);

}



void BoardShooting::GenerateArrayOfExceptionsAroundDronwedShips()
{
   // int SizeOfVector = NotifyObservers::getSizeOfRememberedVector();
   int size = GetSizeOfVector();
   int  PositionToDotAround;
      

   for (int i = 0; i < size-1; i++)
   {
        PositionToDotAround = GetValueOfVector(i);
        std::cout << PositionToDotAround;
       _drownArray[PositionToDotAround] = true;
   }



   /* int columnOfDrownedShip = PositionToMarkAround % 10;
    int rowOfDrownedShip = (PositionToMarkAround - columnOfDrownedShip) / 10;
    _playerShootingArray[rowOfDrownedShip][columnOfDrownedShip] = 'X';
    _drownArray[PositionToMarkAround] = true;*/

   
}


void BoardShooting::takeBotGeneratedArray(std::array<std::array<char, 10>, 10> TakenbotArray)
{
    BotArray = TakenbotArray;
    for (int row = 0; row < _playerShootingArray.size(); row++)
    {
        for (int column = 0; column < _playerShootingArray.size(); column++)
        {
            _playerShootingArray[row][column] = '.';
        }

    }

}




void BoardShooting::SetUp()
{
    location_square_bot_X = location_botGrid_X;
    location_square_bot_Y = location_botGrid_Y;
}





void BoardShooting::addSensorsToGrid()
{
    for (int i = 0; i < 10 * 10; i++)
    {
        if (i % 10 == 0 && i > 0 && i <= 10 * 10) {
            location_square_bot_Y += size_tile;
            location_square_bot_X = location_botGrid_X;
        }

        square_grid_bot.push_back(sf::FloatRect(sf::Vector2f(location_square_bot_X,location_square_bot_Y), sf::Vector2f(size_point, size_point)));

        location_square_bot_X += size_tile;
    }
}



std::vector<sf::RectangleShape> playerShootingTabBox;
void BoardShooting::addBoxToSquare(sf::RenderWindow& win)
{
    for (int i = 0; i < 100; i++)
    {
        playerShootingTabBox.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
        playerShootingTabBox.back().setPosition(square_grid_bot[i].left, square_grid_bot[i].top);
        if (_drownArray[i])
        {
            playerShootingTabBox.back().setFillColor(sf::Color::Red);
        }
        else if (_shootPositon[i])
        {
            playerShootingTabBox.back().setFillColor(sf::Color::Black);
        }
        else if (_hitArray[i])
        {
            playerShootingTabBox.back().setFillColor(sf::Color::Magenta);
        }
        else
        playerShootingTabBox.back().setFillColor(sf::Color::Yellow);
    }

    for (int i = 0; i < playerShootingTabBox.size(); i++)
    {
        win.draw(playerShootingTabBox[i]);
    }
}


void BoardShooting::playerShootHereAfterValidation(int position, bool& isPlayerMovement)
{
    if (BotArray[_row][_column] == '1')
    {
        _playerShootingArray[_row][_column] == 'X';
        _drownArray[position] = true;
    }

    else if (BotArray[_row][_column] == '2' || BotArray[_row][_column] == '3' || BotArray[_row][_column] == '4')
    {
        _playerShootingArray[_row][_column] == '+';
        _hitArray[position] = true;
        ChooseObserverToNotify(BotArray[_row][_column], position);

        GenerateArrayOfExceptionsAroundDronwedShips();
        
    }
    else
    {
        _playerShootingArray[_row][_column] = '*';
        _shootPositon[position] = true;
        isPlayerMovement = false;
    }
    
}


void BoardShooting::ValidatePlayerInPutPosition(int positionToCheck, bool &isPlayerMovement)
{
    _column = positionToCheck % 10;
    _row = (positionToCheck - _column)/10;    
    if (_playerShootingArray[_row][_column] != '.')
    {
        return;
    }
    else
    {
        playerShootHereAfterValidation(positionToCheck, isPlayerMovement);
    }
}
bool BoardShooting::gridEvent(sf::RenderWindow& win, bool &isPlayerMovement,sf::Sprite &currentInstriction)
{
   

        for (int i = 0; i < square_grid_bot.size(); i++)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isPressed)
            {
                if (square_grid_bot[i].contains(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y))
                {
                    ValidatePlayerInPutPosition(i, isPlayerMovement);
                    return true;
                
                }
            }
            else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                isPressed = false;
            }
        }

    return false;
}






