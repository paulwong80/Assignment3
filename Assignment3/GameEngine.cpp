#include "GameEngine.h"
#include "Scene_Play.h"
#include "Scene_Menu.h"

#include <iostream>
void GameEngine::init(const std::string& path)
{
	m_assets.loadFromFile(path);
	m_window.create("Mario");
	changeScene("MENU", std::make_shared<Scene_Menu>(this));
}

void GameEngine::update()
{
	sUserInput();
	m_sceneMap.at(m_currentScene)->update();
}

void GameEngine::sUserInput()
{
}

std::shared_ptr<Scene> GameEngine::currentScene()
{
	return m_sceneMap[m_currentScene];
}

GameEngine::GameEngine(const std::string& path)
{
	init(path);
}

void GameEngine::changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene)
{
	if (endCurrentScene)
	{
		m_sceneMap.erase(m_currentScene);
	}
	m_currentScene = sceneName;
	m_sceneMap[sceneName] = scene;
}

void GameEngine::quit()
{
}

void GameEngine::run()
{
	while (isRunning)
	{
		update();
	}
}

const Assets& GameEngine::assets() const
{
	// TODO: insert return statement here
}

bool GameEngine::isRunning()
{
	return m_runing && m_window.isOpen();
}

glfwWindow* GameEngine::window()
{
	return m_window;
}

std::shared_ptr<Scene> GameEngine::getScene(const std::string& scene) const
{
	return std::shared_ptr<Scene>();
}
