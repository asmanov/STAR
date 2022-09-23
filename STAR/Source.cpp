#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include"Cruiser.h"
#include "Transport.h"
#include "Leader.h"
using namespace sf;

int main()
{
	Weapon roket;
	Cruiser ship;
	Transport trans;
	Leader led;
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

		window.draw(ship.m_cruiser);
		window.draw(ship.fire);
		window.draw(trans.m_transport);
		window.draw(trans.fire);
		window.draw(led.m_led);
		window.draw(led.fire);
		window.display();
	}

	
	return 0;
}