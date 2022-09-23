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

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			//roket.roket.move(1.0f, 0.0f);
		}
		// Отрисовка окна	
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