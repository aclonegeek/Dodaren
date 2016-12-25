#pragma once
#include <SFML/Graphics.hpp>

#include "States/StateManager.hpp"
#include "States/MenuState.hpp"

class Game {
public:
	Game() {}
	void run();
private:
	static const sf::Time TimePerFrame;

	StateManager m_stateManager;
	sf::RenderWindow m_window;
};