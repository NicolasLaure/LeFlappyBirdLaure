#include "bird.h"

#include "utils/screen.h"
#include "raymath.h"

namespace LeFlappyBird {
	namespace Bird {
		static const float BIRD_VELOCITY_UP = -500.0f;
		static const float BIRD_ACCELERATION = 1000.0f;
		static const Vector2 BIRD_SIZE = { 50.0f, 50.0f };

		static void checkBirdScreenCollisions(Bird& bird) {
			ScreenUtils::Entity birdEntity = { bird.position, { 0.0f, bird.velocity.y }, bird.size };
			ScreenUtils::checkPositionByScreenBounds(birdEntity);

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
			if (IsKeyPressed(bird.goUpbutton)) {
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
	}
}
