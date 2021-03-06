#include <SFML/Window/Event.hpp>
#include <iostream>

#include "GameState.hpp"
#include "../ResourceHandler.hpp"

GameState::GameState(StateManager& stateManager, sf::RenderWindow& window)
: State{ stateManager, window } 
, m_entityManager{ m_window } 
, m_player{ std::make_unique<Player>(
    m_entityManager, static_cast<sf::Vector2f>(m_window.getSize())) } {
    std::cout << "[GameState] Initialized\n";

    m_entityManager.add("Player", std::move(m_player));
}

GameState::~GameState() {
    std::cout << "[GameState] Destroyed\n";
}

void GameState::pause() {

}

void GameState::resume() {

}

void GameState::processEvents() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
            m_stateManager.quit();
            break;
            case sf::Event::KeyPressed:
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                m_stateManager.quit();
                break;
            }
        }
    }
}

void GameState::update(const sf::Time& dt) {
    m_entityManager.update(dt);
}

void GameState::draw() {
    m_window.clear(sf::Color::Black);
    m_entityManager.draw();
    m_window.display();
}