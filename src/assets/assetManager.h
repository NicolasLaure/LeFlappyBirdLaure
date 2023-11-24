#pragma once
#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace AssetManager {
		enum Textures
		{
			PARALLAX_BACKGROUND,
			PARALLAX_BACKGROUND_TREES,
			PARALLAX_BACKGROUND_MOUNTAINS,
			CHEESECAKE,
			CHEESECAKE_FLYING,
			LEMONPIE,
			LEMONPIE_FLYING,
			UPPER_PIPE,
			LOWER_PIPE,
			CREDITS,
			RULES_CHANGE_PAGE,
			RULES_PAGE_ONE,
			RULES_PAGE_TWO,
			PAUSE_PANEL,
			GAME_OVER_PANEL,
			CONTINUE_BUTTON,
			MAIN_MENU_BUTTON,
			TEXTURES_COUNT
		};

		enum Sounds
		{
			JUMP,
			SOUNDS_COUNT
		};
		void init();
		void unload();
		Texture2D getTexture(Textures asset);
	}
}