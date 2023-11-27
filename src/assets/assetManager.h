#pragma once
#pragma once
#include "raylib.h"

namespace LeFlappyBird
{
	namespace AssetManager
	{
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
			RULES_PAGE_THREE,
			PAUSE_PANEL,
			GAME_OVER_PANEL,
			CONTINUE_BUTTON,
			MAIN_MENU_BUTTON,
			TEXTURES_COUNT
		};

		enum Sounds
		{
			PLAYER_ONE_JUMP,
			PLAYER_TWO_JUMP,
			WALL_HIT,
			GROUND_HIT,
			BUTTON_PRESSED,
			BUTTON_RELEASED,
			SOUNDS_COUNT
		};

		enum Musics
		{
			MENU_MUSIC,
			GAMEPLAY_MUSIC,
			MUSICS_COUNT
		};

		void init();
		void unload();
		Texture2D getTexture(Textures asset);
		Sound getSound(Sounds asset);
		Music getMusic(Musics asset);
	}
}