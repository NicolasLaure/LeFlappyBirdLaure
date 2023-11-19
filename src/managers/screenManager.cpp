#include "screenManager.h"

#include "raylib.h"

#include "screens/gameplay.h"
#include "screens/menu.h"
#include "screens/credits.h"
#include "managers/pauseManager.h"

namespace LeFlappyBird {
	namespace ScreensManager {
		static Screens actualScreen;

		static bool isPaused = false;

		void initManager() {
			actualScreen = Screens::MENU;

			Menu::initMenu();
		}

		void changeScreenTo(Screens screen) {
			actualScreen = screen;

			switch (actualScreen) {
			case Screens::MENU:
				Menu::initMenu();
				break;
			case Screens::GAMEPLAY:
				Gameplay::initGameplay(false);
				break;
			case Screens::MULTIPLAYER_GAMEPLAY:
				Gameplay::initGameplay(true);
				break;
			case Screens::YOU_LOST:
				break;
			case Screens::CREDITS:
				Credits::initCredits();
				break;
			case Screens::RULES:
				break;
			}
		}

		void drawScreen() {
			switch (actualScreen) {
			case Screens::MENU:
				Menu::drawMenu();
				break;
			case Screens::CREDITS:
				Credits::drawCredits();
				break;
			case Screens::YOU_LOST:
				break;
			case Screens::RULES:
				break;
			case Screens::GAMEPLAY:
			case Screens::MULTIPLAYER_GAMEPLAY:
				Gameplay::drawGameplay();

				if (isPaused)
					Pause::Draw();
				break;
			};
		}

		void updateScreen(bool& shouldClose) {
			switch (actualScreen) {
			case Screens::MENU:
				Menu::checkMenuInputAndCollision(shouldClose);
				break;
			case Screens::CREDITS:
				Credits::checkCreditsInputAndCollision();
				break;
			case Screens::RULES:
				break;
			case Screens::GAMEPLAY:
			case Screens::MULTIPLAYER_GAMEPLAY:
				if (!isPaused)
					Gameplay::updateGameplay(isPaused);
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