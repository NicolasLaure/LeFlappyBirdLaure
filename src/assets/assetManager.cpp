#include "assetManager.h"

namespace LeFlappyBird {
	namespace AssetManager {
		struct AssetWithTexture {
			Assets asset;
			Texture2D texture;
		};

		static AssetWithTexture textures[ASSETS_COUNT];

		void init() {
			AssetWithTexture background = { Assets::PARALLAX_BACKGROUND, LoadTexture("res/images/parallax-mountain-bg.png") };
			AssetWithTexture backgroundTrees = { Assets::PARALLAX_BACKGROUND_TREES, LoadTexture("res/images/parallax-mountain-trees.png") };
			AssetWithTexture backgroundMountains = { Assets::PARALLAX_BACKGROUND_MOUNTAINS, LoadTexture("res/images/parallax-mountain-mountains.png") };

			AssetWithTexture auxTextures[ASSETS_COUNT] = {
				background,
				backgroundTrees,
				backgroundMountains
			};

			for (int i = 0; i < ASSETS_COUNT; i++) {
				textures[i] = auxTextures[i];
			}
		}

		Texture2D getTexture(Assets asset) {
			for (int i = 0; i < ASSETS_COUNT; i++) {
				if (asset == textures[i].asset) {
					return textures[i].texture;
				}
			}
			return {};
		}
	}
}