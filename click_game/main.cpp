#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

float SPEED = 10.0;
int FRAME_NUMBER = 0;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1600, 800), "Clicker");
    window.setFramerateLimit(30);

    Texture characterTexture1;
    GameObject::MaskedTexture(characterTexture1, "C:/mirea/c_plus_plus/click_game/click_game/data/img/nyan_cat_1.png");

    Texture characterTexture2;
    GameObject::MaskedTexture(characterTexture2, "C:/mirea/c_plus_plus/click_game/click_game/data/img/nyan_cat_2.png");

    Texture lavaTexture;
    GameObject::MaskedTexture(lavaTexture, "C:/mirea/c_plus_plus/click_game/click_game/data/img/lava.png");
    
    Texture splashTexture;
    GameObject::MaskedTexture(splashTexture, "C:/mirea/c_plus_plus/click_game/click_game/data/img/splash.png");

    Texture skyTexture;
    GameObject::MaskedTexture(skyTexture, "C:/mirea/c_plus_plus/click_game/click_game/data/img/sky.png");

    Texture stoneTexture1;
    GameObject::MaskedTexture(stoneTexture1, "C:/mirea/c_plus_plus/click_game/click_game/data/img/stone1.png");
    Texture stoneTexture2;
    GameObject::MaskedTexture(stoneTexture2, "C:/mirea/c_plus_plus/click_game/click_game/data/img/stone2.png");
    Texture stoneTexture3;
    GameObject::MaskedTexture(stoneTexture3, "C:/mirea/c_plus_plus/click_game/click_game/data/img/stone3.png");
    Texture stoneTexture4;
    GameObject::MaskedTexture(stoneTexture4, "C:/mirea/c_plus_plus/click_game/click_game/data/img/stone4.png");
    Texture stoneTexture5;
    GameObject::MaskedTexture(stoneTexture5, "C:/mirea/c_plus_plus/click_game/click_game/data/img/stone5.png");

    Sprite character;
    character.setTexture(characterTexture1);
    character.setPosition(0, window.getSize().y / 2 - character.getLocalBounds().height / 2);

    Sprite splash;
    splash.setTexture(splashTexture);
    splash.setPosition(260, window.getSize().y - 260);

    int sky_length = window.getSize().x / skyTexture.getSize().x + 2;
    Sprite* sky = new Sprite[sky_length];
    for (int i = 0; i < sky_length; i++) {
        sky[i].setTexture(skyTexture);
        sky[i].setPosition(i * sky[i].getLocalBounds().width, 0);
    }
    
    int lava_length = window.getSize().x / lavaTexture.getSize().x + 2;
    Sprite *lava = new Sprite[lava_length];
    for (int j = 0; j < lava_length; j++) {
        lava[j].setTexture(lavaTexture);
        lava[j].setPosition(j * lava[j].getLocalBounds().width, window.getSize().y - lava[j].getLocalBounds().height);
    }

    Sprite stone[5];
    stone[0].setTexture(stoneTexture1);
    stone[1].setTexture(stoneTexture2);
    stone[2].setTexture(stoneTexture3);
    stone[3].setTexture(stoneTexture4);
    stone[4].setTexture(stoneTexture5);

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
        
        for (int i = 0; i < sky_length; i++) {
            window.draw(sky[i]);
            sky[i].move(-SPEED, 0);
            if (sky[i].getPosition().x < (i - 1) * sky[i].getLocalBounds().width) {
                sky[i].setPosition(i * sky[i].getLocalBounds().width, 0);
            }
        }
        
        FRAME_NUMBER++;
        if (FRAME_NUMBER % 6 == 0 or FRAME_NUMBER % 6 == 1 or FRAME_NUMBER % 6 == 2) {
            character.setTexture(characterTexture1);
        }
        else {
            character.setTexture(characterTexture2);
        }
        window.draw(character);

        if (GameObject::CollisionsTest(character, lava))
        {
            window.draw(splash);
            SPEED = 0;
        }

        for (int j = 0; j < lava_length; j++) {
            window.draw(lava[j]);
            lava[j].move(-SPEED, 0);
            if (lava[j].getPosition().x < (j - 1) * lava[j].getLocalBounds().width) {
                lava[j].setPosition(j * lava[j].getLocalBounds().width, window.getSize().y - lava[j].getLocalBounds().height);
            }
        }

        window.display();
    }

    return 0;
}
