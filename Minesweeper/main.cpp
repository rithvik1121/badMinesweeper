#include <iostream>




#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>




#include "Square.h"
#include "Node.h"


void calculateNeighbors(std::vector<std::vector<Node>> squares)
{

	for (int i = 0; i < squares.size(); i++) 
	{
		for (int j = 0; j < squares[i].size(); j++)
		{
			
			int neighborsCount = 0;
			//top left corner
			if (i == 0)
			{
				if (j == 0) 
				{
					if (squares[1][j].getData().getIsMine())
					{
						neighborsCount++;
					}

					if (squares[0][1].getData().getIsMine())
					{
						neighborsCount++;
					}
					if (squares[1][1].getData().getIsMine())
					{
						neighborsCount++;
					}
				}
				else if (j == squares[i].size() - 1)
				{
					if (squares[i][j - 1].getData().getIsMine())
					{
						neighborsCount++;
					}

					if (squares[i + 1][j].getData().getIsMine())
					{
						neighborsCount++;
					}

					if (squares[i + 1][j - 1].getData().getIsMine())
					{
						neighborsCount++;
					}
				}
			}
			
			else if (i == squares.size()-1) {

						if (j == 0) {
							if (squares[i - 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}

							if (squares[i - 1][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}

							if (squares[i][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							else if (j == squares[i].size() - 1)
							{
								if (squares[i][j - 1].getData().getIsMine())
								{
									neighborsCount++;
								}

								if (squares[i - 1][j - 1].getData().getIsMine())
								{
									neighborsCount++;
								}

								if (squares[i - 1][j].getData().getIsMine())
								{
									neighborsCount++;
								}
							}
						}
			}

			else {
				//non-corners
				if (i >= 1 && i < squares.size() - 1) {
					//^filters out first and last rows
					if (j >= 1 && j < squares[i].size() - 1)
						//^filters out first and last columns
					{
						if (squares[i - 1][j - 1].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i - 1][j].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i - 1][j + 1].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i][j - 1].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i][j + 1].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i + 1][j - 1].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i + 1][j].getData().getIsMine())
						{
							neighborsCount++;
						}
						if (squares[i + 1][j + 1].getData().getIsMine())
						{
							neighborsCount++;
						}

					}
					//middle rows, but only first or last column
					else {
						//first column
						if (j == 0) {
							if (squares[i - 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i - 1][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
						}
						//last column
						if (j == squares[i].size() - 1)
						{
							if (squares[i - 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i - 1][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
						}
					}
				}

				else {
					if (i == 0)
					{
						if (j >= 1 && j < squares[i].size() - 1)
						{
							if (squares[i][j-1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i+1][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i + 1][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
						}
					}

					if (i == squares.size() - 1)
					{
						if (j >= 1 && j < squares[i].size() - 1)
						{
							if (squares[i][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i - 1][j - 1].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i - 1][j].getData().getIsMine())
							{
								neighborsCount++;
							}
							if (squares[i - 1][j + 1].getData().getIsMine())
							{
								neighborsCount++;
							}
						}
					}
				}
			}
			
			squares[i][j].getData().setMineCount(neighborsCount);
			std::cout << neighborsCount << ", "  << squares[i][j].getData().getMineCount() << ", " << '\n';
		}
	}
}






int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
	window.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("COMIC.TTF"))
	{
		std::cout << "Failed to read font\n";
	}


	std::vector<std::vector<Node>> squares(16);
	float x = 0.f;
	float y = 0.f;
	for (int i = 0; i < 16; i++) {
		y = 0.f;
		for (int j = 0; j < 12; j++) {
	
			Square sq(Square(x, y));
			squares[i].push_back(Node(sq, &font));
			y += 50.f;
		}
		x += 50.f;
	}

	calculateNeighbors(squares);
	//Square test_Sq(100.f, 100.f, &font);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					sf::Vector2f flpos = sf::Vector2f::Vector2(pos.x, pos.y);

					//TEST with one square
					//if (test_Sq.getGlobalBounds().contains(flpos))
					//{
					//	test_Sq.clicked();
					//}


					for (int i = 0; i < squares.size(); i++) {
						for (int j = 0; j < squares[i].size(); j++)
						{
							if (squares[i][j].getData().getGlobalBounds().contains(flpos))
							{
								squares[i][j].getData().clicked();
							}
						}
					}
				}
			}
		}

		window.clear(sf::Color::Black);

		for (int i = 0; i < squares.size(); i++) {
			for (int j = 0; j < squares[i].size(); j++)
			{
					squares[i][j].draw(&window);
			}
		}
		
		//Draw test square
		//test_Sq.draw(&window);

		window.display();
	}


	
}




