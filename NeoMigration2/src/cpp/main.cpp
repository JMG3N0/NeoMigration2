#include "player.h"
#include "obstacle.h"

using namespace NM2;

int main()
{

	Player p1;
	Obstacle obs;
	initPlayer(p1);
	initObstacle(obs);
	bool hasCollided = false;

	InitWindow(800, 600, "Neo Migration 2");

	while (!WindowShouldClose())
	{

		
		BeginDrawing();
		ClearBackground(BLACK);	
		hasCollided = checkCollision(p1, obs);
		updateObstacle(obs, hasCollided);
		updatePlayer(p1, hasCollided);
		DrawText("0.1", 770, 580, 20, WHITE);
		DrawTextEx(GetFontDefault(), TextFormat("Score: %d", p1.score), {10.0f, 580.0f}, 20.0f, 1.0f, WHITE);
		//DrawText("Score: ", 10, 580, 20, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}