#pragma once
#include "../Animation.hpp"
#include "EntityManager.hpp"

class Player : public Entity {
public:
	Player(EntityManager& entityManager, sf::Vector2f& windowSize);

	void setupAnimations();
	void update(const sf::Time& dt);
private:
	EntityManager& m_entityManager;
	sf::Vector2f& m_windowSize;

	std::unique_ptr<Animation> m_animation;
};