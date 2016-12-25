#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <cassert>
#include <memory>
#include <map>

template <typename Resource, typename Identifier>
class ResourceHandler {
public:
	void load(Identifier id, const std::string& filePath) {
		std::unique_ptr<Resource> resource(new Resource());

		if (!resource->loadFromFile(filePath)) {
			throw std::runtime_error("ResourceHandler::load - Failed to load " + filePath);
		}

		insert(id, std::move(resource));
	}

	const Resource& get(Identifier id) const {
		auto found = m_resourceMap.find(id);
		assert(found != m_resourceMap.end());
		return *found->second;
	}
private:
	void insert(Identifier id, std::unique_ptr<Resource> resource) {
		auto inserted = m_resourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}

	std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
};

template <typename Music, typename Identifier>
class MusicHandler {
public:
	void load(Identifier id, const std::string& filePath) {
		std::unique_ptr<Music> music(new Music());

		if (!music->openFromFile(filePath)) {
			throw std::runtime_error("MusicHandler::load - Failed to load " + filePath);
		}

		insert(id, std::move(music));
	}

	const Music& get(Identifier id) const {
		auto found = m_musicMap.find(id);
		assert(found != m_musicMap.end());
		return *found->second;
	}
private:
	void insert(Identifier id, std::unique_ptr<Music> Music) {
		auto inserted = m_musicMap.insert(std::make_pair(id, std::move(Music)));
		assert(inserted.second);
	}

	std::map<Identifier, std::unique_ptr<Music>> m_musicMap;
};

namespace Textures {
	enum class ID {
		Player
	};
}

namespace Fonts {
	enum class ID {
		
	};
}

namespace Sound {
	enum class ID {

	};
}

namespace Music {
	enum class ID {

	};
}

static ResourceHandler<sf::Texture, Textures::ID>	textureMap;
static ResourceHandler<sf::Font, Fonts::ID>			fontMap;
static ResourceHandler<sf::SoundBuffer, Sound::ID>	soundBufferMap;
static MusicHandler<sf::Music, Music::ID>			musicMap;