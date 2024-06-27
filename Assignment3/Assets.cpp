#include "Assets.h"
#include <cassert>
#include <fstream>

void Assets::addTexture(const std::string& textureName, const std::string& path, bool smooth)
{
	m_textureMap[textureName] = Texture();
	if (!m_textureMap[textureName].loadFromFile(path))
	{
		std::cerr << "Could not load texture file: " << path << std::endl;
		m_textureMap.erase(textureName);
	}
	else
	{
		m_textureMap[textureName].setSmooth(smooth);
		std::cout << "Loaded tExture: " << path << std::endl;
	}
}

void Assets::addAnimation(const std::string& animationName, const std::string& textureName, size_t frameCount, size_t speed)
{
	m_animationMap[animationName] = Animation(animationName, getTexture(textureName), frameCount, speed);
}

void Assets::addFont(const std::string& fontName, const std::string& path)
{
}

Assets::Assets()
{
}

void Assets::loadFromFile(const std::string& path)
{
	std::ifstream file(path);
	std::string str;
	while (file.good())
	{
		file >> str;
		if (str == "Texture")
		{
			std::string name, path;
			file >> name >> path;
			addTexture(name, path);
		}
		else if (str == "Animation")
		{
			std::string name, texture;
			size_t frames, speed;
			file >> name >> texture >> frames >> speed;
			addAnimation(name, texture, frames, speed);
		}
		else if (str == "Font")
		{
			std::string name, path;
			file >> name >> path;
			addFont(name, path);
		}
		else
		{
			std::cerr << "Unknown Asset Type: " << str << std::endl;
		}
	}

}

const Texture& Assets::getTexture(const std::string& textureName) const
{
	// TODO: insert return statement here
}

const Animation& Assets::getAnimation(const std::string& animationName) const
{
	// TODO: insert return statement here
}

const Font& Assets::getFont(const std::string& fontName) const
{
	// TODO: insert return statement here
}
