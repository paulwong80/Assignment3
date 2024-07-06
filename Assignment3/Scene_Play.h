#pragma once
#include "Scene.h"
#include <map>
#include <memory>
#include "EntityManager.h"

class Scene_Play:public Scene
{
	struct PlayerConfig
	{
		float X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
		std::string WEAPON;
	};
protected:
	std::shared_ptr<Entity> m_player;
	std::string m_levelPath;
	PlayerConfig m_playerConfig;
	bool m_drawTextures = true;
	bool m_drawCollision = false;
	bool m_drawGrid = false;
	const Vec2 m_gridSize = { 64, 64 };
	// Text m_gridText;

	void init(const std::string& levelPath);
	void loadLevel(const std::string& filename);
	void sMovement();
	void sLifespan();
	void sCollision();
	void sAnimation();
	void sRender();
	Vec2 gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity);
	void spawnPlayer();
	void spawnBullet(std::shared_ptr<Entity> entity);
	void sDoAction(const Action& action);
public:
	EntityManager m_entityManager;
	void update() override;
	void onEnd() override;
	Scene_Play(GameEngine* game, const std::string& levelPath);
};

