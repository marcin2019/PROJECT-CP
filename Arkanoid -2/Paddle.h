#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Movement.h"
#include "Definition.h"

using namespace std;
class Paddle:public Movement
{
	int paddle_move;
	

public:
sf::RectangleShape paddle;
	Paddle(sf::RectangleShape &paddle);//int);
~Paddle();
void createpaddle(sf::RectangleShape &paddle);

virtual int movement_objects(sf::Sprite &sprite,sf::RectangleShape &paddle);


};

