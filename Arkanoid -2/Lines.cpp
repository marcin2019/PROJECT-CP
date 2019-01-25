#include "Lines.h"


template <int N>
Lines<N>::Lines()
{
	int i = 0;

	int a = 1;
	int b = 1;
	while (b < (MAX_SCREEN_Y - 360))
	{
		while (a < (MAX_SCREEN_X - 50)) {
			line_top[i].setSize(sf::Vector2f(X_VALUE_RECT, 1));
			line_bottom[i].setSize(sf::Vector2f(X_VALUE_RECT, 1));
			line_right[i].setSize(sf::Vector2f(1, Y_VALUE_RECT));
			line_left[i].setSize(sf::Vector2f(1, Y_VALUE_RECT));

			line_top[i].setPosition(sf::Vector2f(15 + a, 100 + b));
			line_bottom[i].setPosition(sf::Vector2f(15 + a, 100 + b + Y_VALUE_RECT));
			line_left[i].setPosition(sf::Vector2f(15 + a, 100 + b));
			line_right[i].setPosition(sf::Vector2f(15 + a + X_VALUE_RECT, 100 + b));

			//rectangle[i].setPosition(sf::Vector2f(15 + a, 100 + b));


			a += X_VALUE_RECT + 2;
			i++;
		}
		a = 1;
		b += Y_VALUE_RECT + 2;
	}
}

template <int N>
Lines<N>::~Lines()
{
}
