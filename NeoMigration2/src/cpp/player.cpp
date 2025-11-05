#include "player.h"

namespace NM2
{
	Player initPlayer(Player& player)
	{
		player.alive = true;
		
		//player.pos.x = static_cast<float>((GetScreenWidth() / 2));
		player.pos.x = 800.f / 2;
		//player.pos.y = static_cast<float>((GetScreenHeight() / 2));
		player.pos.y = 600.0f / 2.0f;
		player.score = 0;
		player.highScore = 0;
		player.height = 25;
		player.width = 25;
		player.jumpPower = 50000.0f;
		player.gravity = 100.0f;
		player.fallSpeed = 0.0f;
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
		player.fallSpeed = 0.0f;
		return player;
	}

	Player updatePlayer(Player& player, bool collided)
	{
		drawPlayer(player);

		if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
		{
			player.fallSpeed = 0.0f;
			player.pos.y -= player.jumpPower * GetFrameTime();

			if (player.pos.y < 0.0f)
			{
				player.pos.y = 0.0f;
			}
			player.fallSpeed -= (player.jumpPower/2.0f) * GetFrameTime();
		}

		

		if (player.pos.y >= static_cast<float>(GetScreenHeight()) || collided == true)
		{
			resetPlayer(player);
		}

		player.fallSpeed += player.gravity * GetFrameTime();
		

		player.pos.y += player.fallSpeed * GetFrameTime();




		return player;
	}

	void drawPlayer(Player player)
	{
		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, RED);
	}

	
}