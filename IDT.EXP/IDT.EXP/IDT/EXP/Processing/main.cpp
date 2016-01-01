#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utility\Conversion.hpp"
#include "Utility\StandardLogger.hpp"

using namespace IDT::EXP::Utility;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");


	BaseLogger* logger = new StandardLogger();
	logger->Warning("Oh nein, Hilfe!");
	delete logger;
	logger = nullptr;


	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}