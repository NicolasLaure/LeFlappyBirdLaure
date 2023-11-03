#include "gameplay.h"

#include "entities/bird.h"
#include "entities/wall.h"
#include "managers/screenManager.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace Gameplay {
		struct GameplayEntities {
			Bird::Bird bird;
			Wall::Wall wall;
			int points = 0;
		};

		static GameplayEntities gameplayEntities;

		static void initManagers() {
		}

		void initGameplay() {
			const Vector2 BIRD_INIT_POSITION = {
				ScreenUtils::getScreenWidth() / 8,
				MathUtils::getHalf(ScreenUtils::getScreenHeight())
			};

			const Vector2 WALL_INIT_POSITION = {
				ScreenUtils::getScreenWidth(),
				static_cast<float>(Wall::createRandomYStartValue())
			};

			gameplayEntities = {
				Bird::createBird(BIRD_INIT_POSITION),
				Wall::createWall(WALL_INIT_POSITION),
				0
			};
			initManagers();
		}

		void updateGameplay() {
			Bird::updateBird(gameplayEntities.bird);
			Wall::updateWall(gameplayEntities.wall);
		}

		void drawGameplay() {
			Bird::drawBird(gameplayEntities.bird);
			Wall::drawWall(gameplayEntities.wall);
		}
	}
}
