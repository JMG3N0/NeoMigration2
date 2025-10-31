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
		//float speed;
		float gravity;
		float jumpPower;
	};

	Player initPlayer(Player& player);
	Player resetPlayer(Player& player);
	Player updatePlayer(Player& player);
	void drawPlayer(Player player);



}