#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Definition.h"


template <int N>
class Lines
{

	
	
public:
	//int number2 = Rectangle::number;
	sf::RectangleShape line_top[N];
	sf::RectangleShape line_bottom[N];
	sf::RectangleShape line_right[N];
	sf::RectangleShape line_left[N];

	Lines();
~Lines();
};

