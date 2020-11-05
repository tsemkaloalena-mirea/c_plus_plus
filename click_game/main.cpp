#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

#define SPEED 5.0f

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1600, 800), "Clicker");
    window.setFramerateLimit(60);

    Texture crashTexture;
    GameObject::MaskedTexture(crashTexture, "C:/mirea/c_plus_plus/click_game/click_game/1.png");

    Texture lavaTexture;
    GameObject::MaskedTexture(lavaTexture, "C:/mirea/c_plus_plus/click_game/click_game/2.png");

    Sprite character;
    character.setTexture(crashTexture);
    character.setPosition(100, window.getSize().y / 2 - character.getLocalBounds().height / 2);

    
    
    int length = window.getSize().x / lavaTexture.getSize().x + 2;
    Sprite *lava = new Sprite[length];
    for (int i = 0; i < length; i++) {
        lava[i].setTexture(lavaTexture);
        lava[i].setPosition(i * lava[i].getLocalBounds().width, window.getSize().y - lava[i].getLocalBounds().height);
    }

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        {
            character.move(SPEED, 0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        {
            character.move(-SPEED, 0);
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up))
        {
            character.move(0, -SPEED);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
        {
            character.move(0, SPEED);
        }
        else {
            character.move(0, SPEED);
        }

        window.clear();
        if (GameObject::CollisionsTest(character, lava))
        {
            std::cout << "Collision" << std::endl;
        }
        else
        {
            std::cout << "No Collision" << std::endl;
        }

        for (int i =0; i < length; i++) {
            window.draw(lava[i]);
            lava[i].move(-SPEED, 0);
            if (lava[i].getPosition().x < (i - 1) * lava[i].getLocalBounds().width) {
                lava[i].setPosition(i * lava[i].getLocalBounds().width, window.getSize().y - lava[i].getLocalBounds().height);
            }
        }
        
        window.draw(character);

        window.display();
    }

    return 0;
}
