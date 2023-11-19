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
			PAUSE_PANEL,
			CONTINUE_BUTTON,
			MAIN_MENU_BUTTON,
			ASSETS_COUNT
		};

		void init();
		Texture2D getTexture(Assets asset);
	}
}