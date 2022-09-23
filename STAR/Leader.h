#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Leader :
    public Ship
{
public:
	sf::Sprite m_led;
	sf::Sprite fire;

public:
	Leader() :Ship("Leader", 1000, 1000, 2)
	{
		m_led.setTexture(texture);
		fire.setTexture(texture);
		m_led.setTextureRect(sf::IntRect(25, 700, 210, 270));
		fire.setTextureRect(sf::IntRect(250, 900, 200, 200));
		m_led.setPosition(600.0f, 800.0f);
		//fire.setPosition(7.0f, 93.0f);
		fire.setPosition((m_led.getPosition()).x - 9.0f, (m_led.getPosition()).y + 58.0f);
		m_led.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

