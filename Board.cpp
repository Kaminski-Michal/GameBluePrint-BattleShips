#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <array>
#include <Windows.h>
#include "Board.h"
#include "GenerateNavigationsDots.hpp"
#include "Enums.hpp"

//#include "Boat.h"

static int _3BlockShipInGame = 2;
static int _2BlockShipInGame = 3;
static int _1BlockShipInGame = 4;



 bool Board::GetConfirmationIfAllShipsArePresent(int ShipSizeToCheck)
{
     PlayersPlacedShips ShipToVerifyPresent = static_cast<PlayersPlacedShips>(ShipSizeToCheck);
     switch (ShipToVerifyPresent)
     {
     case OneBlockShips:

         if (_isPlayer1BlockShipsPresent)
             return true;
         else
             return false;

     case TwoBlockShips:

         if (_isPlayer2BlockShipsPresent)
             return true;
         else
             return false;

     case ThreeBlockShips:

         if (_isPlayer3BlockShipsPresent)
             return true;
         else
             return false;

     case FourBlockShips:

         if (_isPlayer4BlockShipPresent)
             return true;
         else
             return false;

     default:
         return false;
         break;
     }

    if (_isPlayer1BlockShipsPresent && _isPlayer2BlockShipsPresent && _isPlayer3BlockShipsPresent && _isPlayer4BlockShipPresent)
        return true;
    else
        return false;
}

std::array<std::array <char, 10>, 10> Board::GetCompletetPlayerArray()
{
    return userGridArray;
}



void Board::EndProgresssion()
{
    GenerateNavigationDots GenerateDotsForBot;
    if (_shipTypeInProgression == '4')
    {
        _isPlayer4BlockShipPresent = true;
        GenerateDotsForBot.GenerateDots(userGridArray);
   

    }
    else if (_shipTypeInProgression == '3')
    {
        _Player3BlockShipsRemaining++;
        if (_Player3BlockShipsRemaining == _3BlockShipInGame)
        {
            _isPlayer3BlockShipsPresent = true;
            
            
        }
    }

    else if (_shipTypeInProgression == '2')
    {
        _Player2BlockShipsRemaining++;
            if (_Player2BlockShipsRemaining == _2BlockShipInGame)
            {
                _isPlayer2BlockShipsPresent = true;
                
            }
    }
    _previousRow = 0;
    _previousColumn = 0;
    _shipTypeInProgression = 0;
    _isPlacingProgression = false;
    GenerateDotsForBot.GenerateDots(userGridArray);

   

    //Czerone pola ogwiazdkowane
    //^
}


bool Board::PlaceWithProgression(int row, int column)
{
   

    if ((_previousRow == (row -1) && _previousColumn == column))
    {
        canChangeColour = true;
        std::cout << "Down" << std::endl;
        return true;
    }
    else if ((_previousRow == (row + 1)) && (_previousColumn == column))
    {
        canChangeColour = true;
        std::cout << "Up" << std::endl;
        return true;
    }
    else if ((_previousRow == row)&& (_previousColumn == (column -1)))
    {
        canChangeColour = true;
        std::cout << "Right" << std::endl;
        return true;
    }
    else if ((_previousRow == row)&&(_previousColumn == (column +1)))
    {
        canChangeColour = true;
        std::cout << "Left" << std::endl;
        return true;
    }
    else
    {
        canChangeColour = false;
         std::cout << "Last Row was:" << _previousRow << std::endl;
        std::cout << "Last Column was:" << _previousColumn << std::endl;
        std::cout << "Damn, where is it bro?" << std::endl;
        return false;
    }
}

void Board::StartProgressionFunction(int previousRow, int previousColumn, int size)
{
    _previousRow = previousRow;
    _previousColumn = previousColumn;
    _PlayerprogressionRemaining = size - 1;
    std::cout << "Progression is:" << _PlayerprogressionRemaining << std::endl;
    _isPlacingProgression = true;

}

