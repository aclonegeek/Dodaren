#pragma once
#include <memory>

#include "StateManager.hpp"
#include "../Entities/EntityManager.hpp"
#include "../Entities/Player.hpp"

class GameState : public State {
public:
	GameState(StateManager& stateManager, sf::RenderWindow& window);
    ~GameState();

	void pause();
	void resume();

	void processEvents();
	void update(const sf::Time& dt);
	void draw();
private:
	EntityManager m_entityManager;

	std::unique_ptr<Player> m_player;
};
