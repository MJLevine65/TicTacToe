#include "SFML/Graphics.hpp"
#include "Classes/Screen/screen.h"
#include <list>
#include <iostream>
#include <filesystem>
#include "Classes/Button/button.hpp"
#include "Classes/Button/textButton.hpp"
#include "Classes/Board/board.hpp"
#include <map>
#include "Classes/Player/player.h"
#include "Classes/Player/user.hpp"
#include "Classes/Player/ai.hpp"
#include "HeyComic.h"
using namespace sf;

int main() {
    std::cout << std::filesystem::current_path() << std::endl;

    //Define Colors
    Color background_color = Color(0, 0, 255, 255);

    //Define font objects
    Font font;
    
    font.loadFromMemory(&Hey_Comic_ttf, Hey_Comic_ttf_len);
    
    int tileSize = 200;
    int tileLeft = 660;
    int tileTop = 300;
    //Define text objects
    std::list<Text*> texts;
    std::list<Text> filledTiles;
    Text xTexts[9];
    for (int i = 0; i < 9; i++) { xTexts[i] = Text("X", font, 150); xTexts[i].setPosition(tileLeft + 50 + tileSize * (i % 3), tileTop + tileSize * (i / 3)); }
    Text oTexts[9];
    for (int i = 0; i < 9; i++) { oTexts[i] = Text("O", font, 150); oTexts[i].setPosition(tileLeft + 50+ tileSize * (i % 3), tileTop + tileSize * (i / 3)); }
    Text tileNumbers[9];
    for (int i = 0; i < 9; i++) { tileNumbers[i] = Text(std::to_string(i+1), font, 15); tileNumbers[i].setPosition(tileLeft + tileSize * (i % 3), tileTop + tileSize * (i / 3)); }
    Text title = Text("Tic Tac Toe", font, 100); title.setPosition(706, 150);
    Text pick = Text("Pick X or O", font, 50); pick.setPosition(820, 400);
    Text instructions("Type corresponding number on keyboard to select", font, 20); instructions.setPosition(720, 250);
    std::cout << "here" << std::endl;
    //Define Buttons
    std::list<textButton*> textbuttons;
    textButton playButton = textButton(835, 350, 250, 150, Color(250, 0, 0, 255), font, "Play", 20);
    textButton Xbutton = textButton(1010, 500, 100, 100, Color(250, 0, 0, 255), font, "X", 20);
    textButton Obutton = textButton(810, 500, 100, 100, Color(250, 0, 0, 255), font, "O", 20);
    textButton playAgain = textButton(1300, 500, 250, 100, Color(240, 0, 0, 255), font,"Play again?", 15);

    //Define Shapes
    RectangleShape tileShapes[9];
    //Create Board Tiles
    for (int i = 0; i < 9; i++) {
        tileShapes[i] = RectangleShape(sf::Vector2f(tileSize, tileSize));
        tileShapes[i].setPosition(tileLeft + tileSize * (i % 3), tileTop + tileSize * (i / 3));
        tileShapes[i].setFillColor(Color(240, 0, 0, 255));
        tileShapes[i].setOutlineColor(Color(0, 0, 0, 255));
        tileShapes[i].setOutlineThickness(2);
    } 

    //Setup Initial conditions

    texts.push_back(&title);
    textbuttons.push_back(&playButton);
    Board gameboard = Board();
    User user;
    AI ai;

    bool showTiles = false;
    bool pressed = false;

    int choice;
    

    while (window.isOpen())
    {
        Event event;

        //Display assets
        window.clear(background_color);
        window.draw(title);
        if (showTiles) {
            window.draw(instructions);
            for (RectangleShape tile : tileShapes) { window.draw(tile); }
            for (Text num : tileNumbers) { window.draw(num); }
            for (int i = 0; i < 9; i++) {
                switch (gameboard.board[i]) {
                case 'X':
                    window.draw(xTexts[i]);
                    break;
                case 'O':
                    window.draw(oTexts[i]);
                    break;
                default:
                    break;

                }

            }
        }//Display shapes
        for (textButton* b : textbuttons) { b->check(); b->paste(); }                         //Display text buttons
        for (Text ft : filledTiles) { window.draw(ft); }                                //Display filled tile symbols
        for (Text* tx : texts) { window.draw(*tx); }                                      //Display text

        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::C)) {
                window.close();
            }
            if (Mouse::isButtonPressed(Mouse::Left) && !pressed) {
                if (playButton.hovering) {
                    textbuttons.remove(&playButton);
                    playButton.reset();
                    textbuttons.push_back(&Xbutton);
                    textbuttons.push_back(&Obutton);
                    texts.push_back(&pick);
                    pressed = true;
                }
                else if (Xbutton.hovering || Obutton.hovering) {
                    if (Xbutton.hovering) {
                        user = User('X', true);
                        ai = AI('O', false);
                    }
                    else {
                        user = User('O', true);
                        ai = AI('X', false);
                    }
                    textbuttons.remove(&Xbutton);
                    Xbutton.reset();
                    textbuttons.remove(&Obutton);
                    Obutton.reset();
                    showTiles = true;
                    texts.remove(&pick);
                    pressed = true;
                }

                else if (playAgain.hovering) {
                    textbuttons.remove(&playAgain);
                    playAgain.reset();
                    pressed = true;
                    textbuttons.clear(); textbuttons.push_back(&playButton);
                    showTiles = false;
                    textbuttons.remove(&playAgain);
                    for (int i = 0; i < 9; i++) { gameboard.board[i] = '-'; }
                    background_color = Color(0, 0, 255, 255);
                }
            }
            else if (pressed && !Mouse::isButtonPressed(Mouse::Left)) { pressed = false; }

            if (user.turn) {
              
                choice = -1;
                Keyboard::Key numkeys[9] = { Keyboard::Num1,Keyboard::Num2,Keyboard::Num3
                    ,Keyboard::Num4,Keyboard::Num5,Keyboard::Num6,Keyboard::Num7,Keyboard::Num8,Keyboard::Num9 };
       
                for (int i = 0; i < 9;i++) {
                    if (Keyboard::isKeyPressed(numkeys[i]) && gameboard.board[i] == '-') { choice = i; }

                }
      

                if (choice != -1) {
                    choice = user.play_turn(choice, &gameboard);
                    switch (choice) {
                    case 0:
                        user.turn = false; ai.turn = true;
                        break;
                    case 1:
                        background_color = Color(0, 255, 255, 255);
                        user.turn = false;
                        textbuttons.push_back(&playAgain);
                        break;
                    case 2:
                        background_color = Color(0, 255, 0, 255);
                        user.turn = false;
                        textbuttons.push_back(&playAgain);
                        break;
                    }
                }
                continue;
            }
            else if (ai.turn){
                choice = ai.play_turn(&gameboard);
                switch (choice) {
                case 0:
                    user.turn = true; ai.turn = false;
                    break;
                case 1:
                    background_color = Color(0, 255, 255, 255);
                    ai.turn = false;
                    textbuttons.push_back(&playAgain);
                    break;
                case 2:
                    background_color = Color(255, 0, 0, 255);
                    ai.turn = false;
                    textbuttons.push_back(&playAgain);
                    break;
                }
            }
        }
    }
    return 0;
}
     
        

	
    
