#pragma once

#include "raylib.h"

namespace NM2
{
	struct Obstacle
	{
		Vector2 pos;
		Vector2 safeSpot;
		float speed;
		float safeSpace;
		int width;
	};

	Obstacle initObstacle(Obstacle& obstacle);
	Obstacle updateObstacle(Obstacle& obstacle);
	Obstacle resetObstacle(Obstacle& obstacle);
	void drawObstacle(Obstacle obstacle);
	
}