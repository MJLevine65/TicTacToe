#pragma once
#include "SFML/Graphics.hpp"

class Button 
	{
	public:
		int left;
		int top;
		int width;
		int height;
		bool hovering;
		sf::IntRect rect;
		sf::Color color;
		sf::Color alt_color;
		sf::RectangleShape shape;
		Button();
		Button(int l, int  t, int  w, int h, sf::Color c);
		void paste();
		void reset();
		void check();





};


