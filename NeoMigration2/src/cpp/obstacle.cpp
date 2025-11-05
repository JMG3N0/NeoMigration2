#include "obstacle.h"

namespace NM2
{

	Obstacle initObstacle(Obstacle& obstacle)
	{
		obstacle.pos.y = 200.0f;
		obstacle.pos.x = static_cast<float>(GetScreenWidth());
		obstacle.speed = 50.0f;
		obstacle.safeSpace = 100;
		obstacle.width = 20;
		obstacle.speedCap = 300.0f;

		return obstacle;
	}

	Obstacle updateObstacle(Obstacle& obstacle, bool collided)
	{
		drawObstacle(obstacle);

		obstacle.pos.x -= obstacle.speed * GetFrameTime();

		if (obstacle.pos.x <= 0.0f || collided == true)
		{
			resetObstacle(obstacle);

			if (collided ==true)
			{
				obstacle.speed = 50.0f;
			}

			return obstacle;
		}

		return obstacle;
	}

	Obstacle resetObstacle(Obstacle& obstacle)
	{
		obstacle.pos.x = static_cast<float>(GetScreenWidth());
		if (obstacle.speed + 25.0f <= 300.0f)
		{
			obstacle.speed += 25.0f;
		}
		
		return obstacle;
	}
	
	void drawObstacle(Obstacle obstacle)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x), 0, obstacle.width, GetScreenHeight(), YELLOW);
		DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, static_cast<int>(obstacle.safeSpace), BLACK);
		
	}

	bool checkCollision(Player player, Obstacle obstacle)
	{
		if (player.pos.y - static_cast<float>(player.height/2) < obstacle.pos.y || player.pos.y + static_cast<float>(player.height / 2) > (obstacle.pos.y + obstacle.safeSpace) )
		{
			if (player.pos.x + static_cast<float>(player.width) >= obstacle.pos.x && player.pos.x - static_cast<float>(player.width) <= obstacle.pos.x + static_cast<float>(obstacle.width))
			{
				return true;
			}

		}
		
		
			return false;
		
	}
}
