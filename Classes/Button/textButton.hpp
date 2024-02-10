#pragma once
#include "button.hpp"
#include "SFML/Graphics.hpp"

class textButton : public Button {
private:
	sf::Text text;
	sf::Font font;
public:
	textButton(int l, int t, int w, int h, sf::Color c, sf::Font f, std::string tx, int gap);
	void paste();




};