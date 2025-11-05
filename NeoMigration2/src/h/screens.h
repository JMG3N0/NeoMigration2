#pragma once

namespace NM2
{
	enum ScreenType
	{
		Title = 0,
		Main,
		Game,
		Credits
	};
	
	void runGame();
	void drawNupdate();
	void titleScreen(ScreenType& screen);
	void gameScreen(ScreenType& screen);
	void mainScreen(ScreenType& screen);
	void creditsScreen(ScreenType& screen);
}
