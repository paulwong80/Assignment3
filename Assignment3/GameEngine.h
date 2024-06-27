#pragma once
#include "Scene.h"
#include "Assets.h"
#include <map>
#include <memory>
typedef std::map<std::string, std::shared_ptr<Scene>> SceneMap;


class GameEngine
{
protected:
	// glfwWindow* m_window; To be fixed 
	Assets m_assets;
	std::string m_currentScene;
	SceneMap m_sceneMap;
	size_t m_simulationSpeed = 1;
	bool m_runing = true;
	
	void init(const std::string& path);
	void update();
	void sUserInput();
	std::shared_ptr<Scene> currentScene();
public:
	GameEngine(const std::string& path);
	void changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene = false);
	void quit();
	void run();
	// glfwWindow* window(); To be fixed 
	const Assets& assets() const;
	bool isRunning();
	glfwWindow* window();
	std::shared_ptr<Scene> getScene(const std::string& scene) const;
};

