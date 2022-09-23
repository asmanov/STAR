#pragma once
#include <list>
#include "Ship.h"
#include "Leader.h"
#include "Cruiser.h"
#include "Transport.h"

using std::list;



class Fleet
{
private:
	list<Ship> fleet;
	int budget;
	int experience;

public:
	Fleet(int budgetP=30000, int experienceP=0): budget(budgetP), 
		experience(experienceP), fleet{}
	{
		
	}
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
		if(budget>item->getCost())
		{
			fleet.push_back(*item);
			budget -= item->getCost();
		}
	}
};

