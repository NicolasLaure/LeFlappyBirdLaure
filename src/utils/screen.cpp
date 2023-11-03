#include "screen.h"

namespace LeFlappyBird {
	namespace ScreenUtils {
		static float screenWidth = 0;
		static float screenHeight = 0;

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
			Vector2 nextFramePosition = { entity.position.x + entity.velocity.x * GetFrameTime(), entity.position.y + entity.velocity.y * GetFrameTime() };
			
			if (nextFramePosition.x + entity.size.x > getScreenWidth()) {
				entity.position.x = getScreenWidth() - entity.size.x;
			}
			else if (nextFramePosition.x < 0) {
				entity.position.x = 0;
			}
			else if (nextFramePosition.y + entity.size.y > getScreenHeight()) {
				entity.position.y = getScreenHeight() - entity.size.y;
			}
			else if (nextFramePosition.y < 0) {
				entity.position.y = 0;
			}
		}
	}
}
