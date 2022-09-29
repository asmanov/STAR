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
	/*std::cout << "��� ������ ���� ����������� ����������� ������� ��� ������ �����\n"
		<< "������������ - ���������: 1000, ������: 1000, �������������: 2 �����\t == ������� 1\n"
		<< "������� - ���������: 2000, ������: 2000, �������������: 10 �����\t == ������� 2\n"
		<< "������������ - ���������: 1500, ������: 500, �������������: 30 �����\t == ������� 3\n"
		<< "��� ������ ����\t\t\t\t ==������� 0\n";*/
	int n;
	myFleet.buyShip(1);
	do
	{
		system("cls");
		std::cout << "��� ������ ���� ����������� ����������� ������� ��� ������ �����\n"
			<< "������������ - ���������: 1000, ������: 1000, �������������: 2 �����\t == ������� 1\n"
			<< "������� - ���������: 2000, ������: 2000, �������������: 10 �����\t == ������� 2\n"
			<< "������������ - ���������: 1500, ������: 500, �������������: 30 �����\t == ������� 3\n"
			<< "��� ������ ����\t\t\t\t\t\t ==������� 0\n";
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
	//�������� �������� �������� ����
	space.loadFromFile("space.png");
	Sprite starspace;
	starspace.setTexture(space);
	_getch();
	//����� ���� ����
	RenderWindow window(VideoMode(1600, 1000), "SFML Works!");
	float x = 0;
	float y = 0;
	// ������������ ������� ������� � �����
	Event event;
	Clock clock;
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		time = time / 1500;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)//������� ������� �������� 
			{
				window.close();//��������� ����
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
		// ��������� ����	
		window.clear();
		window.draw(starspace);//��������� ���� ��������� ����
		window.setMouseCursorVisible(1);//��������� ��������� ����
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