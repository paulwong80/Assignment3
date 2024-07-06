#include "Scene_Play.h"

void Scene_Play::sDoAction(const Action& action)
{
}

void Scene_Play::update()
{
	m_entityManager.update();
	sMovement();
	sLifespan();
	sCollision();
	sAnimation();
	sRender();
}

void Scene_Play::onEnd()
{
	m_game->changeScene("MENU", nullptr, true);
}

Scene_Play::Scene_Play(GameEngine* game, const std::string& levelPath)
	:Scene(game), m_levelPath(levelPath)
{
	init(levelPath);
}

void Scene_Play::init(const std::string& levelPath)
{
	registerAction(GLFW_KEY_D, "RIGHT");
	registerAction(GLFW_KEY_A, "LEFT");
	registerAction(GLFW_KEY_W, "JUMP");
	registerAction(GLFW_KEY_ESCAPE, "QUIT");
	registerAction(GLFW_KEY_P, "PAUSE");
	registerAction(GLFW_KEY_T, "TOGGLE_TEXTURE");
	registerAction(GLFW_KEY_C, "TOGGLE_COLLISION");
	registerAction(GLFW_KEY_G, "TOGGLE_GRID");
	glViewport(0, 0, width(), height());

}

void Scene_Play::loadLevel(const std::string& filename)
{
	m_entityManager = EntityManager();
}

void Scene_Play::sMovement()
{
}

void Scene_Play::sLifespan()
{
}

void Scene_Play::sCollision()
{
}

void Scene_Play::sAnimation()
{
}

void Scene_Play::sRender()
{
	glClearColor(0.36f, 0.58f, 0.99f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

Vec2 Scene_Play::gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity)
{
	return Vec2();
}

void Scene_Play::spawnPlayer()
{
}

void Scene_Play::spawnBullet(std::shared_ptr<Entity> entity)
{
}
