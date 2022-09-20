#pragma once
#include <SFML/Graphics.hpp>

class Weapon
{
private:
	int power; //мощность оружия
	int cost; //стоимость оружия
	
public:
	Weapon() : power{1000}, cost{1000}
	{
		
	}
	int getPower()
	{
		return power;
	}
	int getCost()
	{
		return cost;
	}
};

