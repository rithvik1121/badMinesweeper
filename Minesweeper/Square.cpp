#include "Square.h"
#include <iostream>



Square::Square()
{
	this->mineCount = 0;
	this->isClicked = 0;
	this->isMine = 0;
}

Square::Square(float x, float y)
{
	int min_chance = rand() % 100;

	this->isMine = 0;

	if (min_chance < 25)
	{
		this->isMine = 1;
	}

	this->square.setPosition(x, y);
	this->square.setSize(sf::Vector2f(50.f, 50.f));
	this->square.setFillColor(sf::Color(255, 125, 0, 255));
	this->square.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->square.setOutlineThickness(3.f);

	this->mineCount = 0;
	this->isClicked = false;
}

bool Square::getIsClicked()
{
	return this->isClicked;
}

bool Square::getIsMine()
{
	return this->isMine;
}

int Square::getMineCount()
{
	return this->mineCount;
}

void Square::setMineCount(int setV)
{
	this->mineCount = setV;
}

void Square::draw(sf::RenderWindow *window)
{
	window->draw(this->square);
}

void Square::clicked()
{
	this->square.setFillColor(sf::Color(120, 120, 120, 255));


	isClicked = true;


}
sf::RectangleShape Square::getSquare()
{
	return this->square;
}
sf::FloatRect Square::getGlobalBounds()
{
	return this->square.getGlobalBounds();
}

sf::FloatRect Square::getLocalBounds()
{
	return this->square.getLocalBounds();
}

