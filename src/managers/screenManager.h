#pragma once

namespace LeFlappyBird
{
	namespace ScreensManager
	{
		enum Screens
		{
			GAMEPLAY = 0,
			MENU,
			RULES,
			YOU_LOST,
			CREDITS
		};

		void initManager();
		void changeScreenTo(Screens screen);
		void drawScreen();
		void updateScreen(bool& shouldClose);
	}
}
