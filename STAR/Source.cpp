#include <SFML/Graphics.hpp>
#include "Weapon.h"

using namespace sf;

int main()
{
	Weapon roket;
	RenderWindow window(VideoMode(800, 800), "SFML Works!");

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
			roket.roket.move(1.0f, 0.0f);
		}
		// Отрисовка окна	
		window.clear();

		window.draw(roket.roket);
		window.display();
	}

	
	return 0;
}