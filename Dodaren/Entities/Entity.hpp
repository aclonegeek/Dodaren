#pragma once
#include <SFML/Graphics.hpp>

#include "../ResourceHandler.hpp"

class Entity {
public:
	Entity() {}

	virtual void load(Textures::ID id, const std::string& filePath) {
		textureMap.load(id, filePath);
		m_sprite.setTexture(textureMap.get(id));
	}

	virtual void update(const sf::Time& dt) {
		m_sprite.move(m_velocity * dt.asSeconds());
	}

	virtual void destroy() {
		m_active = 0;
	}

	virtual void collision(Entity& entity) {
		destroy();
		entity.destroy();
	}

	bool checkCollision(Entity& entity) {
		return m_sprite.getGlobalBounds().intersects(entity.getSprite().getGlobalBounds());
	}

	void setVelocity(sf::Vector2f velocity) { m_velocity = velocity; }
	void setVelocity(float vx, float vy)	{ m_velocity.x = vx; m_velocity.y = vy; }

	const bool			isActive()	  const	{ return m_active == 1; }
	const std::string	getType()	  const	{ return m_type; }
	const sf::Sprite	getSprite()	  const	{ return m_sprite; }
	const sf::Vector2f	getVelocity() const	{ return m_velocity; }
protected:
	int				m_active;
	std::string		m_type;

	sf::Sprite		m_sprite;
	sf::Vector2f	m_velocity;
};