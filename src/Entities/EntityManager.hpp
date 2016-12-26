#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Entity.hpp"

class EntityManager {
public:
	EntityManager(sf::RenderWindow& window);

	void add(const std::string& name, std::unique_ptr<Entity> entity);
	void update(const sf::Time& dt);
	void draw();

	const bool exists(const std::string& name) const;
	const Entity& getEntity(const std::string& name) const;
private:
	void remove(std::string entity);

	std::map<std::string, std::unique_ptr<Entity>> m_entities;
	sf::RenderWindow& m_window;
};