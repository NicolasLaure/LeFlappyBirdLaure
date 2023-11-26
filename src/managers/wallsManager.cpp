#include <vector>

#include "utils/timer.h"
#include "entities/wall.h"
#include "utils/screen.h"
#include "utils/math.h"

namespace LeFlappyBird {
	namespace WallsManager {
		static const double WALL_SPAWN_TIME = 2.0;
		static Vector2 lastWallPosition;

		Timer::Timer wallSpawnTimer;

		std::vector<Wall::Wall> walls;

		void init() {
			Timer::startTimer(&wallSpawnTimer, WALL_SPAWN_TIME);

			lastWallPosition = {
				ScreenUtils::getScreenWidth(),
				static_cast<float>(Wall::createRandomYStartValue(0, 0))
			};

			walls = { Wall::createWall(lastWallPosition) };
		};

		void updateWalls(int& score, Vector2 birdPosition, bool isPaused) {

			if (isPaused)
				Timer::pauseTimer(&wallSpawnTimer);
			else if (!isPaused && Timer::isPaused(wallSpawnTimer))
				Timer::unPauseTimer(&wallSpawnTimer);

			if (Timer::timerDone(wallSpawnTimer)) {
				Vector2 nextWallPosition;
				if (lastWallPosition.y > MathUtils::getHalf(ScreenUtils::getScreenHeight())) {
					nextWallPosition = {
						lastWallPosition.x,
						static_cast<float>(
							Wall::createRandomYStartValue(
								0,
								static_cast<int>(
									MathUtils::getHalf(ScreenUtils::getScreenHeight())
								)
							)
						)
					};
				}
				else {
					nextWallPosition = {
						lastWallPosition.x,
						static_cast<float>(
							Wall::createRandomYStartValue(
								static_cast<int>(
									MathUtils::getHalf(ScreenUtils::getScreenHeight())
								),
								0
							)
						)
					};
				}

				walls.push_back(Wall::createWall(nextWallPosition));
				lastWallPosition = nextWallPosition;
				Timer::startTimer(&wallSpawnTimer, WALL_SPAWN_TIME);
			}

			for (size_t i = 0; i < walls.size(); i++) {
				if (Wall::isDisappearing(walls[i])) {
					walls.erase(walls.begin() + i);
				}
				else {
					Wall::updateWall(walls[i], birdPosition, score);
				}
			}
		};

		void draw() {
			for (size_t i = 0; i < walls.size(); i++) {
				Wall::drawWall(walls[i]);
			}
		};

		bool isCollidingWithWall(Bird::Bird bird) {
			for (size_t i = 0; i < walls.size(); i++) {
				if (Wall::collidesWith(walls[i], bird)) {
					return true;
				}
			}
			return false;
		};
	}
}