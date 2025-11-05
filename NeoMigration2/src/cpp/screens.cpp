#include "screens.h"

#include "player.h"
#include "obstacle.h"

#include "raylib.h"
#include <iostream>

namespace NM2
{

	static const int screenWidth = 800;
	static const int screenHeight = 600;

	ScreenType screen;

	Player p1;
	Obstacle obs;

	bool hasCollided = false;

	void runGame()
	{
		screen = Title;
		srand((unsigned int)time(NULL));
		InitWindow(screenWidth, screenHeight, "Neo Migration 2");
		SetExitKey(NULL);

		while (!WindowShouldClose())
		{
			drawNupdate();
		}

		CloseWindow();
	}


	void titleScreen(ScreenType& screen)
	{
		float ScreenWidth = static_cast<float>(screenWidth);
		float ScreenHeight = static_cast<float>(screenHeight);

		ClearBackground(RAYWHITE);

		DrawTextEx(GetFontDefault(), "Neo Migration 2", { (ScreenWidth / 2) - 110, (ScreenHeight / 2) - 30 }, 30, 1.0f, BLUE);
		DrawTextEx(GetFontDefault(), "Press any key to continue...", { (ScreenWidth / 2) - 140, (ScreenHeight / 2) + 30 }, 20, 1.0f, BLUE);

		
		if (GetKeyPressed() >= 32 && GetKeyPressed() <= 168 || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
		{
			
			screen = Main;
		}
		


	}

	void mainScreen(ScreenType& screen)
	{
		Vector2 mousePos = GetMousePosition();
		float ScreenWidth = static_cast<float>(screenWidth);
		float ScreenHeight = static_cast<float>(screenHeight);

		DrawTextEx(GetFontDefault(), "Neo Migration 2", { (ScreenWidth / 2) - 110, (ScreenHeight / 2) - 30 }, 30, 1.0f, BLUE);

		DrawTextEx(GetFontDefault(), "Play", { (ScreenWidth / 2) - 20, (ScreenWidth / 2) - 65 }, 20, 1.0f, BLUE);
		DrawTextEx(GetFontDefault(), "Credits", { (ScreenWidth / 2) - 40,   (ScreenWidth / 2) - 35 }, 20, 1.0f, BLUE);
		DrawTextEx(GetFontDefault(), "Exit", { (ScreenWidth / 2) - 20, (ScreenHeight / 2) + 100 }, 20, 1.0f, BLUE);

		if (mousePos.x <= ((ScreenWidth / 2) + 50) && mousePos.x >= ((ScreenWidth / 2) - 50))
		{
			if (mousePos.y <= ((screenHeight / 2) + 30) + 12 && mousePos.y >= ((screenHeight / 2) + 30) - 12)
			{
				DrawTextEx(GetFontDefault(), "Play", { (ScreenWidth / 2) - 20, (ScreenWidth / 2) - 65 }, 20, 1.0f, RED);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					initPlayer(p1);
					initObstacle(obs);
					screen = Game;
				}
			}

			if (mousePos.y <= ((screenHeight / 2) + 65) + 12 && mousePos.y >= ((screenHeight / 2) + 65) - 12)
			{
				DrawTextEx(GetFontDefault(), "Credits", { (ScreenWidth / 2) - 40,   (ScreenWidth / 2) - 35 }, 20, 1.0f, RED);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					screen = Credits;
				}
			}

			if (mousePos.y <= ((screenHeight / 2) + 100) + 12 && mousePos.y >= ((screenHeight / 2) + 100) - 12)
			{
				DrawTextEx(GetFontDefault(), "Exit", { (ScreenWidth / 2) - 20, (ScreenHeight / 2) + 100 }, 20, 1.0f, RED);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					CloseWindow();
				}
			}
		}

	}

	void creditsScreen(ScreenType& screen)
	{
		Vector2 mousePos = GetMousePosition();
		float ScreenWidth = static_cast<float>(screenWidth);
		float ScreenHeight = static_cast<float>(screenHeight);

#if _DEBUG
		DrawRectangle(((screenWidth / 2) - 150), ((screenHeight / 2)), 320, 30, GREEN);
		
#endif // _DEBUG

		DrawTextEx(GetFontDefault(), "Made by Joan Manuel Rivas Cepeda", { (ScreenWidth / 2.0f) - 150.0f, (ScreenHeight / 2.0f) }, 20, 1.0f, BLUE);
		DrawTextEx(GetFontDefault(), "Go Back", { (30.0f), (ScreenHeight - 20.0f) }, 20, 1.0f, BLUE);
		DrawTextEx(GetFontDefault(), "Play Game", { (ScreenWidth - 150.0f), (ScreenHeight - 20.0f) }, 20, 1.0f, BLUE);

		if (mousePos.x >= 200.0f && mousePos.x <= ((ScreenWidth / 2.0f) + 200.0f))
		{
			if (mousePos.y >= ((ScreenHeight / 2.0f) - 35.0f) && mousePos.y <= ((ScreenHeight / 2.0f) + 35.0f))
			{
				DrawTextEx(GetFontDefault(), "Made by Joan Manuel Rivas Cepeda", { (ScreenWidth / 2.0f) - 150.0f, (ScreenHeight / 2.0f) }, 20, 1.0f, RED);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					OpenURL("https://joan-mrc.itch.io");
				}
			}
		}

		



		if (mousePos.y <= screenHeight && mousePos.y >= ScreenHeight - 40)
		{
			if (mousePos.x <= (ScreenWidth / 6))
			{
				DrawTextEx(GetFontDefault(), "Go Back", { (30.0f), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					screen = Main;
				}
			}
			if (mousePos.x >= ScreenWidth - 140)
			{
				DrawTextEx(GetFontDefault(), "Play Game", { static_cast<float>(ScreenWidth - 150), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{

					screen = Game;
				}
			}
		}

	}
	

	void drawNupdate()
	{




		BeginDrawing();

		ClearBackground(RAYWHITE);

		switch (screen)
		{
		case ScreenType::Title:
			titleScreen(screen);
			break;
		case ScreenType::Main:
			mainScreen(screen);
			break;
		case ScreenType::Credits:
			creditsScreen(screen);
			break;
		case ScreenType::Game:

			hasCollided = checkCollision(p1, obs);
			updateObstacle(obs, hasCollided);
			updatePlayer(p1, hasCollided);
			
			DrawTextEx(GetFontDefault(), TextFormat("Score: %d", p1.score), { 10.0f, 580.0f }, 20.0f, 1.0f, BLUE);

			break;
		default:
			break;
		}

		EndDrawing();

		if (screen != Game)
		{
			
			DrawText("0.2", 770, 580, 20, BLUE);
			
		}



	}


	
	
	
	



	

	
}