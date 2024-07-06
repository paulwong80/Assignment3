#pragma once
#include <iostream>
#include "Animation.h"
typedef std::string Texture;
typedef std::string Font;

class Assets
{
	std::map<std::string, Texture> m_textureMap;
	std::map<std::string, Animation> m_animationMap;
	std::map<std::string, Font> m_fontMap;

	void addTexture(const std::string& textureName, const std::string& path, bool smooth = true);
	void addAnimation(const std::string& animationName, const std::string& textureName, size_t frameCount, size_t speed);
	void addFont(const std::string& fontName, const std::string& path);
public:
	Assets();
	void loadFromFile(const std::string& path);
	const Texture& getTexture(const std::string& textureName) const;
	const Animation& getAnimation(const std::string& animationName) const;
};

