#include <SFML/Graphics.hpp>
#include "Weapon.h"

using namespace sf;

int main()
{
	Weapon roket;
	RenderWindow window(VideoMode(800, 800), "SFML Works!");

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
			roket.roket.move(1.0f, 0.0f);
		}
		// ��������� ����	
		window.clear();

		window.draw(roket.roket);
		window.display();
	}

	
	return 0;
}