#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Definition.h"


using namespace std;
template <int N>
class Blocks
{

public:
	int number = N;
	int i = 0;
	Blocks();

	sf::RectangleShape block[N];
	void creating_of_blocks(sf::Texture &texture2);
	~Blocks();
};

