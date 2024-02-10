#include "textButton.hpp"
#include "../Classes/Screen/screen.h"
sf::Text text;
sf::Font font;
	
textButton::textButton(int l, int t, int w, int h, sf::Color c, sf::Font f, std::string tx,int gap):Button(l,t,w,h,c) {
	font = f;
	int size = 0;
	do {
		this->text = sf::Text(tx, font, ++size); 
	} while (text.getGlobalBounds().width <= width - (gap * 2) && text.getGlobalBounds().height <= height - (gap * 2));
		
	this->text.setPosition(left + gap, top );
}

void textButton::paste() {
	window.draw(this->shape);
	window.draw(this->text);

}

