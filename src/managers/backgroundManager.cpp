#include "backgroundManager.h"

#include "raylib.h"

#include "assets/assetManager.h"
#include "utils/screen.h"

namespace LeFlappyBird
{
	namespace BackgroundManager
	{
		struct BackgroundAsset
		{
			Texture2D backgroundTexture;
			float parallaxVelocity;
			float scroll;
			float scale;
		};

		struct Background
		{
			BackgroundAsset background;
			BackgroundAsset midground;
			BackgroundAsset foreground;
		};

		static Background background;

		static void updateBackgroundAsset(BackgroundAsset& backgroundAsset, float speedMultiplier)
		{
			backgroundAsset.scroll += backgroundAsset.parallaxVelocity * speedMultiplier * GetFrameTime();

			if (backgroundAsset.scroll >= backgroundAsset.backgroundTexture.width * 2.0f)
			{
				backgroundAsset.scroll = 0.0f;
			}
		}

		static void drawBackgroundAsset(BackgroundAsset backgroundAsset)
		{
			Rectangle source = {
				backgroundAsset.scroll,
				0.0f,
				static_cast<float>(backgroundAsset.backgroundTexture.width * backgroundAsset.scale),
				static_cast<float>(backgroundAsset.backgroundTexture.height)
			};

			Rectangle dest = {
				0,
				0,
				ScreenUtils::getScreenWidth() * backgroundAsset.scale,
				ScreenUtils::getScreenHeight()
			};

			Vector2 origin = { 0.0f, 0.0f };

			DrawTexturePro(
				backgroundAsset.backgroundTexture,
				source,
				dest,
				origin,
				0.0f,
				WHITE
			);
		}

		void initBackground()
		{
			const float MOUNTAINS_SCROLL_VELOCITY = 10.0f;
			const float TREES_SCROLL_VELOCITY = 20.0f;
			const float SCROLLED_TEXTURES_SCALE = 2.0f;

			background = {
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND),
					0.0f,
					0.0f,
					1.0f,
				},
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND_MOUNTAINS),
					MOUNTAINS_SCROLL_VELOCITY,
					0.0f,
					SCROLLED_TEXTURES_SCALE
				},
				{
					AssetManager::getTexture(AssetManager::PARALLAX_BACKGROUND_TREES),
					TREES_SCROLL_VELOCITY,
					0.0f,
					SCROLLED_TEXTURES_SCALE
				},
			};
		};

		void updateBackground(float speedMultiplier)
		{
			updateBackgroundAsset(background.background, speedMultiplier);
			updateBackgroundAsset(background.foreground, speedMultiplier);
			updateBackgroundAsset(background.midground, speedMultiplier);
		};

		void drawBackground()
		{
			drawBackgroundAsset(background.background);
			drawBackgroundAsset(background.midground);
			drawBackgroundAsset(background.foreground);
		};
	}
}
