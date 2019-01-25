#include "Counter.h"



Counter::Counter()
{
}


Counter::~Counter()
{
}

void Counter::counting(int i) {
	if (!font_counter.loadFromFile("arial.ttf")) {
		cout << "ERROR" << endl;
	}
	string tmp = to_string(i);
	text_counter.setString(tmp);

	text_counter.setFont(font_counter);
	text_counter.setColor(sf::Color::Red);
	text_counter.setCharacterSize(50);
	text_counter.setPosition(sf::Vector2f(MAX_SCREEN_X - 200, 10));

	//cout<<"Done"<<endl;
}