#include "menu.h"

#include "utils/math.h"
#include "utils/screen.h"
#include "managers/screenManager.h"
#include "assets/assetManager.h"
#include "assets/fontManager.h"

namespace LeFlappyBird
{
	namespace Menu
	{
		static const float OPTION_RECTANGLE_WIDTH = 300.0f;
		static const float OPTION_RECTANGLE_HEIGHT = 40.0f;

		static const float TOP_MARGIN = 120.0f;
		static const float OPTION_RECTANGLE_MARGIN = 25.0f;
		static const float TITLE_TOP_MARGIN = 40.0f;
		static const float TITLE_FONT_SIZE = 50.0f;
		static const float TITLE_SPACING = 3.0f;

		static MenuOption menuOptions[Option::OPTIONS_QUANTITY];

		static void drawOptionBox(MenuOption option)
		{
			Buttons::drawButton(option.optionButton);
		}

		static std::string optionToText(Option option)
		{
			switch (option)
			{
			case Option::SINGLEPLAYER:
				return "Single Player";
			case Option::MULTIPLAYER:
				return "Two Players";
			case Option::EXIT:
				return "Exit";
			case Option::READ_RULES:
				return "Rules";
			case Option::READ_CREDITS:
				return "Credits";
			default:
				return "";
			}
		}

		static void actionPerMenuOption(Option option, bool& shouldClose)
		{
			switch (option)
			{
			case Option::SINGLEPLAYER:
				ScreensManager::changeScreenTo(ScreensManager::Screens::GAMEPLAY);
				break;
			case Option::MULTIPLAYER:
				ScreensManager::changeScreenTo(ScreensManager::Screens::MULTIPLAYER_GAMEPLAY);
				break;
			case Option::READ_CREDITS:
				ScreensManager::changeScreenTo(ScreensManager::Screens::CREDITS);
				break;
			case Option::READ_RULES:
				ScreensManager::changeScreenTo(ScreensManager::Screens::RULES);
				break;
			case Option::EXIT:
				shouldClose = true;
				break;
			}
		}

		void initMenu()
		{
			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				float yPosition = TOP_MARGIN + (OPTION_RECTANGLE_MARGIN + OPTION_RECTANGLE_HEIGHT) * i;
				float screenWidth = ScreenUtils::getScreenWidth();

				Rectangle optionRectangle = {
				MathUtils::getHalf(screenWidth) - MathUtils::getHalf(OPTION_RECTANGLE_WIDTH),
				yPosition,
				OPTION_RECTANGLE_WIDTH,
				OPTION_RECTANGLE_HEIGHT
				};

				menuOptions[i] = {
					(Option)i,
					optionToText((Option)i),
					Buttons::createButton(optionRectangle)
				};
			}
			PlayMusicStream(AssetManager::getMusic(AssetManager::Musics::MENU_MUSIC));
		}

		void update(bool& shouldClose)
		{
			UpdateMusicStream(AssetManager::getMusic(AssetManager::Musics::MENU_MUSIC));
			checkMenuInputAndCollision(shouldClose);
		}
		void drawMenu()
		{
			const char* title = "LeFlappyBird";
			Vector2 titleSize = FontManager::measureText(title, TITLE_FONT_SIZE, TITLE_SPACING);
			float screenWidth = ScreenUtils::getScreenWidth();
			float asteroidsTitlePosX = MathUtils::getHalf(screenWidth) - MathUtils::getHalf(titleSize.x);

			FontManager::drawText(
				title, { asteroidsTitlePosX, TITLE_TOP_MARGIN }, TITLE_FONT_SIZE, TITLE_SPACING, WHITE);

			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				drawOptionBox(menuOptions[i]);
				Buttons::drawCenteredTextInButton(menuOptions[i].optionButton, menuOptions[i].text.c_str());
			}

			FontManager::drawText("0.3", { 10, 0 }, TITLE_FONT_SIZE, TITLE_SPACING, WHITE);
		}

		void checkMenuInputAndCollision(bool& shouldClose)
		{
			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				Buttons::updateButton(menuOptions[i].optionButton);

				if (menuOptions[i].optionButton.isClicked)
				{
					actionPerMenuOption(menuOptions[i].option, shouldClose);
				}
			};
		}
	}

}