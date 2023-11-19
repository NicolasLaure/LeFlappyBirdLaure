#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace Bird {
		struct Bird {
			Vector2 position{};
			Vector2 velocity{};
			Vector2 size{};
			bool isPlayerOne{false};
			KeyboardKey goUpbutton = KEY_SPACE;
			MouseButton goUpMouseButton = MOUSE_BUTTON_LEFT;
		};

		Bird createBird(Vector2 position, bool isPlayerOne);
		void updateBird(Bird& bird);
		void drawBird(Bird bird);
		Rectangle getRectangle(Bird bird);
		bool isCollidingBottom(Bird bird);
	}
}
