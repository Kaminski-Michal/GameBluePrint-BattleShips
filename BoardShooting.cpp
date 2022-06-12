#pragma region SFML_Library
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "BoardShooting.h"

void BoardShooting::SetUp()
{
    location_square_bot_X = location_botGrid_X;
    location_square_bot_Y = location_botGrid_Y;
}
void BoardShooting::setUserGrid()
{
    for (int line = 0; line < botGridArray.size(); line++)
    {
        for (int row = 0; row < botGridArray.size(); row++)
        {
            botGridArray[line][row] = '.';
        }
    }
}
void BoardShooting::addSensorsToGrid()
{
    for (int i = 0; i < 10 * 10; i++) // po ka¿dym elemencie tablicy
    {
        if (i % 10 == 0 && i > 0 && i <= 10 * 10) {
            location_square_bot_Y += size_tile;
            location_square_bot_X = location_botGrid_X;
        }

        square_grid_bot.push_back(sf::FloatRect(sf::Vector2f(location_square_bot_X,
            location_square_bot_Y), sf::Vector2f(size_point, size_point)));

        location_square_bot_X += size_tile;
    }
}
bool BoardShooting::gridEvent(sf::RenderWindow& win)
{
    for (int i = 0; i < square_grid_bot.size(); i++)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isPressed)
        {
            /* if (square_grid_bot[i].contains(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y))
             {

                 isPressed = true;

                 if (canChangeColour)
                 {
                     _playerPlacedShipHere[i] = true;
                 }
                 CheckEachRowAndColumnsForNavigationDots();
                 return true;
             }*/
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            //Sleep(10);//remove if, return to else if (used to reduce Spam in console)
            //isPressed = false;
        }


    }

    return false;
}
std::vector<sf::RectangleShape> playerShootingTabBox;
void BoardShooting::addBoxToSquare(sf::RenderWindow& win)
{
    for (int i = 0; i < 100; i++)
    {
        playerShootingTabBox.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
        playerShootingTabBox.back().setPosition(square_grid_bot[i].left, square_grid_bot[i].top);
        playerShootingTabBox.back().setFillColor(sf::Color::Yellow);
    }

    for (int i = 0; i < playerShootingTabBox.size(); i++)
    {
        win.draw(playerShootingTabBox[i]);
    }


}