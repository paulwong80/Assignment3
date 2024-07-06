#include "EntityManager.h"

void EntityManager::removerDeadEntities(EntityVec& vec)
{
	vec.erase(std::remove_if(
		vec.begin(), 
		vec.end(), 
		[](const std::shared_ptr<Entity>& entity) {  return !entity->isActive(); }), 
		vec.end());
}

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
	for  (auto & e: m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entitiyMap[e->tag()].push_back(e);
	}
	removerDeadEntities(m_entities);
	for (auto& kv: m_entitiyMap)
	{
		removerDeadEntities(kv.second);
	}
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
	m_entitiesToAdd.push_back(entity);
	return entity;
}

const EntityVec& EntityManager::getEntities()
{
	// TODO: insert return statement here
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag)
{
	// TODO: insert return statement here
	return m_entitiyMap[tag];
}

const std::map<std::string, EntityVec>& EntityManager::getEntityMap()
{
	// TODO: insert return statement here
	return m_entitiyMap;
}
