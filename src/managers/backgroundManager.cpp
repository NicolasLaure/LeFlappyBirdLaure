#include "backgroundManager.h"

#include "raylib.h"

#include "assets/assetManager.h"
#include "utils/screen.h"

namespace LeFlappyBird {
	namespace BackgroundManager {
		struct BackgroundAsset {
			Texture2D backgroundTexture;
			float parallaxVelocity;
			float scroll;
			float yPosition;
		};

		struct Background {
			BackgroundAsset background;
			BackgroundAsset midground;
			BackgroundAsset foreground;
		};

		static Background background;

		static void updateBackgroundAsset(BackgroundAsset &backgroundAsset) {
			backgroundAsset.scroll += backgroundAsset.parallaxVelocity * GetFrameTime();

			if (backgroundAsset.scroll >= backgroundAsset.backgroundTexture.width * 8.0f) {
				backgroundAsset.scroll = 0.0f;
			}
		}

		static void drawBackgroundAsset(BackgroundAsset backgroundAsset) {
			Rectangle source = {
				backgroundAsset.scroll,
				backgroundAsset.yPosition,
				static_cast<float>(backgroundAsset.backgroundTexture.width * 2),
				static_cast<float>(backgroundAsset.backgroundTexture.height)
			};

			Rectangle dest = {
				0,
				0,
				ScreenUtils::getScreenWidth() * 2,
				ScreenUtils::getScreenHeight() + 100.0f
			};

			Vector2 origin = { backgroundAsset.backgroundTexture.width / 2.0f, backgroundAsset.backgroundTexture.height / 2.0f };

			DrawTexturePro(
				backgroundAsset.backgroundTexture,
				source,
				dest,
				origin,
				0.0f,
				WHITE
			);
		}

		void initBackground() {
			background = {
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND),
					0.0f,
					0.0f,
					0.0f
				},
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND_MOUNTAINS),
					10.0f,
					0.0f,
					0.0f
				},
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND_TREES),
					20.0f,
					0.0f,
					0.0f
				},
			};
		};

		void updateBackground() {
			updateBackgroundAsset(background.background);
			updateBackgroundAsset(background.foreground);
			updateBackgroundAsset(background.midground);
		};

		void drawBackground() {
			drawBackgroundAsset(background.background);
			drawBackgroundAsset(background.midground);
			drawBackgroundAsset(background.foreground);
		};
	}
}
