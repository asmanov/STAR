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
	sf::Texture texture;
public:
	Ship(string nameP, int defenseP, int costP, int lim): name{nameP}, defense{defenseP}, 
		cost{ costP }, lim_weapon{lim}, arsenal {}
	{
		texture.loadFromFile("sbot.png");
	}
	Ship():Ship("", 0, 0, 0)
	{

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
		if (arsenal.size() < lim_weapon)
		{
			Roket item;
			arsenal.push_back(item);
		}
		else std::cout << "Arsenal is FULL!\n";
	}
	//���������� ������ �� ��������
	void extractRoket()
	{
		if (!arsenal.empty())
		{
			arsenal.pop_back();
		}
		else std::cout << "Arsenal is empty!\n";
	}
	//���-�� ����� � ��������
	int numberRoket()
	{
		return arsenal.size();
	}
	//��������� ������ �������
	void changeDefense(int change)
	{
		defense += change;
	}
public:
	list <Roket> arsenal;//������� �����
};

