#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Square
{
	sf::RectangleShape square;
	int mineCount;
	bool isClicked;
	bool isMine;


public:
	Square();
	Square(float x, float y);

	int getMineCount();
	void draw(sf::RenderWindow* window);
	sf::FloatRect getGlobalBounds();
	sf::FloatRect getLocalBounds();
	void clicked();
	sf::RectangleShape getSquare();
	bool getIsMine();
	void setMineCount(int setV);
	bool getIsClicked();


};

