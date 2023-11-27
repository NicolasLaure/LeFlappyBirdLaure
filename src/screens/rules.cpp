#include "rules.h"

#include <string>

#include "raylib.h"

#include "uiComponents/button.h"
#include "assets/assetManager.h"
#include "managers/screenManager.h"
#include "utils/math.h"

namespace LeFlappyBird
{
	namespace Rules
	{
		static const float SCREEN_MARGIN = 50.0f;
		static const int BUTTON_WIDTH = 200;
		static const int BUTTON_HEIGHT = 50;

		static const int CHANGE_PAGE_BUTTON_SIZE = 70;
		int actualPage = 0;

		static Buttons::Button goBackButton;
		static Buttons::Button changePageButton;
		void init()
		{
			goBackButton = Buttons::createButton({ SCREEN_MARGIN, static_cast<float>(GetScreenHeight() - BUTTON_HEIGHT - SCREEN_MARGIN), BUTTON_WIDTH, BUTTON_HEIGHT });
			changePageButton = Buttons::createButton({ static_cast<float>(GetScreenWidth() - CHANGE_PAGE_BUTTON_SIZE - SCREEN_MARGIN) ,static_cast<float>(GetScreenHeight() - CHANGE_PAGE_BUTTON_SIZE - SCREEN_MARGIN) , CHANGE_PAGE_BUTTON_SIZE ,CHANGE_PAGE_BUTTON_SIZE });
			actualPage = 0;
		}

		void checkCreditsInputAndCollision()
		{
			Buttons::updateButton(goBackButton);
			Buttons::updateButton(changePageButton);

			if (goBackButton.isClicked)
			{
				ScreensManager::changeScreenTo(ScreensManager::MENU);
			}

			if (changePageButton.isClicked)
			{
#if defined(PLATFORM_WEB)
				if (actualPage == 0)
				{
					actualPage = 1;
				}
				else if (actualPage == 1)
					actualPage = 2;
				else
					actualPage = 0;
#else
				if (actualPage == 0)
				{
					actualPage = 1;
				}
				else
					actualPage = 0;
#endif

			}
		}

		void draw()
		{
			Texture changePageTexture = AssetManager::getTexture(AssetManager::RULES_CHANGE_PAGE);

			if (actualPage == 0)
				DrawTextureEx(AssetManager::getTexture(AssetManager::RULES_PAGE_ONE), { 0.0f, 0.0f }, 0, 1, WHITE);
			else if(actualPage == 1)
				DrawTextureEx(AssetManager::getTexture(AssetManager::RULES_PAGE_TWO), { 0.0f, 0.0f }, 0, 1, WHITE);
			else
				DrawTextureEx(AssetManager::getTexture(AssetManager::RULES_PAGE_THREE), { 0.0f, 0.0f }, 0, 1, WHITE);

			Buttons::drawTextureInButton(changePageButton, changePageTexture);

			Buttons::drawButton(goBackButton);
			Buttons::drawCenteredTextInButton(goBackButton, "GO BACK");
		}
	}
}
