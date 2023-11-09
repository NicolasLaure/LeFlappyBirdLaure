#include "gameplay.h"

#include "entities/bird.h"
#include "entities/wall.h"
#include "managers/screenManager.h"
#include "managers/uiManager.h"
#include "managers/backgroundManager.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace Gameplay {
		struct GameplayEntities {
			Bird::Bird bird;
			Wall::Wall wall;
			int points = 0;
		};

		static	Vector2 BIRD_INIT_POSITION;

		static Vector2 WALL_INIT_POSITION;

		static GameplayEntities gameplayEntities;

		static void initManagers() {
			BackgroundManager::initBackground();
			UiManager::init();
		}

		static void initEntities() {
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION),
				Wall::createWall(WALL_INIT_POSITION),
				0
			};
		}

		static void restartEntities() {
			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION),
				Wall::createWall({
						WALL_INIT_POSITION.x,
						static_cast<float>(Wall::createRandomYStartValue())
					}),
				0
			};
		}

		void initGameplay() {
			BIRD_INIT_POSITION = {
				ScreenUtils::getScreenWidth() / 8,
				MathUtils::getHalf(ScreenUtils::getScreenHeight())
			};

			WALL_INIT_POSITION = {
			ScreenUtils::getScreenWidth(),
			static_cast<float>(Wall::createRandomYStartValue())
			};

			initEntities();
			initManagers();
		}

		void updateGameplay() {
			Bird::updateBird(gameplayEntities.bird);
			Wall::updateWall(gameplayEntities.wall);

			if (MathUtils::checkRectangleCollision(Bird::getRectangle(gameplayEntities.bird), Wall::getRectangle(gameplayEntities.wall))) {
				restartEntities();
			};

			BackgroundManager::updateBackground();
			UiManager::update();
		}

		void drawGameplay() {
			BackgroundManager::drawBackground();
			Bird::drawBird(gameplayEntities.bird);
			Wall::drawWall(gameplayEntities.wall);
			UiManager::draw();
		}
	}
}
