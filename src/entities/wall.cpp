#include "wall.h"

#include "utils/screen.h"
#include "utils/math.h"
#include "assets/assetManager.h"

namespace LeFlappyBird
{
	namespace Wall
	{
		static const float WALL_VELOCITY = 200.0f;
		static const Vector2 SPACE_SIZE = { 50.0f, 200.0f };

		static Rectangle getTopRectangle(Wall wall)
		{
			return {
				wall.position.x,
				0,
				wall.size.x,
				wall.position.y
			};
		}

		static Rectangle getBottomRectangle(Wall wall)
		{
			return {
				wall.position.x,
				wall.position.y + wall.size.y,
				wall.size.x,
				ScreenUtils::getScreenHeight()
			};
		}

		Wall createWall(Vector2 position)
		{
			return {
				position,
				WALL_VELOCITY,
				SPACE_SIZE
			};
		}

		void updateWall(Wall& wall, Vector2 birdPosition, int& score, float& speedMultiplier, float& spawnTime)
		{
			wall.position.x -= WALL_VELOCITY * speedMultiplier * GetFrameTime();

			if (wall.position.x + wall.size.x < birdPosition.x && !wall.wasPassed)
			{
				score++;
				wall.wasPassed = true;
				const float TIME_AND_SPEED_VARIATION = 1.15f;
				speedMultiplier = MathUtils::clamp(speedMultiplier * TIME_AND_SPEED_VARIATION, 1, 3);
				spawnTime = MathUtils::clamp(spawnTime / TIME_AND_SPEED_VARIATION, 1, 2);
			}
		}

		void drawWall(Wall wall)
		{
			Texture upperPipe = AssetManager::getTexture(AssetManager::Textures::UPPER_PIPE);
			Rectangle upperSource = { 0,0, static_cast<float>(upperPipe.width), static_cast<float>(upperPipe.height) };
			DrawTexturePro(upperPipe, upperSource, getTopRectangle(wall), { 0,0 }, 0, WHITE);

			Texture lowerPipe = AssetManager::getTexture(AssetManager::Textures::LOWER_PIPE);
			Rectangle lowerSource = { 0,0, static_cast<float>(lowerPipe.width), static_cast<float>(lowerPipe.height) };
			DrawTexturePro(lowerPipe, lowerSource, getBottomRectangle(wall), { 0,0 }, 0, WHITE);
		};

		int createRandomYStartValue(int topMargin, int bottomMargin)
		{
			const int SPACE_MARGIN = 10;
			return GetRandomValue(
				SPACE_MARGIN + topMargin,
				static_cast<int>(ScreenUtils::getScreenHeight() - SPACE_SIZE.y - SPACE_MARGIN - bottomMargin)
			);
		}

		bool isDisappearing(Wall wall)
		{
			return wall.position.x < -SPACE_SIZE.x;
		}

		bool collidesWith(Wall wall, Bird::Bird bird)
		{
			return CheckCollisionCircleRec(
				Bird::getBirdCircle(bird).position, Bird::getBirdCircle(bird).radius,
				getTopRectangle(wall)
			) || MathUtils::checkRectangleCollision(
				Bird::getRectangle(bird),
				getBottomRectangle(wall)
			);
		}
	}
}
