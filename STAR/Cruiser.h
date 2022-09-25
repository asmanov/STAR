#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Cruiser :
    public Ship
{
public:
	/*sf::Sprite m_cruiser;
	sf::Sprite fire;*/
	
	
public:
	Cruiser():Ship("Cruiser", 2000, 2000, 10)
	{
		/*position.x = x;
		position.y = y;*/
		ship.setTextureRect(sf::IntRect(25, 2500, 210, 450));
		fire.setTextureRect(sf::IntRect(270, 2800, 300, 200));
		ship.setPosition(500.0f, 800.0f);
		fire.setPosition((ship.getPosition()).x - 3.0f, (ship.getPosition()).y + 91.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
	
};

