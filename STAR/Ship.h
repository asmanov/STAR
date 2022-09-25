#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "Roket.h"
#include <iostream>
using std::list;
using std::string;
class Ship
{
protected:
	string name;//название корабля
	int defense;//прочность корабля
	int cost;//стоимость корабля
	int lim_weapon;//ограничение по кол-ву оружия на борту;
public:
	list <Roket> arsenal;//арсенал ракет
	sf::Texture texture;
	sf::Sprite ship;
	sf::Sprite fire;
	sf::Vector2f position;
public:
	Ship(string nameP, int defenseP, int costP, int lim): name{nameP}, defense{defenseP}, 
		cost{ costP }, lim_weapon{lim}, arsenal {}
	{
		texture.loadFromFile("sbot.png");
		ship.setTexture(texture);
		fire.setTexture(texture);
		ship.setPosition(1700.0f, 0.0f);
		fire.setPosition(1700.0f, 0.0f);
	}
	Ship():Ship("", 0, 0, 0)
	{

	}
	void setPos(float xP, float yP)
	{
		position.x = xP;
		position.y = yP;
	}
	int getDefense()
	{
		return defense;
	}
	int getCost()
	{
		return cost;
	}
	int getLim()
	{
		return lim_weapon;
	}
	//добавление ракеты в арсенал
	void AddRoket()
	{
		if (arsenal.size() < lim_weapon)
		{
			Roket item;
			arsenal.push_back(item);
		}
		else std::cout << "Arsenal is FULL!\n";
	}
	//извлечение ракеты из арсенала
	void extractRoket()
	{
		if (!arsenal.empty())
		{
			arsenal.pop_back();
		}
		else std::cout << "Arsenal is empty!\n";
	}
	//кол-во ракет в арсенале
	int numberRoket()
	{
		return arsenal.size();
	}
	//изменение защиты корабля
	void changeDefense(int change)
	{
		defense += change;
	}

};

