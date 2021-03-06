#include "Animation.hpp"

Animation::Animation(sf::Sprite& spriteSheet, const float duration)
: m_spriteSheet{ spriteSheet }
, m_duration{ duration }
, m_frameIndex{ 0 }
, m_visible{ true }
, m_currentAnimation{ "" }
, m_timeElapsed{ 0 } {}

void Animation::add(const std::string& name, int frames, int x, int y, int width, int height) {
    std::vector<sf::IntRect> rectangles;

    for (int i = 0; i < frames; i++) {
        sf::IntRect rect = { (i * width) + x, y, width, height };
        rectangles.push_back(rect);
    }

    m_animations.insert(std::make_pair(name, rectangles));
}

void Animation::reset() {
    m_animations.clear();
}

void Animation::play(const std::string& animation, bool playOnce /* = false */) {
    m_playOnce = playOnce;
    if (m_currentAnimation != animation) {
        m_currentAnimation = animation;
        m_frameIndex = 0;
    }
}

void Animation::stop() {
    m_frameIndex = 0;
}

void Animation::setVisible(bool visible) {
    m_visible = visible;
}

void Animation::update(const sf::Time& dt) {
    m_timeElapsed += dt.asSeconds();

    if (m_playOnce) {
        m_spriteSheet.setTextureRect(m_animations[m_currentAnimation][m_frameIndex]);
    } else if (m_timeElapsed > m_duration) {
        m_timeElapsed -= m_duration;
        if (m_frameIndex < m_animations[m_currentAnimation].size() - 1) {
            m_spriteSheet.setTextureRect(m_animations[m_currentAnimation][m_frameIndex]);
            m_frameIndex++;
        } else {
            if (m_playOnce) {
                setVisible(false);
            }
            m_frameIndex = 0;
        }
    }
}