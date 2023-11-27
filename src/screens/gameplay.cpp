#include "gameplay.h"

#include "entities/bird.h"
#include "managers/screenManager.h"
#include "managers/uiManager.h"
#include "managers/backgroundManager.h"
#include "managers/wallsManager.h"
#include "utils/screen.h"
#include "utils/math.h"
#include "assets/assetManager.h"

namespace LeFlappyBird
{
	namespace Gameplay
	{
		struct GameplayEntities
		{
			Bird::Bird firstPlayerBird;
		};

		static	Vector2 BIRD_INIT_POSITION;

		static Vector2 WALL_INIT_POSITION;

		static GameplayEntities gameplayEntities;

		static float gameSpeedMultiplier;
		void gameOver(bool& isPaused, bool& isGameOver);

		static void initManagers()
		{
			BackgroundManager::initBackground();
			WallsManager::init();
		}

		static void initEntities()
		{
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION, true),
			};
		}

		static void restartEntities(int& score)
		{
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION, true),
			};

			WallsManager::init();

			gameSpeedMultiplier = 1;
			score = 0;
		}

		void initGameplay(bool isMultiplayer)
		{
			BIRD_INIT_POSITION = {
				ScreenUtils::getScreenWidth() / 8,
				MathUtils::getHalf(ScreenUtils::getScreenHeight())
			};
			initEntities();
			initManagers();

			PlayMusicStream(AssetManager::getMusic(AssetManager::Musics::GAMEPLAY_MUSIC));

			gameSpeedMultiplier = 1;
		}

		void updateGameplay(bool& isPaused, bool& isGameOver, int& score)
		{
			if (isGameOver)
			{
				restartEntities(score);
				isGameOver = false;
			}

			if (IsKeyPressed(KEY_ESCAPE) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
				isPaused = true;

			Bird::updateBird(gameplayEntities.firstPlayerBird);
			WallsManager::updateWalls(score, gameplayEntities.firstPlayerBird.position, isPaused, gameSpeedMultiplier);

			if (Bird::isCollidingBottom(gameplayEntities.firstPlayerBird) || WallsManager::isCollidingWithWall(gameplayEntities.firstPlayerBird))
			{
				gameOver(isPaused, isGameOver);
				//restartEntities();
			};

			BackgroundManager::updateBackground(gameSpeedMultiplier);

			UpdateMusicStream(AssetManager::getMusic(AssetManager::Musics::GAMEPLAY_MUSIC));
		}

		void drawGameplay(int score)
		{
			BackgroundManager::drawBackground();
			Bird::drawBird(gameplayEntities.firstPlayerBird);
			WallsManager::draw();
			UiManager::draw(score);
		}

		void gameOver(bool& isPaused, bool& isGameOver)
		{
			isGameOver = true;
			isPaused = true;
		}
	}
}
