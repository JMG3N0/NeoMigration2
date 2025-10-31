#include "player.h"

namespace NM2
{
	Player initPlayer(Player& player)
	{
		player.alive = true;
		
		//player.pos.x = static_cast<float>((GetScreenWidth() / 2));
		player.pos.x = 800.f / 2;
		//player.pos.y = static_cast<float>((GetScreenHeight() / 2));
		player.pos.y = 600.0f / 2;
		player.score = 0;
		player.highScore = 0;
		player.height = 50;
		player.width = 50;
		player.jumpPower = 200000.0f;
		player.gravity = 90.8f;

		return player;
	}

	Player resetPlayer(Player& player)
	{
		player.alive = true;
		//player.pos.x = static_cast<float>((GetScreenWidth() / 2));
		player.pos.x = 800.f/2;
		//player.pos.y = static_cast<float>((GetScreenHeight() / 2));
		player.pos.y = 600.0f / 2;
		player.score = 0;

		return player;
	}

	Player updatePlayer(Player& player)
	{
		drawPlayer(player);

		if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
		{
			player.pos.y -= player.jumpPower * GetFrameTime();

			if (player.pos.y < 0.0f)
			{
				player.pos.y = 0.0f;
			}
		}

		

		if (player.pos.y >= static_cast<float>(GetScreenHeight()))
		{
			resetPlayer(player);
		}

		player.pos.y += player.gravity * GetFrameTime();



		return player;
	}

	void drawPlayer(Player player)
	{
		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, RED);
	}
}