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
			<< "��� ������ ����\t\t\t\t ==������� 0\n";
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
	//�������� �������� �������� ����
	space.loadFromFile("space.png");
	Sprite starspace;
	starspace.setTexture(space);
	_getch();
	//����� ���� ����
	RenderWindow window(VideoMode(1600, 1000), "SFML Works!");


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
		window.draw(starspace);//��������� ���� ��������� ����
		window.setMouseCursorVisible(1);//��������� ��������� ����
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