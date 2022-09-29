#include <SFML/Graphics.hpp>
#include <conio.h>
#include "Weapon.h"
#include "Fleet.h"
#include"Cruiser.h"
#include "Transport.h"
#include "Leader.h"
#include "Fleet.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
using namespace sf;

int main()
{
	setlocale(LC_ALL, "rus");
	int f = 0;
	Fleet myFleet;
	/*std::cout << "Для начала игры приобретите космические корабли для своего флота\n"
		<< "Командирский - стоимость: 1000, защита: 1000, вооруженность: 2 ракет\t == нажмите 1\n"
		<< "Крейсер - стоимость: 2000, защита: 2000, вооруженность: 10 ракет\t == нажмите 2\n"
		<< "Транспортный - стоимость: 1500, защита: 500, вооруженность: 30 ракет\t == нажмите 3\n"
		<< "Для начала игры\t\t\t\t ==нажмите 0\n";*/
	int n;
	myFleet.buyShip(1);
	do
	{
		system("cls");
		std::cout << "Для начала игры приобретите космические корабли для своего флота\n"
			<< "Командирский - стоимость: 1000, защита: 1000, вооруженность: 2 ракет\t == нажмите 1\n"
			<< "Крейсер - стоимость: 2000, защита: 2000, вооруженность: 10 ракет\t == нажмите 2\n"
			<< "Транспортный - стоимость: 1500, защита: 500, вооруженность: 30 ракет\t == нажмите 3\n"
			<< "Для начала игры\t\t\t\t\t\t ==нажмите 0\n";
		std::cin >> n;
		myFleet.buyShip(n);

	} while (n != 0);
	/*myFleet.buyShip(1);
	myFleet.buyShip(2);
	myFleet.buyShip(2);
	myFleet.buyShip(3);*/

	//Weapon roket;
	Enemy1 ship1;
	Enemy2 ship2;
	Enemy3 ship3;
	Texture space;
	//загрузка картинки звезного неба
	space.loadFromFile("space.png");
	Sprite starspace;
	starspace.setTexture(space);
	_getch();
	//вывод окна игры
	RenderWindow window(VideoMode(1600, 1000), "SFML Works!");
	float x = 0;
	float y = 0;
	// Обрабатываем очередь событий в цикле
	Event event;
	Clock clock;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		time = time / 1500;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)//событие нажатие крестика 
			{
				window.close();//закрываем окно
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (f != myFleet.fleets.size() - 1) {
				f++;
			}
			else f = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			myFleet.fleets[f].ship.move(-20.0*time, 0);
			myFleet.fleets[f].fire.move(-20.0*time, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			myFleet.fleets[f].ship.move(20.0*time, 0);
			myFleet.fleets[f].fire.move(20.0*time, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			myFleet.fleets[f].ship.move(0, -20.0 * time);
			myFleet.fleets[f].fire.move(0, -20.0 * time);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			myFleet.fleets[f].ship.move(0, 20.0 * time);
			myFleet.fleets[f].fire.move(0, 20.0 * time);
		}



		ship1.ship.move(0.0, 20.1 * time);
		ship1.fire.move(0.0, 20.1 * time);
		ship2.ship.move(0.0, 20.1 * time);
		ship2.fire.move(0.0, 20.1 * time);
		ship3.ship.move(0.0, 20.1 * time);
		ship3.fire.move(0.0, 20.1 * time);
		x = 0;
		y = 0;
		// Отрисовка окна	
		window.clear();
		window.draw(starspace);//отрисовка фона звездного неба
		window.setMouseCursorVisible(1);//видимость указателя мыши
		for (int i = 0; i < myFleet.fleets.size(); i++)
		{
			window.draw(myFleet.fleets[i].ship);
			window.draw(myFleet.fleets[i].fire);
		}

		window.draw(ship1.ship);
		window.draw(ship1.fire);
		window.draw(ship2.ship);
		window.draw(ship2.fire);
		window.draw(ship3.ship);
		window.draw(ship3.fire);
		window.display();

	}
	
	return 0;
}