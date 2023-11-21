#include "uiManager.h"

#include "raylib.h"
#include <string>

#include "assets/fontManager.h"

using namespace std;

namespace LeFlappyBird
{
	namespace UiManager
	{


		static const float TITLE_FONT_SIZE = 50.0f;
		static const float TITLE_SPACING = 3.0f;

		void init() {};
		void update() {};

		void draw(int score)
		{
			string scoreText = "Score:" + to_string(score);
			FontManager::drawText(scoreText.c_str(), { 10, 0 }, TITLE_FONT_SIZE, TITLE_SPACING, WHITE);
		};
	}
}
