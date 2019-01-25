#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Movement.h"
#include "Menu.h"
#include "Definition.h"


using namespace std;

class Ball:public Movement,public Menu
{
public:
	sf::Sprite ball;
	Ball(sf::Sprite &ball);
	~Ball();

	float X = 1;
	float Y = 2;

	
	
	void creation(sf::Texture &texture3);
	void parameter_of_ball(sf::Sprite &sprite2);

	virtual int movement_objects(sf::Sprite &ball, sf::RectangleShape &rectangle);//sf::Sprite &sprite2);
};

