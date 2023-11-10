#include "bird.h"

#include "utils/screen.h"
#include "utils/math.h"
#include "raymath.h"

namespace LeFlappyBird {
	namespace Bird {
		static const float BIRD_VELOCITY_UP = -500.0f;
		static const float BIRD_ACCELERATION = 1000.0f;
		static const Vector2 BIRD_SIZE = { 50.0f, 50.0f };

		static bool isBirdInNonFlySpace(Bird bird) {
			return bird.position.y + MathUtils::getHalf(bird.size.y) < 0;
		}

		static void checkBirdScreenCollisions(Bird& bird) {
			ScreenUtils::Entity birdEntity = { bird.position, bird.velocity, bird.size };
			ScreenUtils::checkPositionByScreenBounds(birdEntity, {
					0,
					ScreenUtils::getScreenWidth() - birdEntity.size.x
				}, {
					-birdEntity.size.y,
					ScreenUtils::getScreenHeight()
				});

			bird.position = birdEntity.position;
		}

		Bird createBird(Vector2 position) {
			return {
				position,
				{ 0, 0 },
				BIRD_SIZE
			};
		};

		void updateBird(Bird& bird) {
			if (IsKeyPressed(bird.goUpbutton) && !isBirdInNonFlySpace(bird)) {
				bird.velocity.y = BIRD_VELOCITY_UP;
			}

			bird.velocity.y += BIRD_ACCELERATION * GetFrameTime();

			bird.position.y += bird.velocity.y * GetFrameTime();

			checkBirdScreenCollisions(bird);
		};

		void drawBird(Bird bird) {
			DrawRectangleRec({
				bird.position.x,
				bird.position.y,
				bird.size.x,
				bird.size.y
			}, RED);
		};

		Rectangle getRectangle(Bird bird) {
			return {
				bird.position.x,
				bird.position.y,
				bird.size.x,
				bird.size.y
			};
		}

		bool isCollidingBottom(Bird bird) {
			ScreenUtils::Entity birdEntity = { bird.position, bird.velocity, { 0.0f, 0.0f } };

			return ScreenUtils::isCollidingInScreenPart(birdEntity, ScreenUtils::BOTTOM);
		}
	}
}
