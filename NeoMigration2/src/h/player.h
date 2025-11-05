#pragma once

#include "raylib.h"

namespace NM2
{

	struct Player
	{
		Vector2 pos;
		bool alive;
		int score;
		int highScore;
		int height;
		int width;
		float fallSpeed;
		float gravity;
		float jumpPower;
		//float cooldown;
	};

	Player initPlayer(Player& player);
	Player resetPlayer(Player& player);
	Player updatePlayer(Player& player, bool collided);
	void drawPlayer(Player player);



}