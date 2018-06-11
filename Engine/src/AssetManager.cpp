#include "AssetManager.h"

#include "SFML\Graphics.hpp"

bool AssetManager::LoadTexture(const std::string & name, const std::string & fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		_textures[name] = tex;
		return true;
	}

	return false;
}

sf::Texture & AssetManager::GetTexture(const std::string & name)
{
	return _textures.at(name);
}

bool AssetManager::LoadFont(const std::string & name, const std::string & fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		_fonts[name] = font;
		return true;
	}

	return false;
}

sf::Font & AssetManager::GetFont(const std::string & name)
{
	return _fonts.at(name);
}
