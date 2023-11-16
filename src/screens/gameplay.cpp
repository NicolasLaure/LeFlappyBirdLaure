#include "gameplay.h"

#include "entities/bird.h"
#include "managers/screenManager.h"
#include "managers/uiManager.h"
#include "managers/backgroundManager.h"
#include "managers/wallsManager.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace Gameplay {
		struct GameplayEntities {
			Bird::Bird bird;
			int points = 0;
		};

		static	Vector2 BIRD_INIT_POSITION;

		static Vector2 WALL_INIT_POSITION;

		static GameplayEntities gameplayEntities;

		static void initManagers() {
			BackgroundManager::initBackground();
			UiManager::init();
			WallsManager::init();
		}

		static void initEntities() {
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION),
				0
			};
		}

		static void restartEntities() {
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION),
				0
			};

			WallsManager::init();
		}

		void initGameplay() {
			BIRD_INIT_POSITION = {
				ScreenUtils::getScreenWidth() / 8,
				MathUtils::getHalf(ScreenUtils::getScreenHeight())
			};

			initEntities();
			initManagers();
		}

		void updateGameplay() {
			Bird::updateBird(gameplayEntities.bird);
			WallsManager::updateWalls();

			if (Bird::isCollidingBottom(gameplayEntities.bird) || WallsManager::isCollidingWithWall(gameplayEntities.bird)) {
				restartEntities();
			};

			BackgroundManager::updateBackground();
			UiManager::update();
		}

		void drawGameplay() {
			BackgroundManager::drawBackground();
			Bird::drawBird(gameplayEntities.bird);
			WallsManager::draw();
			UiManager::draw();
		}
	}
}
