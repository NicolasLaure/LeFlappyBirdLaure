#include "bird.h"

#include "utils/screen.h"

namespace LeFlappyBird {
	namespace Bird {
		static const float BIRD_VELOCITY = 500.0f;
		static const Vector2 BIRD_SIZE = { 50.0f, 50.0f };

		static void checkBirdScreenCollisions(Bird& bird) {
			ScreenUtils::Entity birdEntity = { bird.position, { 0.0f, bird.velocity }, bird.size };
			ScreenUtils::checkPositionByScreenBounds(birdEntity);

			bird.position = birdEntity.position;
		}

		Bird createBird(Vector2 position) {
			return {
				position,
				BIRD_VELOCITY,
				BIRD_SIZE
			};
		};

		void updateBird(Bird& bird) {
			if (IsKeyDown(bird.goUpbutton)) {
				bird.position.y -= bird.velocity * GetFrameTime();
			}
			else if (IsKeyDown(bird.goDownButton)) {
				bird.position.y += bird.velocity * GetFrameTime();
			}

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
