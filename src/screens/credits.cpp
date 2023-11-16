#include "credits.h"

#include <string>

#include "raylib.h"

#include "uiComponents/button.h"
#include "assets/assetManager.h"
#include "managers/screenManager.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace Credits {
		static const float SCREEN_MARGIN = 50.0f;
		static const int BUTTON_WIDTH = 200;
		static const int BUTTON_HEIGHT = 50;

		static Buttons::Button goBackButton;

		void drawCredits() {
			DrawTextureEx(AssetManager::getTexture(AssetManager::CREDITS), { 0.0f, 0.0f }, 0, 1, WHITE);

			Buttons::drawButton(goBackButton);
			Buttons::drawCenteredTextInButton(goBackButton, "GO BACK");
		};

		void initCredits() {
			goBackButton = Buttons::createButton(
				{
					SCREEN_MARGIN,
					static_cast<float>(GetScreenHeight() - BUTTON_HEIGHT - SCREEN_MARGIN),
					BUTTON_WIDTH,
					BUTTON_HEIGHT
				}
			);
		};
		
		void checkCreditsInputAndCollision() {
			Buttons::updateButton(goBackButton);
			Vector2 mousePosition = GetMousePosition();

			if (goBackButton.isClicked) {
				ScreensManager::changeScreenTo(ScreensManager::MENU);
			}
		};
	}
}
