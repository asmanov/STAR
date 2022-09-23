#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Cruiser :
    public Ship
{
public:
	sf::Sprite m_cruiser;
	sf::Sprite fire;
public:
	Cruiser():Ship("Cruiser", 2000, 2000, 10)
	{
		m_cruiser.setTexture(texture);
		fire.setTexture(texture);
		m_cruiser.setTextureRect(sf::IntRect(25, 2500, 210, 450));
		fire.setTextureRect(sf::IntRect(270, 2800, 300, 200));
		m_cruiser.setPosition(500.0f, 800.0f);
		//fire.setPosition(7.0f, 93.0f);
		fire.setPosition((m_cruiser.getPosition()).x - 3.0f, (m_cruiser.getPosition()).y + 91.0f);
		m_cruiser.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
	
};

