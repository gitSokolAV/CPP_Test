#include <SFML/Graphics.hpp>
#include "field.h"

using namespace sf;



int main()
{
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Texture texture;
	texture.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\tiles.png");

	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0,0,18, 18));
	
	int dx = 0;
	while (window.isOpen())
	{
		//
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed)
			{
				//if (event.key.code == Keyboard::Up) rotate = true;
			if (event.key.code == Keyboard::Left) dx = -1;
			else if (event.key.code == Keyboard::Right) dx = 1;
			}
		}
		//horizontal moving
		for (int i = 0; i < 4; i++) a[i].x += dx;

		int n = 3;
		//first tetramino?
		if(a[0].x == 0)
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}
		dx = 0;
		window.clear(Color::White);
		for (int i = 0; i < 4; i++)
		{
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			window.draw(sprite);
		}
		
		window.display();
	}
	return 0;
}