#include "screenManager.h"

#include "raylib.h"

#include "screens/gameplay.h"

namespace LeFlappyBird {
	namespace ScreensManager {
		static Screens actualScreen;

		void initManager() {
			actualScreen = Screens::GAMEPLAY;

			Gameplay::initGameplay();
		}

		void changeScreenTo(Screens screen) {
			actualScreen = screen;

			switch (actualScreen) {
				case Screens::MENU:
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