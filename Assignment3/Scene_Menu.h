#pragma once
#include "Scene.h"
#include <memory>
#include "EntityManager.h"

class Scene_Menu:public Scene
{
protected:
	std::string m_title;
	std::vector<std::string> m_menuStrings;
	std::vector<std::string> m_levelPaths;
	// Text m_menuText;
	size_t m_selectedMenuIndex = 0;

	void init();
	void update() override;
	void onEnd() override;
	void sDoAction(const Action& action) override;
	void doAction(const Action& action) override;
	void sRender() override;
public:
	Scene_Menu(GameEngine* game);
};

