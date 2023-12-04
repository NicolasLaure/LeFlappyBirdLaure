#include "screenManager.h"

#include "raylib.h"

#include "screens/gameplay.h"
#include "screens/menu.h"
#include "screens/credits.h"
#include "screens/rules.h"
#include "managers/pauseManager.h"

namespace LeFlappyBird
{
	namespace ScreensManager
	{
		static Screens actualScreen;

		static bool isPaused = false;
		static bool isGameOver = false;
		static int score = 0;
		void initManager()
		{
			actualScreen = Screens::MENU;

			Menu::initMenu();

			Pause::init();
		}

		void changeScreenTo(Screens screen)
		{
			actualScreen = screen;

			switch (actualScreen)
			{
			case Screens::MENU:
				Menu::initMenu();
				break;
			case Screens::GAMEPLAY:
				Gameplay::initGameplay(false);
				score = 0;
				break;
			case Screens::MULTIPLAYER_GAMEPLAY:
				Gameplay::initGameplay(true);
				score = 0;
				break;
			case Screens::YOU_LOST:
				break;
			case Screens::CREDITS:
				Credits::initCredits();
				break;
			case Screens::RULES:
				Rules::init();
				break;
			}
		}

		void drawScreen()
		{
			switch (actualScreen)
			{
			case Screens::MENU:
				Menu::drawMenu();
				break;
			case Screens::CREDITS:
				Credits::drawCredits();
				break;
			case Screens::YOU_LOST:
				break;
			case Screens::RULES:
				Rules::draw();
				break;
			case Screens::GAMEPLAY:
			case Screens::MULTIPLAYER_GAMEPLAY:
				Gameplay::drawGameplay(score);

				if (isPaused)
					Pause::Draw(isGameOver, score);
				break;
			};
		}

		void updateScreen(bool& shouldClose)
		{
			switch (actualScreen)
			{
			case Screens::MENU:
				Menu::update(shouldClose);
				break;
			case Screens::CREDITS:
				Credits::checkCreditsInputAndCollision();
				break;
			case Screens::RULES:
				Rules::checkCreditsInputAndCollision();
				break;
			case Screens::GAMEPLAY:
			case Screens::MULTIPLAYER_GAMEPLAY:
				if (!isPaused)
					Gameplay::updateGameplay(isPaused, isGameOver, score);
				else
					Pause::Update(isPaused);
				break;
			case Screens::YOU_LOST:
				break;
			};

			shouldClose = shouldClose || WindowShouldClose();
			};
		}
	}