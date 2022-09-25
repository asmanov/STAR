#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Transport :
    public Ship
{
public:
	/*sf::Sprite m_transport;
	sf::Sprite fire;*/

public:
	Transport():Ship("Transport", 1500, 500, 30)
	{
		ship.setTexture(texture);
		fire.setTexture(texture);
		ship.setTextureRect(sf::IntRect(25, 3000, 210, 450));
		fire.setTextureRect(sf::IntRect(300, 3200, 300, 200));
		ship.setPosition(700.0f, 700.0f);
		fire.setPosition((ship.getPosition()).x + 6.0f, (ship.getPosition()).y + 58.0f);
		ship.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

