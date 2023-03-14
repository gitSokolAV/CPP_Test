#include <SFML/Graphics.hpp>
#include "field.h"
#include <time.h>

using namespace sf;



int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Texture texture;
	texture.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\tiles.png");

	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	int dx = 0;
	bool rotate = 0;

	float timer = 0;
	float delay = 0.3;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up) rotate = true;
				else if (event.key.code == Keyboard::Left) dx = -1;
				else if (event.key.code == Keyboard::Right) dx = 1;
			}
		}
		//horizontal moving
		for (int i = 0; i < 4; i++)
		{
			b[i] = a[i];
			a[i].x += dx;
		}
		if (!check())
		{
			for (int i = 0; i < 4; i++)
			{
				a[i] = b[i];
			}
		}

		//rotate tetramino
		if (rotate) 
		{
			Point p = a[1]; //center rotate
			for (int i = 0; i < 4; i++)
			{
				int x = a[i].y - p.y; // y - y0
				int y = a[i].x - p.x; // x - x0
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
		}
		//moving tetramino - down
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++)
			{
				a[i].y += 1;
				timer = 0;
			}
		}
		int n = 3;
		//first tetramino?
		if (a[0].x == 0)
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}

		dx = 0;
		rotate = 0;

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