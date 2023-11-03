#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace Wall {
		struct Wall {
			Vector2 position;
			float velocity;
			Vector2 size;
		};

		Wall createWall(Vector2 position);
		void updateWall(Wall& wall);
		void drawWall(Wall wall);
		int createRandomYStartValue();
		Rectangle getRectangle(Wall wall);
	}
}
