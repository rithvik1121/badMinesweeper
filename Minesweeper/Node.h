#pragma once
#include "Square.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Node
{
	Square data;
	sf::Text text;
	sf::Font font;


public:

	Node(Square s, sf::Font* font);
	Square getData();

	void draw(sf::RenderWindow* window);
};

