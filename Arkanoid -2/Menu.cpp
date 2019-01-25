#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;
Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::field_creation() {

	for (int i = 0; i < 3; i++) {
		menu_fields[i].setSize(sf::Vector2f(FIELD_X, FIELD_Y));
		menu_fields[i].setPosition(sf::Vector2f(POSITION_MENUS_BLOCKS_X, POSITION_MENUS_BLOCKS_Y*(i + 1)));
		menu_fields[i].setFillColor(sf::Color::Yellow);
	}
	//cout << menu_fields[0].getPosition().x << ":" << menu_fields[0].getPosition().y << endl;

}

void Menu::string_creation() {
	if (!font.loadFromFile("arial.ttf")) {
		cout << "ERROR" << endl;
	}
	text[0].setString("PLAY");
	text[1].setString("INSTRUCTION");
	text[2].setString("EXIT");



	for (int i = 0; i < 3; i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::Red);
		text[i].setCharacterSize(40);
		text[i].setPosition(sf::Vector2f(POSITION_MENUS_BLOCKS_X, POSITION_MENUS_BLOCKS_Y*(i + 1)));
	}

}

int Menu::location(sf::Event &event) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
		if (((event.mouseButton.x > menu_fields[0].getPosition().x) && (event.mouseButton.x< (menu_fields[0].getPosition().x + FIELD_X))) && ((event.mouseButton.y > menu_fields[0].getPosition().y) && (event.mouseButton.y < (menu_fields[0].getPosition().y + FIELD_Y))))
			return 1;

		else if (((event.mouseButton.x > POSITION_MENUS_BLOCKS_X) && (event.mouseButton.x < (POSITION_MENUS_BLOCKS_X + FIELD_X))) && ((event.mouseButton.y > POSITION_MENUS_BLOCKS_Y * 2) && (event.mouseButton.y < (POSITION_MENUS_BLOCKS_Y * 2 + FIELD_Y))))
			return 2;
		else if (((event.mouseButton.x > POSITION_MENUS_BLOCKS_X) && (event.mouseButton.x < (POSITION_MENUS_BLOCKS_X + FIELD_X))) && ((event.mouseButton.y > POSITION_MENUS_BLOCKS_Y * 3) && (event.mouseButton.y < (POSITION_MENUS_BLOCKS_Y * 3 + FIELD_Y))))
			return 3;
		else
			return 0;
	}
	else
		return -1;
}


void Menu::instruction(sf::RenderWindow &window, sf::Event &event)
{
		
		fstream file;
		file.open("Arkanoid.txt", ios::in);

		if (!file.is_open())
		{
			cout << "ERROR" << endl;
		}
		if (!font.loadFromFile("arial.ttf")) {
			cout << "ERROR" << endl;
		}
		
		int i = 0;
		while (!file.eof())
		{
			getline(file, line[i]);
			i++;
			//cout << line[0] << endl;
		
		}
		file.close();
		for (int i = 0; i < 7; i++) {
			text_instruction[i].setFont(font);
			text_instruction[i].setColor(sf::Color::White);
			text_instruction[i].setCharacterSize(20);
			text_instruction[i].setPosition(sf::Vector2f(0, 20+(20)*i));
		}
		text_instruction[7].setFont(font);
		text_instruction[7].setColor(sf::Color::White);
		text_instruction[7].setCharacterSize(20);
		text_instruction[7].setPosition(sf::Vector2f(MAX_SCREEN_X/3, MAX_SCREEN_Y-50));
		
	
}

void Menu::last_menu(string s)
{
	if (!font.loadFromFile("arial.ttf")) {
		cout << "ERROR" << endl;
	}

		text_last_menu.setString(s);
		text_last_menu.setFont(font);
		text_last_menu.setColor(sf::Color::Black);
		text_last_menu.setCharacterSize(100);
		text_last_menu.setPosition(sf::Vector2f(MAX_SCREEN_X / 4, MAX_SCREEN_Y/3));
	
}