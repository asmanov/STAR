#pragma once
#include "Ship.h"
class Enemy3 :
    public Ship
{
public:
	Enemy3() :Ship("Cruiser", 2000, 2000, 10)
	{
		ship.setTextureRect(sf::IntRect(20, 2000, 220, 300));
		fire.setTextureRect(sf::IntRect(270, 2100, 300, 300));
		ship.rotate(180);
		fire.rotate(180);
		ship.setPosition(700.0f, 100.0f);
		fire.setPosition((ship.getPosition()).x + 2.0f, (ship.getPosition()).y - 28.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

