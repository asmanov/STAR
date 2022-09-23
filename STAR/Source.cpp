#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include"Cruiser.h"
#include "Transport.h"
#include "Leader.h"
#include "Fleet.h"
using namespace sf;

int main()
{
	setlocale(LC_ALL, "rus");
	Fleet myFleet;
	std::cout << "\n";
	myFleet.buyShip(1);
	myFleet.buyShip(2);
	myFleet.buyShip(2);
	myFleet.buyShip(3);
	
	/*Weapon roket;
	Cruiser ship;
	Transport trans;
	Leader led;*/
	RenderWindow window(VideoMode(1800, 1000), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
			//roket.roket.move(1.0f, 0.0f);
		}
		// ��������� ����	
		window.clear();
		for(int i = 0; i< myFleet.fleets.size(); i++)
		{
			window.draw(myFleet.fleets[i].ship);
			window.draw(myFleet.fleets[i].fire);
		}
		/*window.draw(trans.m_transport);
		window.draw(trans.fire);
		window.draw(led.m_led);
		window.draw(led.fire);*/
		window.display();
	}

	
	return 0;
}