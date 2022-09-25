#pragma once
#include "Ship.h"
class Enemy1 :
    public Ship
{
public:
	Enemy1() :Ship("Cruiser", 2000, 2000, 10)
	{
		ship.setTextureRect(sf::IntRect(25, 500, 210, 270));
		fire.setTextureRect(sf::IntRect(250, 600, 300, 200));
		ship.rotate(180);
		fire.rotate(180);
		ship.setPosition(500.0f, 100.0f);
		fire.setPosition((ship.getPosition()).x + 10.0f, (ship.getPosition()).y - 30.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

