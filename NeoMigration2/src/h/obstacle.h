#pragma once

#include "raylib.h"

#include "player.h"

namespace NM2
{
	struct Obstacle
	{
		Vector2 pos;
		float speed;
		float speedCap;
		int safeSpace;
		int width;
		bool canGivePoint;
	};

	Obstacle initObstacle(Obstacle& obstacle);
	Obstacle updateObstacle(Obstacle& obstacle, bool collided);
	Obstacle resetObstacle(Obstacle& obstacle);
	void drawObstacle(Obstacle obstacle);
	bool checkCollision(Player& player, Obstacle& obstacle);
}