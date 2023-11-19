#include "managers/pauseManager.h"

#include "raylib.h"

#include "assets/assetManager.h"
#include "uiComponents/button.h"
#include "managers/screenManager.h"

namespace LeFlappyBird
{
	namespace Pause
	{
		enum Option
		{
			CONTINUE,
			MENU,
			OPTIONS_QUANTITY
		};

		struct PauseOption
		{
			Option option;
			Texture texture;
			Buttons::Button optionButton;
		};

		static PauseOption pauseOptions[Option::OPTIONS_QUANTITY];

		static void actionPerPauseOption(Option option, bool& isPaused);
		void checkMenuInputAndCollision(bool& isPaused);

		static const int BUTTON_SIZE = 120;

		void init()
		{
			int buttonSpacing = 50;
			Rectangle pauseButtonRect = { static_cast<float>(GetScreenWidth()) / 2 - (BUTTON_SIZE + buttonSpacing),static_cast<float>(GetScreenHeight()) / 2 - BUTTON_SIZE / 2,120,120 };
			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				if (i == 0)
					pauseOptions[i] = { CONTINUE, AssetManager::getTexture(AssetManager::Assets::CONTINUE_BUTTON), Buttons::createButton(pauseButtonRect) };
				else
				{
					pauseButtonRect.x = static_cast<float>(GetScreenWidth()) / 2 + buttonSpacing;
					pauseOptions[i] = { MENU, AssetManager::getTexture(AssetManager::Assets::MAIN_MENU_BUTTON), Buttons::createButton(pauseButtonRect) };
				}
			}
		}
		void Update(bool& isPaused)
		{
			checkMenuInputAndCollision(isPaused);
		}
		void Draw()
		{
			Texture pausePanel = AssetManager::getTexture(AssetManager::Assets::PAUSE_PANEL);

			Rectangle source = {
				0.0f,
				0.0f,
				static_cast<float>(pausePanel.width),
				static_cast<float>(pausePanel.height)
			};

			Rectangle dest = {
				0.0f,
				0.0f,
				static_cast<float>(GetScreenWidth()),
				static_cast<float>(GetScreenHeight()),
			};
			DrawTexturePro(pausePanel, source, dest, { 0,0 }, 0, WHITE);

			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				Buttons::drawTextureInButton(pauseOptions[i].optionButton, pauseOptions[i].texture);
			}
		}

		void checkMenuInputAndCollision(bool& isPaused)
		{
			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				Buttons::updateButton(pauseOptions[i].optionButton);

				if (pauseOptions[i].optionButton.isClicked)
				{
					actionPerPauseOption(pauseOptions[i].option, isPaused);
				}
			};

			if (IsKeyPressed(KEY_ESCAPE) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
				if (isPaused)
					isPaused = false;
		}
		static void actionPerPauseOption(Option option, bool& isPaused)
		{
			switch (option)
			{
			case Option::CONTINUE:
					isPaused = false;
				break;
			case Option::MENU:
				ScreensManager::changeScreenTo(ScreensManager::Screens::MENU);
				isPaused = false;
				break;
			}
		}
	}
}