#include "Ball.h"



Ball::Ball(sf::Sprite &ball):ball(ball)
{
}


Ball::~Ball()
{
}

void Ball::creation(sf::Texture &texture3) {
	if (!texture3.loadFromFile("ball.png")) {
		cout << "Errror" << endl;
	}
}

void Ball::parameter_of_ball(sf::Sprite &sprite2) {
	sprite2.setScale(sf::Vector2f(1.25, 1.25));
	sprite2.setPosition(sf::Vector2f(MAX_SCREEN_X / 2, (MAX_SCREEN_Y / 7) * 5));

}

int Ball::movement_objects(sf::Sprite &ball, sf::RectangleShape &rectangle){//sf::Sprite &ball) {
	ball.move(X, Y);
	sf::Vector2f vector = ball.getPosition();
	if (vector.x < 10 || vector.x>MAX_SCREEN_X - 10) X = -X;
	if (vector.y < 10) Y = -Y;
	if (vector.y > MAX_SCREEN_Y - 10) {

		X = 0;
		Y = 0;

		string s = "YOU LOST";
		
		
		last_menu(s); //inherited from menu class
		

		return 1;


	}
	
	
	return 0;
}