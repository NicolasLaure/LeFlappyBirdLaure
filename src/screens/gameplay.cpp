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
			int points = 0;
		};

		static bool isMultiPlayer = false;
		static	Vector2 BIRD_INIT_POSITION;

		static Vector2 WALL_INIT_POSITION;

		static GameplayEntities gameplayEntities;

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
					0
				};
			}
			else
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					Bird::createBird(BIRD_INIT_POSITION, false),
					0
				};
			}
		}

		static void restartEntities()
		{
			if (!isMultiPlayer)
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					NULL,
					0
				};
			}
			else
			{
				gameplayEntities = {
					Bird::createBird(BIRD_INIT_POSITION, true),
					Bird::createBird(BIRD_INIT_POSITION, false),
					0
				};
			}

			WallsManager::init();
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

		void updateGameplay(bool& isPaused)
		{

			Bird::updateBird(gameplayEntities.firstPlayerBird);
			WallsManager::updateWalls();

			if (Bird::isCollidingBottom(gameplayEntities.firstPlayerBird) || WallsManager::isCollidingWithWall(gameplayEntities.firstPlayerBird))
			{
				restartEntities();
			};

			if (isMultiPlayer)
			{
				Bird::updateBird(gameplayEntities.secondPlayerBird);

				if (Bird::isCollidingBottom(gameplayEntities.secondPlayerBird) || WallsManager::isCollidingWithWall(gameplayEntities.secondPlayerBird))
				{
					restartEntities();
				};
			}

			if (IsKeyPressed(KEY_ESCAPE) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
				isPaused = true;

			BackgroundManager::updateBackground();
			UiManager::update();
		}

		void drawGameplay()
		{
			BackgroundManager::drawBackground();
			Bird::drawBird(gameplayEntities.firstPlayerBird);
			if (isMultiPlayer)
				Bird::drawBird(gameplayEntities.secondPlayerBird);
			WallsManager::draw();
			UiManager::draw();
		}
	}
}
