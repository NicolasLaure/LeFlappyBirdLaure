#include "wall.h"

#include "utils/screen.h"

namespace LeFlappyBird {
	namespace Wall {
		static const float WALL_VELOCITY = 200.0f;
		static const Vector2 WALL_SIZE = { 50.0f, 200.0f };

		Wall createWall(Vector2 position) {
			return {
				position,
				WALL_VELOCITY,
				WALL_SIZE
			};
		}

		void updateWall(Wall& wall) {
			wall.position.x -= WALL_VELOCITY * GetFrameTime();

			if (wall.position.x < -WALL_SIZE.x) {
				wall.position = {
					ScreenUtils::getScreenWidth(),
					static_cast<float>(createRandomYStartValue())
				};
			}
		}

		void drawWall(Wall wall) {
			DrawRectangleRec({
				wall.position.x,
				wall.position.y,
				wall.size.x,
				wall.size.y
				}, YELLOW);
		};

		int createRandomYStartValue() {
			return GetRandomValue(
				0,
				static_cast<int>(ScreenUtils::getScreenHeight() - WALL_SIZE.y)
			);
		}

		Rectangle getRectangle(Wall wall) {
			return {
				wall.position.x,
				wall.position.y,
				wall.size.x,
				wall.size.y
			};
		}
	}
}
