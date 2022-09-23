#pragma once
#include <vector>
#include "Ship.h"
#include "Leader.h"
#include "Cruiser.h"
#include "Transport.h"

using std::vector;



class Fleet : public Ship, Leader, Cruiser, Transport
{
private:
	
	int budget;
	int experience;
public:
	vector<Ship> fleets;
public:
	Fleet(int budgetP=30000, int experienceP=0): budget(budgetP), 
		experience(experienceP), fleets{}
	{
		fleets.reserve(1);
	}
	//покупка корабля
	void buyShip(int n)
	{
		Ship* item = new Ship;
		switch (n)
		{
		case 1:
			item = new Leader;
			break;
		case 2:
			item = new Cruiser;
			break;
		case 3:
			item = new Transport;
			break;
		default:
			break;
		}
		if (budget > item->getCost())
		{
			fleets.push_back(*item);
			budget -= item->getCost();
		}
		else std::cout << "You haven`t money.\n";
	}
	/*Ship getShip(int i)
	{
		return  0;
	}*/

	//Покупка ракет
	void BuyRoket()
	{
	
	}
	int getBudget()
	{
		return budget;
	}
	int getExperience()
	{
		return experience;
	}
	void setExp(int exp)
	{
		experience += exp;
	}
	
};

