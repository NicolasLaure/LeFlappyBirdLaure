#pragma once

namespace LeFlappyBird {
	namespace Gameplay {

		void initGameplay(bool isMultiplayer);
		void updateGameplay(bool& isPaused, bool& isGameOver, int& score);
		void drawGameplay(int score);
	}
}
