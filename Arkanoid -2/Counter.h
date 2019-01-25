#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Definition.h"


using namespace std;
class Counter
{
public:
	Counter();
	~Counter();
	sf::Text text_counter;
	sf::Font font_counter;
	void counting(int i);
};

