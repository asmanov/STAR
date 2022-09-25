#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Leader :
    public Ship
{
public:
	Leader() :Ship("Leader", 1000, 1000, 2)
	{
		ship.setTexture(texture);
		fire.setTexture(texture);
		ship.setTextureRect(sf::IntRect(25, 700, 210, 270));
		fire.setTextureRect(sf::IntRect(250, 900, 200, 200));
		ship.setPosition(600.0f, 800.0f);
		//fire.setPosition(7.0f, 93.0f);
		fire.setPosition((ship.getPosition()).x - 9.0f, (ship.getPosition()).y + 58.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

