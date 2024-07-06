#include "Scene.h"
#include <GLFW/glfw3.h>
void Scene::setPaused(bool paused)
{
	m_paused = true;
}

Scene::Scene() {};

Scene::Scene(GameEngine* gameEngine)
	:m_game(gameEngine)
{
}

void Scene::doAction(const Action& action)
{
}

void Scene::simulate(const size_t frames)
{
}

void Scene::registerAction(int inputKey, const std::string& actionName)
{
	m_actionMap[inputKey] = actionName;
}

size_t Scene::width() const
{
	int width, height;
	glfwGetFramebufferSize(m_game->window(), &width, &height);
	return size_t(width);
}

size_t Scene::height() const
{
	int width, height;
	glfwGetFramebufferSize(m_game->window(), &width, &height);
	return size_t(height);
}

size_t Scene::currentFrame() const
{
	return m_currentFrame;
}

bool Scene::hasEnded() const
{
	return m_hasEnded;
}

const ActionMap& Scene::getActionMap() const
{
	// TODO: insert return statement here
	return m_actionMap;
}

void Scene::drawLine(const Vec2& p1, const Vec2& p2)
{
}
