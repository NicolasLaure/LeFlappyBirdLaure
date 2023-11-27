#pragma once
#include "raylib.h"

#include "entities/bird.h"

namespace LeFlappyBird
{
	namespace Wall
	{
		struct Wall
		{
			Vector2 position;
			float velocity;
			Vector2 size;
			bool wasPassed{ false };
		};

		Wall createWall(Vector2 position);
		void updateWall(Wall& wall, Vector2 birdPosition, int& score, float& speedMultiplier, float& spawnTime);
		void drawWall(Wall wall);
		int createRandomYStartValue(int topMargin, int bottomMargin);
		bool isDisappearing(Wall wall);
		bool collidesWith(Wall wall, Bird::Bird bird);
	}
}
