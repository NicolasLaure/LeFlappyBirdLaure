#include "gameplay.h"

#include "entities/bird.h"
#include "managers/screenManager.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace Gameplay {
		struct GameplayEntities {
			Bird::Bird bird;
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

			gameplayEntities = {
				LeFlappyBird::Bird::createBird(BIRD_INIT_POSITION),
				0
			};
			initManagers();
		}

		void updateGameplay() {
			Bird::updateBird(gameplayEntities.bird);
		}

		void drawGameplay() {
			Bird::drawBird(gameplayEntities.bird);
		}
	}
}
