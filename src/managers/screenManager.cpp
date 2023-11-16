#include "screenManager.h"

#include "raylib.h"

#include "screens/gameplay.h"
#include "screens/menu.h"

namespace LeFlappyBird {
	namespace ScreensManager {
		static Screens actualScreen;

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
					Gameplay::initGameplay();
					break;
				case Screens::YOU_LOST:
					break;
				case Screens::CREDITS:
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
					break;
				case Screens::YOU_LOST:
					break;
				case Screens::RULES:
					break;
				case Screens::GAMEPLAY:
					Gameplay::drawGameplay();
					break;
			};
		}

		void updateScreen(bool& shouldClose) {
			switch (actualScreen) {
				case Screens::MENU:
					Menu::checkMenuInputAndCollision(shouldClose);
					break;
				case Screens::CREDITS:
					break;
				case Screens::RULES:
					break;
				case Screens::GAMEPLAY:
					Gameplay::updateGameplay();
					break;
				case Screens::YOU_LOST:
					break;
			};

			shouldClose = shouldClose || WindowShouldClose();
		};
	}
}