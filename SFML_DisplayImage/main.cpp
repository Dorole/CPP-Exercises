#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "SFML window");
	window.setFramerateLimit(60);

	Texture imageTexture;
	if (!imageTexture.loadFromFile("C:/Users/dorot/Desktop/C++/CPP-Exercises/SFML_DisplayImage/Eli_Tabitha.png"))
		return -1;

	Sprite imageSprite;
	imageSprite.setTexture(imageTexture);

	Vector2f targetSize(1920, 1080);
	imageSprite.setScale(
		targetSize.x / imageSprite.getLocalBounds().width,
		targetSize.y / imageSprite.getLocalBounds().height);
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.setActive();

		window.draw(imageSprite);

		window.display();

	}
}