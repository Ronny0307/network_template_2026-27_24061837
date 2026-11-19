
#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game
{
 public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
	void keyPressed(const sf::Event::KeyPressed* event);
	void keyReleased(const sf::Event::KeyReleased* event);
	void mouseMoved(const sf::Event::MouseMoved* event);

 private:
	sf::RenderWindow& window;
	sf::Font font;
	sf::Text menu_text1{ font };
	sf::Text menu_text2{ font };
	std::shared_ptr<Board> board;
	bool menu_active = true;
	sf::Sprite* menubutton1;
	sf::Texture* menubutton1_texture;
	sf::Sprite* menubutton2;
	sf::Texture* menubutton2_texture;
};

