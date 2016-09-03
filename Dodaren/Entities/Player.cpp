#include "Player.hpp"

#include <iostream>

Player::Player(EntityManager& entityManager, sf::Vector2f& windowSize)
	: m_entityManager{ entityManager }
	, m_windowSize{ windowSize } {
	m_active = 1;
	m_type = "Player";
	load(Textures::ID::Player, "Resources/Graphics/Sprites/spritesheet.png");
	m_sprite.setTextureRect({ 32, 64, 32, 32 });

	m_animation = std::make_unique<Animation>(m_sprite, 0.10f, 0, 0, 32, 32, 300, 300);
	setupAnimations();
}

void Player::setupAnimations() {
	m_animation->add("IdleLeft", 1, 32, 32, 32, 32);
	m_animation->add("IdleRight", 1, 32, 64, 32, 32);
	m_animation->add("WalkLeft", 3, 0, 32, 32, 32);
	m_animation->add("WalkRight", 3, 0, 64, 32, 32);

	m_animation->play("IdleRight");
	m_facing = Direction::RIGHT;
}

void Player::handleInput(const sf::Time& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_animation->play("WalkLeft");
		m_facing = Direction::LEFT;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_animation->play("WalkRight");
		m_facing = Direction::RIGHT;
	} else {
		if (m_facing == Direction::LEFT) {
			m_animation->play("IdleLeft");
		} else {
			m_animation->play("IdleRight");
		}
	}
}

void Player::update(const sf::Time& dt) {
	handleInput(dt);
	m_animation->update(dt);
}