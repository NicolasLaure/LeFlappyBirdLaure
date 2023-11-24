#include "assetManager.h"

namespace LeFlappyBird
{
	namespace AssetManager
	{
		struct AssetWithTexture
		{
			Textures asset;
			Texture2D texture;
		};

		struct AssetWithSound
		{
			Sounds asset;
			Sound sound;
		};
		static AssetWithTexture textures[TEXTURES_COUNT];
		static AssetWithSound sounds[SOUNDS_COUNT];

		void init()
		{
			AssetWithTexture background = { Textures::PARALLAX_BACKGROUND, LoadTexture("res/images/parallax-mountain-bg.png") };
			AssetWithTexture backgroundTrees = { Textures::PARALLAX_BACKGROUND_TREES, LoadTexture("res/images/parallax-mountain-trees.png") };
			AssetWithTexture backgroundMountains = { Textures::PARALLAX_BACKGROUND_MOUNTAINS, LoadTexture("res/images/parallax-mountain-mountains.png") };
			AssetWithTexture cheesecake = { Textures::CHEESECAKE, LoadTexture("res/images/cheesecake.png") };
			AssetWithTexture flyingCheesecake = { Textures::CHEESECAKE_FLYING, LoadTexture("res/images/cheesecake-flying.png") };
			AssetWithTexture lemonPie = { Textures::LEMONPIE, LoadTexture("res/images/lemonPie.png") };
			AssetWithTexture flyingLemonPie = { Textures::LEMONPIE_FLYING, LoadTexture("res/images/lemonPie-flying.png") };
			AssetWithTexture credits = { Textures::CREDITS, LoadTexture("res/images/credits.png") };
			AssetWithTexture rulesPageChange = { Textures::RULES_CHANGE_PAGE, LoadTexture("res/images/changePageButton.png") };
			AssetWithTexture rulesPageOne = { Textures::RULES_PAGE_ONE, LoadTexture("res/images/rulesPage1.png") };
			AssetWithTexture rulesPageTwo = { Textures::RULES_PAGE_TWO, LoadTexture("res/images/rulesPage2.png") };
			AssetWithTexture pausePanel = { Textures::PAUSE_PANEL, LoadTexture("res/images/pausePanel.png") };
			AssetWithTexture gameOverPanel = { Textures::GAME_OVER_PANEL, LoadTexture("res/images/gameOverPanel.png") };
			AssetWithTexture continueButton = { Textures::CONTINUE_BUTTON, LoadTexture("res/images/continueButton.png") };
			AssetWithTexture mainMenuButton = { Textures::MAIN_MENU_BUTTON, LoadTexture("res/images/mainMenuButton.png") };

			AssetWithTexture auxTextures[TEXTURES_COUNT] = {
				background,
				backgroundTrees,
				backgroundMountains,
				cheesecake,
				flyingCheesecake,
				lemonPie,
				flyingLemonPie,
				credits,
				rulesPageChange,
				rulesPageOne,
				rulesPageTwo,
				pausePanel,
				gameOverPanel,
				continueButton,
				mainMenuButton
			};

			for (int i = 0; i < TEXTURES_COUNT; i++)
			{
				textures[i] = auxTextures[i];
			}

			AssetWithSound jump = { Sounds::JUMP, LoadSound("res/images/parallax-mountain-trees.png") };
		}

		void unload()
		{
			for (int i = 0; i < TEXTURES_COUNT; i++)
			{
				UnloadTexture(textures[i].texture);
			}
			for (int i = 0; i < SOUNDS_COUNT; i++)
			{
				UnloadSound(sounds[i].sound);
			}
		}

		Texture2D getTexture(Textures asset)
		{
			for (int i = 0; i < TEXTURES_COUNT; i++)
			{
				if (asset == textures[i].asset)
				{
					return textures[i].texture;
				}
			}
			return {};
		}
	}
}
