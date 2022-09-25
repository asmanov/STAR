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
			<< "Для начала игры\t\t\t\t ==нажмите 0\n";
		std::cin >> n;
		myFleet.buyShip(n);
		
	} while (n!=0);
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
		window.draw(starspace);//отрисовка фона звездного неба
		window.setMouseCursorVisible(1);//видимость указателя мыши
		for(int i = 0; i< myFleet.fleets.size(); i++)
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