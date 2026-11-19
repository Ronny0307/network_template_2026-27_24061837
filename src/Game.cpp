
#include "Game.h"
#include "Tile.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  
}

Game::~Game()
{
    
}

bool Game::init()
{
    board = std::make_shared<Board>(window);
    board->init();   
	font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf");
	menu_text1.setString("Press 'C' to Connect to a game");
	menu_text2.setString("Press 'H' to Host a game");
	menu_text1.setFont(font);
	menu_text2.setFont(font);
	menu_text1.setPosition(sf::Vector2f(850,150));
	menu_text2.setPosition(sf::Vector2f(850,250));
	menu_active = true;

	menubutton1_texture = new sf::Texture();
	menubutton2_texture = new sf::Texture();


    return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    board->render(); 
	if (menu_active)
	{
		window.draw(menu_text1);
		window.draw(menu_text2);
	}
}

void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{

    board->mouseButtonPressed(event);

}

void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
    board->mouseButtonReleased(event);    
}

void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	if (event->scancode == sf::Keyboard::Scancode::C)
	{
		menu_active = false;
	}
	if (event->scancode == sf::Keyboard::Scancode::H)
	{
		menu_active = false;
	}
}

void Game::keyReleased(const sf::Event::KeyReleased* event)
{

}

void Game::mouseMoved(const sf::Event::MouseMoved* event)
{
    board->mouseMoved(event);
}




