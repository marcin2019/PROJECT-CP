#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>


#include "Definition.h"


using namespace std;
class Movement
{
public:
	
Movement();
~Movement();

virtual int movement_objects(sf::Sprite &sprite, sf::RectangleShape &rectangle)=0;
		
};

