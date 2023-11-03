#include "bird.h"

#include "utils/screen.h"

namespace LeFlappyBird {
	namespace Bird {
		static const float BIRD_VELOCITY = 500.0f;
		static const Vector2 BIRD_SIZE = { 50.0f, 50.0f };

		static void checkBirdScreenCollisions(Bird& bird) {
			ScreenUtils::Entity birdEntity = { bird.position, { 0.0f, bird.velocity }, BIRD_SIZE };
			ScreenUtils::checkPositionByScreenBounds(birdEntity);

			bird.position = birdEntity.position;
		}

		Bird createBird(Vector2 position) {
			return {
				position,
				BIRD_VELOCITY
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
#ifdef _DEBUG
			DrawRectangleRec({
				bird.position.x,
				bird.position.y,
				BIRD_SIZE.x,
				BIRD_SIZE.y
			}, RED);
#endif 
		};
	}
}
