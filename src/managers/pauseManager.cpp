#include "managers/pauseManager.h"

#include "raylib.h"
#include <string>

#include "assets/assetManager.h"
#include "uiComponents/button.h"
#include "managers/screenManager.h"
#include "assets/fontManager.h"
#include "utils/timer.h"
#include "utils/screen.h"

using namespace std;

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

		static const float SCORE_FONT_SIZE = 50.0f;
		static const float SCORE_SPACING = 3.0f;

		static bool isResuming = false;
		static Timer::Timer resumeTimer;
		static const double resumeDuration = 3;

		void init()
		{
			int buttonSpacing = 50;
			Rectangle pauseButtonRect = { ScreenUtils::getScreenWidth() / 2 - (BUTTON_SIZE + buttonSpacing),ScreenUtils::getScreenHeight() / 2 - BUTTON_SIZE / 2,120,120 };
			for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
			{
				if (i == 0)
					pauseOptions[i] = { CONTINUE, AssetManager::getTexture(AssetManager::Assets::CONTINUE_BUTTON), Buttons::createButton(pauseButtonRect) };
				else
				{
					pauseButtonRect.x = ScreenUtils::getScreenWidth() / 2 + buttonSpacing;
					pauseOptions[i] = { MENU, AssetManager::getTexture(AssetManager::Assets::MAIN_MENU_BUTTON), Buttons::createButton(pauseButtonRect) };
				}
			}
		}
		void Update(bool& isPaused)
		{
			if (isResuming && Timer::timerDone(resumeTimer))
			{
				isPaused = false;
				isResuming = false;
			}
			else
				checkMenuInputAndCollision(isPaused);
		}

		void Draw(bool isGameOver, int score)
		{
			if (!isResuming)
			{

				Texture pausePanel = AssetManager::getTexture(AssetManager::Assets::PAUSE_PANEL);
				if (isGameOver)
				{
					pausePanel = AssetManager::getTexture(AssetManager::Assets::GAME_OVER_PANEL);
				}

				Rectangle source = {
					0.0f,
					0.0f,
					static_cast<float>(pausePanel.width),
					static_cast<float>(pausePanel.height)
				};
				Rectangle dest = {
					0.0f,
					0.0f,
					ScreenUtils::getScreenWidth(),
					ScreenUtils::getScreenHeight(),
				};
				DrawTexturePro(pausePanel, source, dest, { 0,0 }, 0, WHITE);

				for (int i = 0; i < Option::OPTIONS_QUANTITY; i++)
				{
					Buttons::drawTextureInButton(pauseOptions[i].optionButton, pauseOptions[i].texture);
				}

				if (isGameOver)
				{
					string scoreString = "Your Score was:" + to_string(score);
					float posX = ScreenUtils::getScreenWidth() / 2 - FontManager::measureText(scoreString.c_str(), SCORE_FONT_SIZE, SCORE_SPACING).x / 2;
					static const int ScoreUpperDisplacement = 120;
					float posY = ScreenUtils::getScreenHeight() / 2 - ScoreUpperDisplacement;
					FontManager::drawText(scoreString.c_str(), { posX, posY }, SCORE_FONT_SIZE, SCORE_SPACING, WHITE);
				}
			}
			else
			{
				static const int RESUME_TEXT_SIZE = 150;
				static const int RESUME_TEXT_SPACING = 0;
				string timeLeftText = to_string(static_cast<int>(Timer::getTimerCountDown(resumeTimer)));
				Vector2 textSize = FontManager::measureText(timeLeftText.c_str(), RESUME_TEXT_SIZE, RESUME_TEXT_SPACING);
				Vector2 pos = { ScreenUtils::getScreenWidth() / 2 - textSize.x / 2 ,ScreenUtils::getScreenHeight() / 2 - textSize.y / 2 };
				FontManager::drawText(timeLeftText.c_str(), pos, RESUME_TEXT_SIZE, RESUME_TEXT_SPACING, WHITE);
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
				{
					if (!isResuming)
					{
						Timer::startTimer(&resumeTimer, resumeDuration);
						isResuming = true;
					}
				}
		}
		static void actionPerPauseOption(Option option, bool& isPaused)
		{
			switch (option)
			{
			case Option::CONTINUE:
				if (!isResuming)
				{
					Timer::startTimer(&resumeTimer, resumeDuration);
					isResuming = true;
				}
				break;
			case Option::MENU:
				ScreensManager::changeScreenTo(ScreensManager::Screens::MENU);
				isPaused = false;
				break;
			}
		}
	}
}