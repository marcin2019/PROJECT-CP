#include "Blocks.h"
#include <iostream>

using namespace std;


template <int N>
Blocks<N>::Blocks()
{
}

template <int N>
Blocks<N>::~Blocks()
{
}
template <int N>
void Blocks<N>::creating_of_blocks(sf::Texture &texture2) {
	int a = 1;
	int b = 1;

	while (b < (MAX_SCREEN_Y - 360))
	{
		while (a < (MAX_SCREEN_X - 50)) {
			block[i].setSize(sf::Vector2f(X_VALUE_RECT, Y_VALUE_RECT));
			block[i].setPosition(sf::Vector2f(15 + a, 100 + b));
			block[i].setTexture(&texture2);
			a += X_VALUE_RECT + 2;
			i++;
		}
		a = 1;
		b += Y_VALUE_RECT + 2;
	}
	//cout << i << endl;

}