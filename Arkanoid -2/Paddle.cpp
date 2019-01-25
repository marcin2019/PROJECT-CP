#include "Paddle.h"



Paddle::Paddle(sf::RectangleShape &paddle):paddle(paddle)//int x) 
{
	//paddle_move = x;
}


Paddle::~Paddle()
{
}
void Paddle::createpaddle(sf::RectangleShape &paddle) {
	paddle.setSize(sf::Vector2f(150, 10));
	paddle.setPosition(sf::Vector2f(MAX_SCREEN_X / 2, MAX_SCREEN_Y - 13));
	paddle.setFillColor(sf::Color::Blue);
}

int Paddle::movement_objects(sf::Sprite &sprite,sf::RectangleShape &paddle) {
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (paddle.getPosition().x >= 0))
	{
		paddle.move(-30, 0);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (paddle.getPosition().x <= MAX_SCREEN_X - paddle.getSize().x))
	{
		paddle.move(30, 0);

	}
	return 0;
}