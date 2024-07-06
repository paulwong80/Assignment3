#include "Entity.h"

Entity::Entity(const size_t& id, const std::string& tag)
	:m_tag(tag), m_id(id)
{

}
void Entity::destroy()
{
	m_active = false;
}

size_t Entity::id() const
{
	return m_id;
}

bool Entity::isActive() const
{
	return m_active;
}

const std::string& Entity::tag() const
{
	// TODO: insert return statement here
	return m_tag;
}
