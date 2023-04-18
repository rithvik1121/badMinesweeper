#include "Node.h"

Node::Node(Square s, sf::Font* font)
{
	this->data = s;


	sf::Vector2f pos = this->data.getSquare().getPosition();

	this->text.setPosition(pos);
	this->text.setFont(*font);

	if (this->data.getIsMine()) {
		this->text.setString("B!");

	}
	else
	{
		this->text.setString(std::to_string(this->data.getMineCount()));
	}
}

Square Node::getData()
{
	return this->data;
}

void Node::draw(sf::RenderWindow* window)
{
	this->data.draw(window);
	if (this->data.getIsClicked())
	{
		window->draw(this->text);
	}
}


