#pragma once
#include "../Animation.hpp"
#include "EntityManager.hpp"

enum class Direction {
	LEFT,
	RIGHT
};

class Player : public Entity {
public:
	Player(EntityManager& entityManager, sf::Vector2f windowSize);

	void setupAnimations();
	void handleInput(const sf::Time& dt);
	void update(const sf::Time& dt);
private:
	void moveLeft();
	void moveRight();
	void stopMoving();

	EntityManager& m_entityManager;
	sf::Vector2f& m_windowSize;

	std::unique_ptr<Animation> m_animation;

	Direction m_facing;

	const float m_walkSpeed;

	float m_dx;
	float m_dy;
};