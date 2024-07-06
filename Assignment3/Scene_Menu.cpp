#include "Scene_Menu.h"
#include "Scene_Play.h"
void Scene_Menu::init()
{
	m_entityManager = EntityManager();
	registerAction(GLFW_KEY_W, "UP");
	registerAction(GLFW_KEY_S, "DOWN");
	registerAction(GLFW_KEY_ESCAPE, "QUIT");
	registerAction(GLFW_KEY_ENTER, "PLAY");
	m_title = "Mega Mario";
	m_menuStrings.push_back("Level 1");
	m_menuStrings.push_back("Level 2");
	m_levelPaths.push_back("level1.txt");
	m_levelPaths.push_back("level2.txt");
	glViewport(0, 0, width(), height());
}

void Scene_Menu::update()
{
	m_entityManager.update();
	sRender();
}

void Scene_Menu::onEnd()
{
	m_hasEnded = true;
	m_game->quit();
}

void Scene_Menu::sDoAction(const Action& action)
{
	if (action.type() == "START")
	{
		if (action.name() == "UP") { m_selectedMenuIndex = (m_selectedMenuIndex - 1) >= 0 ? m_selectedMenuIndex - 1 : 0; }
		else if (action.name() == "DOWN") { m_selectedMenuIndex = (m_selectedMenuIndex + 1) > 1 ? 1 : m_selectedMenuIndex + 1; }
		else if (action.name() == "QUIT") { onEnd(); }
		else if (action.name() == "PLAY") { m_game->changeScene("PLAY", 
			std::make_shared<Scene_Play>(m_game, m_levelPaths[m_selectedMenuIndex])); }
	}
}

void Scene_Menu::doAction(const Action& action)
{
	sDoAction(action);
}

void Scene_Menu::sRender()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

Scene_Menu::Scene_Menu(GameEngine* game):Scene(game)
{
	init();
}
