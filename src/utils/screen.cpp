#include "screen.h"

namespace LeFlappyBird {
	namespace ScreenUtils {
		static float screenWidth = 0;
		static float screenHeight = 0;

		static void checkPositionBounds(Entity& entity, Vector2 xBoundsValues, Vector2 yBoundsValues) {
			Vector2 nextFramePosition = { entity.position.x + entity.velocity.x * GetFrameTime(), entity.position.y + entity.velocity.y * GetFrameTime() };

			if (nextFramePosition.x > xBoundsValues.y) {
				entity.position.x = xBoundsValues.y;
			}
			else if (nextFramePosition.x < xBoundsValues.x) {
				entity.position.x = xBoundsValues.x;
			}
			else if (nextFramePosition.y > yBoundsValues.y) {
				entity.position.y = yBoundsValues.y;
			}
			else if (nextFramePosition.y < yBoundsValues.x) {
				entity.position.y = yBoundsValues.x;
			}
		}

		float getScreenWidth() {
			if (screenWidth == 0) {
				screenWidth = static_cast<float>(GetScreenWidth());
			}
			return screenWidth;
		}

		float getScreenHeight() {
			if (screenHeight == 0) {
				screenHeight = static_cast<float>(GetScreenHeight());
			}
			return screenHeight;
		}

		float getScaleRelativeByScreen(float value) {
			return value * screenWidth;
		}

		void checkPositionByScreenBounds(Entity& entity) {
			checkPositionBounds(entity, {
					0,
					getScreenWidth() - entity.size.x
				},
				{
					0,
					getScreenHeight() - entity.size.y
				});
		}

		void checkPositionByScreenBounds(Entity& entity, Vector2 xBoundsValues, Vector2 yBoundsValues) {
			checkPositionBounds(entity, xBoundsValues, yBoundsValues);
		}

		bool isCollidingInScreenPart(Entity entity, ScreenPart screenPart) {
			switch (screenPart) {
				case TOP:
					return entity.position.y <= 0;
				case BOTTOM:
					return entity.position.y + entity.size.y >= getScreenHeight();
				default:
					return false;
			}
		}
	}
}
