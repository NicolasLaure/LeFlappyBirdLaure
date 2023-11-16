#include "bird.h"

#include "assets/assetManager.h"
#include "utils/screen.h"
#include "utils/math.h"
#include "utils/timer.h"
#include "raymath.h"

#include <iostream>

namespace LeFlappyBird {
	namespace Bird {
		static const float BIRD_VELOCITY_UP = -400.0f;
		static const float BIRD_ACCELERATION = 1000.0f;
		static const Vector2 BIRD_SIZE = { 64.0f, 64.0f };
		static const Vector2 BIRD_COLLISSION_SIZE = { 50.0f, 50.0f };
		
		static Timer::Timer flyingTimer;
		static const double FLYING_TIMER_LIFETIME = 0.3;

		static float getVelocityPercentage(float velocity) {
			return velocity / -BIRD_VELOCITY_UP;
		}

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
			Timer::startTimer(&flyingTimer, 0.0);

			return {
				position,
				{ 0, 0 },
				BIRD_SIZE
			};
		};

		void updateBird(Bird& bird) {
			if (IsKeyPressed(bird.goUpbutton) && !isBirdInNonFlySpace(bird)) {
				Timer::startTimer(&flyingTimer, FLYING_TIMER_LIFETIME);
				bird.velocity.y = BIRD_VELOCITY_UP;
			}

			bird.velocity.y += BIRD_ACCELERATION * GetFrameTime();

			bird.position.y += bird.velocity.y * GetFrameTime();

			std::cout << MathUtils::clamp(getVelocityPercentage(bird.velocity.y) * 90.0f, -90.0f, 65.0f) << std::endl;

			checkBirdScreenCollisions(bird);
		};

		void drawBird(Bird bird) {
#ifdef _DEBUG
			DrawRectangleRec({
				bird.position.x + MathUtils::getHalf((BIRD_SIZE.x - BIRD_COLLISSION_SIZE.x)),
				bird.position.y + MathUtils::getHalf((BIRD_SIZE.y - BIRD_COLLISSION_SIZE.y)),
				BIRD_COLLISSION_SIZE.x,
				BIRD_COLLISSION_SIZE.y
			}, RED);
#endif
			Texture2D birdTexture = AssetManager::getTexture(
				!Timer::timerDone(flyingTimer) ? 
				AssetManager::CHEESECAKE_FLYING : 
				AssetManager::CHEESECAKE
			);

			Rectangle source = {
				0.0f,
				0.0f,
				static_cast<float>(birdTexture.width),
				static_cast<float>(birdTexture.height)
			};

			Rectangle dest = {
				bird.position.x + MathUtils::getHalf(bird.size.x),
				bird.position.y + MathUtils::getHalf(bird.size.y),
				bird.size.x,
				bird.size.y
			};

			Vector2 origin = { 
				MathUtils::getHalf(static_cast<float>(birdTexture.width)),
				MathUtils::getHalf(static_cast<float>(birdTexture.height))
			};

			DrawTexturePro(
				birdTexture,
				source,
				dest,
				origin,
				MathUtils::clamp(getVelocityPercentage(bird.velocity.y) * 90.0f, -90.0f, 60.0f),
				WHITE
			);
		};

		Rectangle getRectangle(Bird bird) {
			return {
				bird.position.x + MathUtils::getHalf((BIRD_SIZE.x - BIRD_COLLISSION_SIZE.x)),
				bird.position.y + MathUtils::getHalf((BIRD_SIZE.y - BIRD_COLLISSION_SIZE.y)),
				BIRD_COLLISSION_SIZE.x,
				BIRD_COLLISSION_SIZE.y
			};
		}

		bool isCollidingBottom(Bird bird) {
			ScreenUtils::Entity birdEntity = { bird.position, bird.velocity, { 0.0f, 0.0f } };

			return ScreenUtils::isCollidingInScreenPart(birdEntity, ScreenUtils::BOTTOM);
		}
	}
}
