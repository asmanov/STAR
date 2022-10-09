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
#include <list>
using namespace sf;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int f = 0;
	Fleet myFleet; //создаем флот игрока 
	int n;
	myFleet.buyShip(1);//добавляе в флот обязательный командирский корабль
	do
	{
		system("cls");
		std::cout << "Для начала игры приобретите космические корабли для своего флота\n"
			<< "Командирский - стоимость: 1000, защита: 1000, вооруженность: 2 ракет\t == нажмите 1\n"
			<< "Крейсер - стоимость: 2000, защита: 2000, вооруженность: 10 ракет\t == нажмите 2\n"
			<< "Транспортный - стоимость: 1500, защита: 500, вооруженность: 30 ракет\t == нажмите 3\n"
			<< "Для начала игры\t\t\t\t\t\t ==нажмите 0\n";
		std::cin >> n;
		myFleet.buyShip(n); //покупка кораблей в свой флот

	} while (n != 0);
	Fleet EnemyFleet;

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

	vector <Roket> ar; //выпущенные ракеты

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//рандомное добавление кораблей во вражеский флот
		if (EnemyFleet.fleets.empty())
		{
			int en = rand() % 5;
			for (int i = 0; i < en; i++)
			{
				int s = 4 + rand() % 2;
				EnemyFleet.buyShip(s);
			}
		}
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
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (f != 0) {
				f--;
			}
			else f = myFleet.fleets.size() - 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			myFleet.fleets[f].ship.move(-30.0*time, 0);
			myFleet.fleets[f].fire.move(-30.0*time, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			myFleet.fleets[f].ship.move(30.0*time, 0);
			myFleet.fleets[f].fire.move(30.0*time, 0);
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
		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			Roket roket;
			roket.roket.setPosition(myFleet.fleets[f].ship.getPosition().x,
				myFleet.fleets[f].ship.getPosition().y+10);
			ar.push_back(roket);
			//std::cout << "shout :" << ar.size() << "\n";
		}
		
		for (int i = 0; i < ar.size(); i++)
		{
			ar[i].roket.move(0.0, -80.1 * time);
		}

		for (int i = 0; i < EnemyFleet.fleets.size(); i++)
		{
			EnemyFleet.fleets[i].ship.move(0.0, 20.1 * time);
			EnemyFleet.fleets[i].fire.move(0.0, 20.1 * time);
		}
		//проверка попадания ракеты в корабль
		for (int i = 0; i < EnemyFleet.fleets.size(); i++)
		{
			for (int k = 0; k < ar.size(); k++)
			{
				//std::cout << "shout :" << ar.size() << "\n";
				Vector2f roket_position;
				roket_position = ar[k].roket.getPosition();
				Vector2f en_ship_position;
				en_ship_position = EnemyFleet.fleets[i].ship.getPosition();
				if (roket_position.x<= en_ship_position.x &&
					roket_position.x > (en_ship_position.x-100) &&
					roket_position.y <= en_ship_position.y &&
					roket_position.y > (en_ship_position.y-5))
				{
					EnemyFleet.fleets[i].changeDefense(-(ar[k].getPower()));
					ar.erase(ar.begin()+k);
					std::cout << "Enemy shep defence: " << i << "\t" << EnemyFleet.fleets[i].getDefense() << "\n";
					
					
					std::cout << roket_position.x << "\t\t" << en_ship_position.x << "\n";
					std::cout << roket_position.y << "\t\t" << en_ship_position.y << "\n";

				}
				
			}
			if (EnemyFleet.fleets[i].getDefense() <= 0)
			{
				EnemyFleet.fleets.erase(EnemyFleet.fleets.begin() + i);
			}
		}


		x = 0;
		y = 0;
		// Отрисовка окна	
		window.clear();
		window.draw(starspace);//отрисовка фона звездного неба
		window.setMouseCursorVisible(1);//видимость указателя мыши
		if (!(EnemyFleet.fleets.empty()))
		{
			for (int i = 0; i < EnemyFleet.fleets.size(); i++)
			{


				window.draw(EnemyFleet.fleets[i].ship);
				window.draw(EnemyFleet.fleets[i].fire);

			}
		}
		if (!myFleet.fleets.empty())
		{
			for (int i = 0; i < myFleet.fleets.size(); i++)
			{
				window.draw(myFleet.fleets[i].ship);
				window.draw(myFleet.fleets[i].fire);
			}
		}
		if(!(ar.empty()))
		{
			for (int i = 0; i < ar.size(); i++)
			{
				window.draw(ar[i].roket);
			}
		}
				
		window.display();

		
	}
	
	return 0;
}