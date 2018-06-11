#pragma once

#include "SFML\Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 540), "Windöw", sf::Style::Default);

	while (window.isOpen())
	{
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();

			window.clear();

			// RENDER LOOP

			// END OF RENDER LOOP
			window.display();
		}
	}

	return 0;
}