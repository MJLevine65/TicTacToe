#pragma once
#include "SFML/Graphics.hpp"
#include "screen.h"
#include <iostream>
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
	Button() {};

	Button(int l,int  t,int  w, int h, sf::Color c = sf::Color(0,0,0,0)) {
		/*
		* Inputs: int left, int top, int width, int height, optional sf::Color color
		*/
		left = l; top = t; width = w; height = h;
		rect = sf::IntRect(left, top, width, height);
		hovering = true;
		color = c;
		alt_color = sf::Color(color.r, color.g, color.b, 200);
		shape = sf::RectangleShape(sf::Vector2f(width, height));
		shape.setPosition(sf::Vector2f(left, top));
		shape.setFillColor(color);
		check();
		shape.setOutlineColor(sf::Color(0, 0, 0, 255));
		shape.setOutlineThickness(2);

	}
	void paste() {
		window.draw(shape);
	}

	void reset() {
		this->hovering = false;
		shape.setFillColor(color);

	}

	void check() {
		if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
			if (!hovering) {
				hovering = true;
				shape.setFillColor(alt_color);
			}
		}
		else if (hovering) {
			hovering = false;
			shape.setFillColor(color);
		}
	}


};

class textButton : public Button {
private:
	sf::Text text;
	sf::Font font;
public:
	
	textButton(int l, int t, int w, int h, sf::Color c, sf::Font f, std::string tx,int gap):Button(l,t,w,h,c) {
		font = f;
		int size = 0;
		do {
			this->text = sf::Text(tx, font, ++size); 
		} while (text.getGlobalBounds().width <= width - (gap * 2) && text.getGlobalBounds().height <= height - (gap * 2));
		
		this->text.setPosition(left + gap, top );
	}

	void paste() {
		window.draw(this->shape);
		window.draw(this->text);

	}

};

