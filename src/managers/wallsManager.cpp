#include <vector>

#include "utils/timer.h"
#include "entities/wall.h"
#include "utils/screen.h"
#include "utils/math.h"
#include "assets/assetManager.h"

namespace LeFlappyBird {
	namespace WallsManager {
		static float wallSpawnTime = 2.0f;
		static Vector2 lastWallPosition;

		Timer::Timer wallSpawnTimer;

		std::vector<Wall::Wall> walls;

		void init() {
			wallSpawnTime = 2.0f;
			Timer::startTimer(&wallSpawnTimer, wallSpawnTime);

			lastWallPosition = {
				ScreenUtils::getScreenWidth(),
				static_cast<float>(Wall::createRandomYStartValue(0, 0))
			};

			walls = { Wall::createWall(lastWallPosition) };
		};

		void updateWalls(int& score, Vector2 birdPosition, bool isPaused, float& speedMultiplier) {

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
				Timer::startTimer(&wallSpawnTimer, wallSpawnTime);
			}

			for (size_t i = 0; i < walls.size(); i++) {
				if (Wall::isDisappearing(walls[i])) {
					walls.erase(walls.begin() + i);
				}
				else {
					Wall::updateWall(walls[i], birdPosition, score, speedMultiplier, wallSpawnTime);
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
					PlaySound(AssetManager::getSound(AssetManager::Sounds::WALL_HIT));
					return true;
				}
			}
			return false;
		};
	}
}