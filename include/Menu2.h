#pragma once
#include "SFML/Graphics.hpp"

#define ITENS_MENU 3

class Menu2
{
public:
	Menu2(float width, float height);
	~Menu2();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[ITENS_MENU];

};
