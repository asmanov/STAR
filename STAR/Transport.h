#pragma once
//#include <SFML/Graphics.hpp>
#include "Ship.h"
class Transport :
    public Ship
{
public:
	sf::Sprite m_transport;
	sf::Sprite fire;

public:
	Transport():Ship("Transport", 1500, 500, 30)
	{
		m_transport.setTexture(texture);
		fire.setTexture(texture);
		m_transport.setTextureRect(sf::IntRect(25, 3000, 210, 450));
		fire.setTextureRect(sf::IntRect(300, 3200, 300, 200));
		m_transport.setPosition(700.0f, 700.0f);
		//fire.setPosition(7.0f, 93.0f);
		fire.setPosition((m_transport.getPosition()).x + 6.0f, (m_transport.getPosition()).y + 58.0f);
		m_transport.scale(0.3f, 0.3f);
		fire.scale(0.3f, 0.3f);
	}
};

