#pragma once
#include "raylib.h"

namespace LeFlappyBird
{
	namespace ScreenUtils
	{
		struct Entity
		{
			Vector2 position;
			Vector2 velocity;
			Vector2 size;
		};

		enum ScreenPart
		{
			TOP = 0,
			BOTTOM
		};

		float getScreenWidth();
		float getScreenHeight();
		float getScaleRelativeByScreen(float value);
		void checkPositionByScreenBounds(Entity& entity);
		void checkPositionByScreenBounds(Entity& entity, Vector2 xBoundsValues, Vector2 yBoundsValues);
		bool isCollidingInScreenPart(Entity entity, ScreenPart screenPart);
	}
}
