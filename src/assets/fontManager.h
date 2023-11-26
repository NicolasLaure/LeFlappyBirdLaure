#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace FontManager {
		void init();
		void unload();

		Vector2 measureText(const char* text, float fontSize, float spacing);
		void drawText(const char* text, Vector2 position, float fontSize, float spacing, Color color);
	}
}
