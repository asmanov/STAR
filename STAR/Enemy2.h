#pragma once
#include "Ship.h"
class Enemy2 :
    public Ship
{
public:
	Enemy2() :Ship("Cruiser", 2000, 2000, 10)
	{
		ship.setTextureRect(sf::IntRect(25, 1800, 210, 300));
		fire.setTextureRect(sf::IntRect(270, 1800, 300, 300));
		ship.rotate(180);
		fire.rotate(180);
		ship.setPosition(600.0f, 100.0f);
		fire.setPosition((ship.getPosition()).x + 3.0f, (ship.getPosition()).y - 0.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

