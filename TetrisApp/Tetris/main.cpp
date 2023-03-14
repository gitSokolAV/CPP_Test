#include <SFML/Graphics.hpp>
#include "field.h"
#include <time.h>

using namespace sf;



int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Texture texture, textureBackground, textureFrame;
	texture.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\tiles.png");
	textureBackground.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\background.png");
	textureFrame.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\frame.png");

	Sprite sprite(texture), spriteBackground(textureBackground), spriteFrame(textureFrame);
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	int dx = 0;
	bool rotate = 0;
	int colorNum = 1;
	bool beginGame = true;
	int n = rand() % 7;

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
		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
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
			if (!check())
			{
				for (int i = 0; i < 4; i++)
				{
					a[i] = b[i];
				}
			}
		}
		//moving tetramino - down
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++)
			{
				b[i] = a[i];
				a[i].y += 1;
			}
			if (!check())
			{
				for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
				colorNum = 1 + rand() % 7;
				int n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}

			}
			timer = 0;

		}
	
		//first tetramino?
		if (beginGame)
		{
			beginGame = false;
			n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}

		dx = 0;
		rotate = 0;
		delay = 0.3;

		//remove line
		int k = M - 1;
		for (int i = M -1 ; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < N) k--;
		}

		window.clear(Color::White);
		window.draw(spriteBackground);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (field[i][j] == 0)continue;
				sprite.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
				sprite.setPosition(j * 18, i * 18);
				sprite.move(28, 31);
				window.draw(sprite);
			}
		}

		for (int i = 0; i < 4; i++)
		{
			sprite.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			sprite.move(28, 31);
			window.draw(sprite);
			
		}
		
		window.draw(spriteFrame);
		
		window.display();
	}
	return 0;
}