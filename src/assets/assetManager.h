#pragma once
#pragma once
#include "raylib.h"

namespace LeFlappyBird {
	namespace AssetManager {
		enum Assets {
			PARALLAX_BACKGROUND,
			PARALLAX_BACKGROUND_TREES,
			PARALLAX_BACKGROUND_MOUNTAINS,
			ASSETS_COUNT
		};

		void init();
		Texture2D getTexture(Assets asset);
	}
}