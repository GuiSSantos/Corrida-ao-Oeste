#pragma once
#include "SFML/Graphics.hpp"

#define ITENS_MENU 3

class Pausa
{
public:
	Pausa(float width, float height);
	~Pausa();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void setPosition(float dx, float dy);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[ITENS_MENU];

};
