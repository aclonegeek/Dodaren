#pragma once
#include <vector>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(sf::Sprite& sprite, float duration);

    void add(std::string name, int frames, int x, int y, int width, int height);
    void setVisible(bool visible);
    void play(std::string animation, bool playOnce = false);
    void stop();
    void reset();
    void update(const sf::Time& dt);
private:
    sf::Sprite& m_spriteSheet;

    std::vector<sf::IntRect> m_frames;
    std::unordered_map<std::string, std::vector<sf::IntRect>> m_animations;
    
    float m_duration;
    std::string m_currentAnimation;

    unsigned int m_frameIndex;
    bool m_visible;
    bool m_playOnce;
    float m_timeElapsed;
};