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
		BeginDrawing();
		ClearBackground(BLACK);
		updatePlayer(p1);
		updateObstacle(obs);
		DrawText("0.1", 780, 580, 20, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}