#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"
class Roket :
    public Weapon
{
public:
	sf::CircleShape roket;
public:
	Roket():Weapon()
	{
		roket.setRadius(5.0);
		roket.setFillColor(sf::Color::Red);
	}

};

