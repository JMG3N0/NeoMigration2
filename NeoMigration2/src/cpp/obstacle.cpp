#include "obstacle.h"

namespace NM2
{

	Obstacle initObstacle(Obstacle& obstacle)
	{
		obstacle.pos.y = 0.0f;
		obstacle.pos.x = static_cast<float>(GetScreenWidth());
		obstacle.safeSpot.x = obstacle.pos.x;
		obstacle.safeSpot.y = static_cast<float>((GetScreenHeight() / 2));
		obstacle.speed = 50.0f;
		obstacle.safeSpace = 70.0f;
		obstacle.width = 20;

		return obstacle;
	}

	Obstacle updateObstacle(Obstacle& obstacle)
	{
		drawObstacle(obstacle);

		obstacle.pos.x -= obstacle.speed * GetFrameTime();
		obstacle.safeSpot.x = obstacle.pos.x;

		if (obstacle.pos.x <= 0.0f)
		{
			resetObstacle(obstacle);
		}

		return obstacle;
	}

	Obstacle resetObstacle(Obstacle& obstacle)
	{
		obstacle.pos.x = static_cast<float>(GetScreenWidth());
		obstacle.safeSpot.x = obstacle.pos.x;

		return obstacle;
	}
	
	void drawObstacle(Obstacle obstacle)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x), 0, obstacle.width, static_cast<int>(400.0f - obstacle.safeSpace), YELLOW);
		DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(400.0f + obstacle.safeSpace), obstacle.width, (GetScreenHeight() - static_cast<int>(obstacle.safeSpot.y + obstacle.safeSpace)), YELLOW);
	}
}
