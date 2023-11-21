#include "gameplay.h"

#include "entities/bird.h"
#include "managers/screenManager.h"
#include "managers/uiManager.h"
#include "managers/backgroundManager.h"
#include "managers/wallsManager.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird
{
	namespace Gameplay
	{
		struct GameplayEntities
		{
			Bird::Bird firstPlayerBird;
			Bird::Bird secondPlayerBird;

		};

		static bool isMultiPlayer = false;

		static	Vector2 BIRD_INIT_POSITION;

		static Vector2 WALL_INIT_POSITION;

		static GameplayEntities gameplayEntities;

		void gameOver(bool& isPaused, bool& isGameOver);

		static void initManagers()
		{
			BackgroundManager::initBackground();
			UiManager::init();
			WallsManager::init();
		}

		static void initEntities()
		{
			if (!isMultiPlayer)
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					NULL,
				};
			}
			else
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					Bird::createBird(BIRD_INIT_POSITION, false),
				};
			}
		}

		static void restartEntities(int& score)
		{
			if (!isMultiPlayer)
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					NULL,
				};
			}
			else
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					Bird::createBird(BIRD_INIT_POSITION, false),
				};
			}

			WallsManager::init();

			score = 0;
		}

		void initGameplay(bool isMultiplayer)
		{
			BIRD_INIT_POSITION = {
				ScreenUtils::getScreenWidth() / 8,
				MathUtils::getHalf(ScreenUtils::getScreenHeight())
			};
			Gameplay::isMultiPlayer = isMultiplayer;
			initEntities();
			initManagers();
		}

		void updateGameplay(bool& isPaused, bool& isGameOver, int& score)
		{
			if (isGameOver)
			{
				restartEntities(score);
				isGameOver = false;
			}

			Bird::updateBird(gameplayEntities.firstPlayerBird);
			WallsManager::updateWalls(score);

			if (Bird::isCollidingBottom(gameplayEntities.firstPlayerBird) || WallsManager::isCollidingWithWall(gameplayEntities.firstPlayerBird))
			{
				gameOver(isPaused, isGameOver);
				//restartEntities();
			};

			if (isMultiPlayer)
			{
				Bird::updateBird(gameplayEntities.secondPlayerBird);

				if (Bird::isCollidingBottom(gameplayEntities.secondPlayerBird) || WallsManager::isCollidingWithWall(gameplayEntities.secondPlayerBird))
				{
					gameOver(isPaused, isGameOver);
					//restartEntities();
				};
			}

			if (IsKeyPressed(KEY_ESCAPE) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
				isPaused = true;

			BackgroundManager::updateBackground();
			UiManager::update();
		}

		void drawGameplay(int score)
		{
			BackgroundManager::drawBackground();
			Bird::drawBird(gameplayEntities.firstPlayerBird);
			if (isMultiPlayer)
				Bird::drawBird(gameplayEntities.secondPlayerBird);
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