void Board::PlaceShipHere(int row, int column, int size)
{
    GenerateNavigationDots GenerateDotsForBot;

    _shipTypeInProgression = size + 48;//na char wiêc rozmiar statku +48 

    userGridArray[row][column] = _shipTypeInProgression;

    //Postaw stetek na tablicy symbol statku (to size)


    std::cout << userGridArray[row][column] << std::endl;
    if (size>1)
    {
        StartProgressionFunction(row, column,size);
    }
    else
    {
        _Player1BlockShipsRemaining++;
        GenerateDotsForBot.GenerateDots(userGridArray);
        //Postaw statek graficznie tutaj (statek 1blok) (gwiazdki zamieñ na czerwone pole)
    }
}

void Board::ValidateInPut(int row, int column)
{
    std::cout << "4:" << _isPlayer4BlockShipPresent << std::endl;
    std::cout << "3:" << _isPlayer3BlockShipsPresent << std::endl;
    std::cout << "2:" << _isPlayer2BlockShipsPresent << std::endl;
    std::cout << "1:" << _isPlayer1BlockShipsPresent << std::endl;
    




    

    if (_isPlacingProgression && userGridArray[row][column] == '.')
    {
        bool isPlaceble = false;
        isPlaceble = PlaceWithProgression(row, column);
        if (isPlaceble)
        {
            canChangeColour = true;
            userGridArray[row][column] = _shipTypeInProgression;
            //tutaj stawia statek

            _previousRow = row;
            _previousColumn = column;
            _PlayerprogressionRemaining--;
        }
        if (_PlayerprogressionRemaining == 0)
        {
            EndProgresssion();
        }
    }
    else if (userGridArray[row][column] == '.')
    {
        canChangeColour = true;
        std::cout << "great spot\n\n\n\n";
        if (!_isPlayer4BlockShipPresent)
        {
          PlaceShipHere(row, column, 4);
        }
        else if (!_isPlayer3BlockShipsPresent)
        {
            PlaceShipHere(row, column, 3);
        }
        else if (!_isPlayer2BlockShipsPresent)
        {
            PlaceShipHere(row, column, 2);
        }
        else if (!_isPlayer1BlockShipsPresent)
        {
            PlaceShipHere(row, column, 1);
        }
        else
        {
            return;
        }






    }
    else
    {
        canChangeColour = false;
        std::cout << "I'm gonna stop you right there\n\n\n";
    }
}

void Board::ValidatePlayerInPut(int location)
{
    static int RowZero = 0;
    if (location <= 9)
    {
        std::cout << "it's row:" << RowZero << "\nand column:" << location << std::endl;
        ValidateInPut(RowZero, location);
    }
    else
    {
        int Row = location / 10;
        int Column = location - (Row * 10);
        std::cout << "it's row:" << Row << "\nand column:" << Column << std::endl;
        ValidateInPut(Row, Column);

    }
}







Board::Board()
{}
void Board::SetUp()
{
    location_square_X = location_userGrid_X;
    location_square_Y = location_userGrid_Y;
}

void Board::setUserGrid() //tworzy tablice
{
    for (int line = 0; line < userGridArray.size(); line++)
    {
        for (int row = 0; row < userGridArray.size(); row++)
        {
            userGridArray[line][row] = '.';
        }
    }
}


//void Board::readUserGridInfo(sf::RenderWindow& window)
//{
//    for (int line = 0; line < userGridArray.size(); line++)
//    {
//        for (int row = 0; row < userGridArray.size(); row++)
//        {
//            if (userGridArray[line][row] == '@') //statek tu jest
//            {
//                p_x = row * size_tile + location_userGrid_X;
//                p_y = line * size_tile + location_userGrid_Y;
//                //  -> odwo³anie do klas ³ódki
//            }
//            else if (userGridArray[line][row] == '*') //zagrane -> nie trafione
//            {
//                p_x = row * size_tile + location_userGrid_X;
//                p_y = line * size_tile + location_userGrid_Y;
//                //  -> odwo³anie do klas ³ódki
//            }
//            else if (userGridArray[line][row] == '+')//zagrane -> trafione
//            {
//                p_x = row * size_tile + location_userGrid_X;
//                p_y = line * size_tile + location_userGrid_Y;
//                //  -> odwo³anie do klas ³ódki
//            }
//        }
//    }
//    
//}


