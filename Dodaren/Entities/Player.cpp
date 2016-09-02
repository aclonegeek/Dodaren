#include "Player.hpp"

Player::Player(EntityManager& entityManager, sf::Vector2f& windowSize)
	: m_entityManager{ entityManager }
	, m_windowSize{ windowSize } {
	m_active = 1;
	m_type = "Player";
	load(Textures::ID::Player, "Resources/Graphics/Sprites/spritesheet.png");

	m_animation = std::make_unique<Animation>(
		m_sprite, 0.10f, 0, 0, 32, 32, 300, 300);
	setupAnimations();
}

void Player::setupAnimations() {
	m_animation->add("WalkLeft", 3, 0, 32, 32, 32);
	m_animation->add("WalkRight", 3, 0, 64, 32, 32);
}

void Player::update(const sf::Time& dt) {
	m_animation->play("WalkRight", dt);
}