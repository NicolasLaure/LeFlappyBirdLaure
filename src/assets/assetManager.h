#pragma once
#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace AssetManager {
		enum Assets
		{
			PARALLAX_BACKGROUND,
			PARALLAX_BACKGROUND_TREES,
			PARALLAX_BACKGROUND_MOUNTAINS,
			CHEESECAKE,
			CHEESECAKE_FLYING,
			LEMONPIE,
			LEMONPIE_FLYING,
			CREDITS,
			RULES_CHANGE_PAGE,
			RULES_PAGE_ONE,
			RULES_PAGE_TWO,
			PAUSE_PANEL,
			GAME_OVER_PANEL,
			CONTINUE_BUTTON,
			MAIN_MENU_BUTTON,
			ASSETS_COUNT
		};

		void init();
		Texture2D getTexture(Assets asset);
	}
}