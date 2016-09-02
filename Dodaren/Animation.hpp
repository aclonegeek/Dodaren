#pragma once
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>

// sprite sheet is 32x32, 3 anims per movement
// each anim is on a different y

class Animation {
public:
	Animation(sf::Sprite& sprite, float duration, int sourceX, int sourceY,
		int width, int height, float posX, float posY);

	void add(std::string name, int frames, int x, int y, int width, int height);
	void setVisible(bool visible);
	void play(std::string animation, const sf::Time& dt, bool playOnce = false);
	void stop();
	void reset();
	void update(const sf::Time& dt);
private:
	sf::Sprite& m_spriteSheet;

	std::vector<sf::IntRect> m_frames;
	std::map<std::string, std::vector<sf::IntRect>> m_animations;
	
	float m_duration;
	std::string m_currentAnimation;

	unsigned int m_frameIndex;
	bool m_visible;
	bool m_playOnce;
	float m_timeElapsed;
};