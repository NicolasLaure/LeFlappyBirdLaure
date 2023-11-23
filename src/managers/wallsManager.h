#pragma once
#include "entities/bird.h"

namespace LeFlappyBird {
	namespace WallsManager {
		void init();
		void updateWalls(int& score, bool isPaused);
		void draw();
		bool isCollidingWithWall(Bird::Bird bird);
	}
}
