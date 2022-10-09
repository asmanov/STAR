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
	string name;//�������� �������
	int defense;//��������� �������
	int cost;//��������� �������
	int lim_weapon;//����������� �� ���-�� ������ �� �����;
public:
	int arsenal;//������� �����
	sf::Texture texture;
	sf::Sprite ship;
	sf::Sprite fire;
	sf::Vector2f position;
public:
	Ship(string nameP, int defenseP, int costP, int lim): name{nameP}, defense{defenseP}, 
		cost{ costP }, lim_weapon{lim}, arsenal {0}
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
	//���������� ������ � �������
	void AddRoket()
	{
		if (arsenal < lim_weapon)
		{
			arsenal++;
		}
		else std::cout << "Arsenal is FULL!\n";
	}
	//���������� ������ �� ��������
	void extractRoket()
	{
		if (arsenal>0)
		{
			arsenal--;
		}
		else std::cout << "Arsenal is empty!\n";
	}
	//���-�� ����� � ��������
	int numberRoket()
	{
		return arsenal;
	}
	//��������� ������ �������
	void changeDefense(int change)
	{
		defense += change;
	}

};

