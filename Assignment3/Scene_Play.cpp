#include "Scene_Play.h"

void Scene_Play::update()
{
	m_entityManager.update();

	sMovement();
	sLifespan();
	sCollision();
	sAnimation();
	sRender();
}
