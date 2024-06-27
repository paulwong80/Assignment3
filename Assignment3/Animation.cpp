#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(const std::string& name, const Texture& t)
	:m_name(name)
	:m_sprite(t)
{
	
}

Animation::Animation(const std::string& name, const Texture& t, size_t frameCount, size_t speed)
{
	m_size = Vec2((float)t.getSize().x) / frameCount, (float)t.getSize().y);
	m_sprite.setOrigin(m_size.x / 2.0f, m_size.y / 2.0f);
	m_sprite.setTextureRect(IntRect(std::floor(m_currentFrame) * m_size.x, 0, m_size.x, m_size.y);
}

void Animation::update()
{
	m_currentFrame++;
}

bool Animation::hasEnded() const
{
	return (m_currentFrame+1>=m_frameCount);
}

const std::string& Animation::getName() const
{
	// TODO: insert return statement here
	return m_name;
}

const Vec2& Animation::getSize() const
{
	// TODO: insert return statement here
	return m_size;
}

Sprite& Animation::getSprite()
{
	// TODO: insert return statement here
	return m_sprite;
}
