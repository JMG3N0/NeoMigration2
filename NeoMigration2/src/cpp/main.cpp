#include "player.h"

using namespace NM2;

int main()
{

	Player p1;
	initPlayer(p1);

	InitWindow(800, 600, "Neo Migration 2");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		updatePlayer(p1);


		EndDrawing();
	}

	CloseWindow();

	return 0;
}