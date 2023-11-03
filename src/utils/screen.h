#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace ScreenUtils {
		struct Entity {
			Vector2 position;
			Vector2 velocity;
			Vector2 size;
		};

		float getScreenWidth();
		float getScreenHeight();
		float getScaleRelativeByScreen(float value);
		void checkPositionByScreenBounds(Entity& entity);
	}
}
