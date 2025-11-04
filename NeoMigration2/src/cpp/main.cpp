#include "player.h"
#include "obstacle.h"

using namespace NM2;

int main()
{

	Player p1;
	Obstacle obs;
	initPlayer(p1);
	initObstacle(obs);

	InitWindow(800, 600, "Neo Migration 2");

	while (!WindowShouldClose())
	{

		bool hasCollided = checkCollision(p1, obs);
		BeginDrawing();
		ClearBackground(BLACK);	
		updateObstacle(obs, hasCollided);
		updatePlayer(p1, hasCollided);
		DrawText("0.1", 770, 580, 20, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}