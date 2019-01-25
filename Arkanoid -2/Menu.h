#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "Definition.h"

using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	sf::Font font;
	sf::Text text[3]; //text for main menu
	sf::RectangleShape menu_fields[3];
	string line[15];
	sf::Text text_instruction[8]; 
	sf::Text text_last_menu;



	void field_creation();
	void string_creation();
	int location(sf::Event &event);
	void instruction(sf::RenderWindow &window,sf::Event &event);
	void last_menu(string s);

};

