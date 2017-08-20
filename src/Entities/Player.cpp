#include "Player.hpp"

Player::Player(const EntityManager& entityManager, const sf::Vector2f& windowSize)
: m_entityManager{ entityManager }
, m_windowSize{ windowSize } 
, m_walkSpeed{ 150.0f } 
, m_dx{ 0.0f }
, m_dy{ 0.0f }
, m_facing{ Direction::RIGHT } {
    m_active = 1;
    m_type = "Player";
    load(Textures::ID::Player, "Resources/Graphics/Sprites/spritesheet.png");

    m_animation = std::make_unique<Animation>(m_sprite, 0.10f);
    setupAnimations();
    m_animation->play("IdleRight");
}

void Player::setupAnimations() {
    m_animation->add("IdleLeft", 1, 32, 32, 32, 32);
    m_animation->add("IdleRight", 1, 32, 64, 32, 32);
    m_animation->add("WalkLeft", 3, 0, 32, 32, 32);
    m_animation->add("WalkRight", 3, 0, 64, 32, 32);
    m_animation->add("Test", 1, 32, 96, 32, 32);
}

void Player::moveLeft() {
    m_dx = -m_walkSpeed;
    m_animation->play("WalkLeft");
    m_facing = Direction::LEFT;
}

void Player::moveRight() {
    m_dx = m_walkSpeed;
    m_animation->play("WalkRight");
    m_facing = Direction::RIGHT;
}

void Player::stopMoving() {
    m_dx = 0.0f;
    m_animation->stop();
    m_animation->play(m_facing == Direction::LEFT ? "IdleLeft" : "IdleRight", true);
}

void Player::handleInput(const sf::Time& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight();
    } else {
        stopMoving();
    }
}

void Player::update(const sf::Time& dt) {
    handleInput(dt);
    m_animation->update(dt);

    m_velocity.x = m_dx;
    m_velocity.y = m_dy;

    Entity::update(dt);
}