#include "fontManager.h"

namespace LeFlappyBird
{
	namespace FontManager
	{
		static Font font;

		void init()
		{
			font = LoadFont("res/VT323.ttf");
		};

		void unload()
		{
			UnloadFont(font);
		}
		Vector2 measureText(const char* text, float fontSize, float spacing)
		{
			return MeasureTextEx(font, text, fontSize, spacing);
		};

		void drawText(const char* text, Vector2 position, float fontSize, float spacing, Color color)
		{
			DrawTextEx(font, text, position, fontSize, spacing, color);
		};
	}
}
