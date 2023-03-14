#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Texture texture;
	texture.loadFromFile("C:\\CPP\\CPP_Test\\TetrisApp\\images\\tiles.png");

	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0,0,18, 18));

	while (window.isOpen())
	{
		//
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();

		}
		window.clear(Color::White);
		window.draw(sprite);
		window.display();
	}
	return 0;
}