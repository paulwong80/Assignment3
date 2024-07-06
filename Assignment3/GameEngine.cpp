#include "GameEngine.h"
#include "Scene_Play.h"
#include "Scene_Menu.h"
#include "Input.h"

const int width = 1280;
const int height = 704;

#include <iostream>
void GameEngine::init(const std::string& path)
{
	m_assets.loadFromFile(path);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	m_window = glfwCreateWindow(width, height, "Not Mario", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	glewInit();
	glfwSetKeyCallback(m_window, KeyCallback);
	changeScene("MENU", std::make_shared<Scene_Menu>(this));
}

void GameEngine::update()
{
	glfwPollEvents();
	sUserInput();
	m_sceneMap[m_currentScene]->update();
}

void GameEngine::sUserInput()
{
	if (event.action == GLFW_PRESS || event.action == GLFW_RELEASE)
	{
		if (currentScene()->getActionMap().find(event.key) == currentScene()->getActionMap().end()){return;}
		const std::string actionType = (event.action == GLFW_PRESS) ? "START" : "END";
		currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key), actionType));
	}
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
	m_running = false;
}

void GameEngine::run()
{
	while (isRunning())
	{
		update();
		glfwSwapBuffers(m_window);
	}
}

const Assets& GameEngine::assets() const
{
	// TODO: insert return statement here
	return m_assets;
}

bool GameEngine::isRunning()
{
	return m_running && !glfwWindowShouldClose(m_window);
}

GLFWwindow* GameEngine::window()
{
	return m_window;
}

std::shared_ptr<Scene> GameEngine::getScene(const std::string& scene)
{
	return m_sceneMap[scene];
}
