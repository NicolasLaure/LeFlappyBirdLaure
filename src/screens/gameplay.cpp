#include "gameplay.h"

#include "managers/screenManager.h"

namespace LeFlappyBird {
	namespace Gameplay {
		struct GameplayEntities {
			int points = 0;
		};

		static GameplayEntities gameplayEntities;

		static void initManagers() {
		}

		void initGameplay() {
			gameplayEntities = {
				0
			};
			initManagers();
		}

		void updateGameplay() {
			
		}

		void drawGameplay() {
			
		}
	}
}
