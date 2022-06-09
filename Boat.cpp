/*#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <array>
#include "Boat.h"

void Boat::missed(sf::RenderWindow& window, const int& p_x, const int& p_y)
{
    situation_played.setPosition(p_x, p_y);     //// Tutaj!!!!!!!
    window.draw(situation_played);
}

void Boat::filled(sf::RenderWindow& window, const int& p_x, const int& p_y)
{
    situation_filled.setPosition(p_x, p_y);
    //    window.draw(filledCase);
}

void Boat::destroyed(sf::RenderWindow& window, const int& p_x, const int& p_y)
{
    situation_explosion.setPosition(p_x, p_y);
    window.draw(situation_explosion);
}

bool Boat::checkPositionOnGrid(sf::FloatRect& gridSquare)
{
    for (int i = 0; i < boat.size(); i++)
    {
        if (gridSquare.intersects(boat[i].sprite.getGlobalBounds()))
        {
            return true;
        }
    }

    return false;
}
const sf::FloatRect Boat::getBoatPosition()
{
    for (int i = 0; i < boat.size(); i++)
    {
        return boat[i].sprite.getGlobalBounds();
    }
}
*/