void Board::addSensorsToGrid()
{
    for (int i = 0; i < 10 * 10; i++) // po ka¿dym elemencie tablicy
    {
        if (i % 10 == 0 && i > 0 && i <= 10 * 10) {
            location_square_Y += size_tile;
            location_square_X = location_userGrid_X;
        }

        square_grid.push_back(sf::FloatRect(sf::Vector2f(location_square_X,
            location_square_Y), sf::Vector2f(size_point, size_point)));

        location_square_X += size_tile;
    }
}


void Board::setBoatOnGrid(int& idx, const int& status)
{
    x = 0;
    y = idx;

    if (idx > 10)
    {
        x = std::abs(idx / 10);
        y = idx % 10;
    }
    if (userGridArray[x][y] != 'x') {
        if (status == '.' && userGridArray[x][y] == '@')
        {
            userGridArray[x][y] = status;
        }
        else if (status == '@')
        {
            userGridArray[x][y] = status;
        }
    }
}
std::vector<sf::RectangleShape> computerColoredBox;
void Board::addBoxToSquare(sf::RenderWindow& window)
{
    for (int i = 0; i < 100; i++)
    {
        computerColoredBox.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
        computerColoredBox.back().setPosition(square_grid[i].left, square_grid[i].top);
        if (_playerPlacedShipHere[i])
        {
            computerColoredBox.back().setFillColor(sf::Color::Green);
        }
        else if (_playerCanNotPlaceShipHere[i])
        {
            computerColoredBox.back().setFillColor(sf::Color::Red);
        }
        else
        {
        computerColoredBox.back().setFillColor(sf::Color::Blue);
        }
    }

    for (int i = 0; i < computerColoredBox.size(); i++)
    {
        window.draw(computerColoredBox[i]);
    }
}    

void Board::addBoxToSquare(sf::RenderWindow& window,bool gameInProcess, std::array<bool, 100> BotHitThatShip, std::array<bool, 100> BotShotHere)
{
    for (int i = 0; i < 100; i++)
    {
        computerColoredBox.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
        computerColoredBox.back().setPosition(square_grid[i].left, square_grid[i].top);
        
        if (BotHitThatShip[i])
        {
            computerColoredBox.back().setFillColor(sf::Color::Red);
        }
        else if (BotShotHere[i])
        {
            computerColoredBox.back().setFillColor(sf::Color::Black);
        }
        else if (_playerPlacedShipHere[i])
        {
            computerColoredBox.back().setFillColor(sf::Color::Green);
        }
        else
        {
            computerColoredBox.back().setFillColor(sf::Color::Blue);
        }
    }

    for (int i = 0; i < computerColoredBox.size(); i++)
    {
        window.draw(computerColoredBox[i]);
    }
}










void Board::CheckEachRowAndColumnsForNavigationDots()
{
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            if (userGridArray[row][column] == '*')
            {
                int location = (row * 10) + column;
                _playerCanNotPlaceShipHere[location] = true;
            }
        }
    }

}




bool Board::gridEvent(sf::RenderWindow& win)
{
    if (_Player1BlockShipsRemaining == _1BlockShipInGame)
    {
        _isPlayer1BlockShipsPresent = true;
        return NULL;
    }

    for (int i = 0; i < square_grid.size(); i++)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isPressed)
        {
            if (square_grid[i].contains(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y))
            {
                
                isPressed = true;
                ValidatePlayerInPut(i);
                if (canChangeColour)
                {
                    _playerPlacedShipHere[i] = true;
                }
                CheckEachRowAndColumnsForNavigationDots();
                return true;
            }
        }
        else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            isPressed = false;
        }

    
    }

    return false;

}