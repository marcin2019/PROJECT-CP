
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <windows.h>

#include "Blocks.cpp"
#include "Lines.cpp"

#include "Menu.h"
#include "Blocks.h"
#include "Counter.h"
#include "Lines.h"
#include "Paddle.h"
#include "Ball.h"
#include "Movement.h"
#include "Definition.h"



using namespace std;

sf::Sprite sprite2; //ball
sf::RectangleShape paddle;


double random(double upper, double lower) {
	double m;
	m = ((rand() / (static_cast<double> (RAND_MAX)))*(upper - lower) + lower);
	return m;
}

void closing_resizing(sf::RenderWindow &window, sf::Event &event) {
	
	switch (event.type) {

	case sf::Event::Closed:
		window.close();
		cout << "The window has been closed" << endl;
		break;

	case sf::Event::Resized:
		cout << "The change of size of window" << event.size.width << ":" << event.size.height << endl;
		break;

		
	}
}

void Uni(Movement *x)
{
	x->movement_objects(sprite2, paddle);
	
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(MAX_SCREEN_X, MAX_SCREEN_Y), "Arkanoid");
	window.setFramerateLimit(60);
	sf::Event event;
	srand(time(NULL));

	sf::Texture texture_menu; //background menu
	Menu menu;

	menu.field_creation(); //fields on which there are commands' text
	menu.string_creation(); //commands

		if (!texture_menu.loadFromFile("Lighthouse.jpg")) {
			cout << "Error" << endl;
		}

		sf::Sprite sprite_menu;
		sprite_menu.setTexture(texture_menu);
		sprite_menu.setScale(sf::Vector2f(1, 0.9)); 


		sf::View view2(sf::FloatRect(0, 0, MAX_SCREEN_X, MAX_SCREEN_Y));
		window.setView(view2);
		sf::Texture texture1; //background2
		sf::Texture texture2; //texture for blocks
		sf::Texture texture3; //ball

		Blocks <160> blocks;

		blocks.block;
		Lines <160>lines;
		Counter counter;

		Movement *m; //pointers used to polymorphism
		
		
		sf::Sprite sprite1;//background2
		

		Ball ball(sprite2);//sprite2);
		Paddle call_paddle(paddle);
		

		call_paddle.createpaddle(paddle);
		

		sf::View view1(sf::FloatRect(0, 0, MAX_SCREEN_X, MAX_SCREEN_Y));
		window.setView(view1);

		if (!texture1.loadFromFile("Desert.jpg")) { //background of game

			cout << "ERROR" << endl;
		}

		if (!texture2.loadFromFile("zielony.jpg")) { //texture of blocks
			cout << "ERROR" << endl;
		}

		
		

		ball.creation(texture3); //creation of ball
		blocks.creating_of_blocks(texture2);

		

		ball.parameter_of_ball(sprite2); 


		sprite1.setTexture(texture1); //texture to background of game
		sprite2.setTexture(texture3); //texture of ball
		
		
		//cout << ball.X << " : " << ball.Y << endl;


		while (window.isOpen()) 
		{

			while (window.pollEvent(event))
			{
				closing_resizing(window, event); 
				
				if ((menu.location(event) == 1)) //choice: PLAY
				{
					while (1)
					{

						while (window.pollEvent(event))
						{
							closing_resizing(window, event);
							
							m = &call_paddle; //polymorphism
							Uni(m); //polymorphism
							

						}
						
						m = &ball; //polymorphism
						Uni(m); //polymorphism
						
						if (paddle.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
						{
							ball.Y = -ball.Y;
						}

						
			
						for (int i = 0; i < blocks.number; i++)
						{
							if (sprite2.getGlobalBounds().intersects(lines.line_top[i].getGlobalBounds()) || sprite2.getGlobalBounds().intersects(lines.line_bottom[i].getGlobalBounds()))
							{
								ball.Y = -ball.Y*random(1.01, 0.99);
								blocks.block[i].setSize(sf::Vector2f(0, 0));
								lines.line_bottom[i].setSize(sf::Vector2f(0, 0));
								lines.line_top[i].setSize(sf::Vector2f(0, 0));
								lines.line_right[i].setSize(sf::Vector2f(0, 0));
								lines.line_left[i].setSize(sf::Vector2f(0, 0));
								blocks.i--;
								counter.counting(blocks.i);


								//cout << ball.Y << endl;

							}
							else if (sprite2.getGlobalBounds().intersects(lines.line_left[i].getGlobalBounds()) || sprite2.getGlobalBounds().intersects(lines.line_right[i].getGlobalBounds()))
							{
								ball.X = -ball.X*random(1.1, 0.9);
								blocks.block[i].setSize(sf::Vector2f(0, 0));
								lines.line_bottom[i].setSize(sf::Vector2f(0, 0));
								lines.line_top[i].setSize(sf::Vector2f(0, 0));
								lines.line_right[i].setSize(sf::Vector2f(0, 0));
								lines.line_left[i].setSize(sf::Vector2f(0, 0));
								blocks.i--;
								counter.counting(blocks.i);

							}
							else
								cout << endl;

							if (blocks.i == 0)
							{
								string w = "YOU WON";
								menu.last_menu(w);
								ball.X = 0;
								ball.Y = 0;

							}
							
							
						}
						
					window.clear();
					window.draw(sprite1);

					for (int i = 0; i < blocks.number; i++)
					{
						window.draw(blocks.block[i]);
					}
					
					window.draw(sprite2);
					window.draw(paddle);
					window.draw(counter.text_counter);
					if (ball.movement_objects(sprite2,paddle) == 1) 
					{
						window.draw(ball.text_last_menu);
						
					}
					if (blocks.i == 0) {
						window.draw(ball.text_last_menu);
					}
					window.display();


				}
					
			}
				



				if ((menu.location(event) == 2)) //choice: INSTRUCTION
				{
					while (1) {
						
						while (window.pollEvent(event))
						{

							closing_resizing(window, event);

							for (int i = 0; i < 7; i++) 
							{
								menu.text_instruction[i].setString(menu.line[i]);
							}
							menu.text_instruction[7].setString("Click 'Z' to come back to main menu");

							
							
							
						}
						menu.instruction(window, event);
						window.clear();
						for (int i = 0; i < 7; i++) {
							window.draw(menu.text_instruction[i]);
							
						}
						window.draw(menu.text_instruction[7]);
						window.display();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
						{	window.close();
							main();
							
						}



					}
					
				}




				if ((menu.location(event) == 3)) //choice EXIT
				{
					exit(0);
				}

			}

		
				window.clear();

				window.draw(sprite_menu);
				for (int i = 0; i < 3; i++)
				{
					window.draw(menu.menu_fields[i]);
					window.draw(menu.text[i]);
				}
				window.display();

			
		}
	
	return 0;
}
