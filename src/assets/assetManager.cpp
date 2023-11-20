#include "assetManager.h"

namespace LeFlappyBird
{
	namespace AssetManager
	{
		struct AssetWithTexture
		{
			Assets asset;
			Texture2D texture;
		};

		static AssetWithTexture textures[ASSETS_COUNT];

		void init()
		{
			AssetWithTexture background = { Assets::PARALLAX_BACKGROUND, LoadTexture("res/images/parallax-mountain-bg.png") };
			AssetWithTexture backgroundTrees = { Assets::PARALLAX_BACKGROUND_TREES, LoadTexture("res/images/parallax-mountain-trees.png") };
			AssetWithTexture backgroundMountains = { Assets::PARALLAX_BACKGROUND_MOUNTAINS, LoadTexture("res/images/parallax-mountain-mountains.png") };
			AssetWithTexture cheesecake = { Assets::CHEESECAKE, LoadTexture("res/images/cheesecake.png") };
			AssetWithTexture flyingCheesecake = { Assets::CHEESECAKE_FLYING, LoadTexture("res/images/cheesecake-flying.png") };
			AssetWithTexture lemonPie = { Assets::LEMONPIE, LoadTexture("res/images/lemonPie.png") };
			AssetWithTexture flyingLemonPie = { Assets::LEMONPIE_FLYING, LoadTexture("res/images/lemonPie-flying.png") };
			AssetWithTexture credits = { Assets::CREDITS, LoadTexture("res/images/credits.png") };
			AssetWithTexture rulesPageChange = { Assets::RULES_CHANGE_PAGE, LoadTexture("res/images/changePageButton.png") };
			AssetWithTexture rulesPageOne = { Assets::RULES_PAGE_ONE, LoadTexture("res/images/rulesPage1.png") };
			AssetWithTexture rulesPageTwo = { Assets::RULES_PAGE_TWO, LoadTexture("res/images/rulesPage2.png") };
			AssetWithTexture pausePanel = { Assets::PAUSE_PANEL, LoadTexture("res/images/pausePanel.png") };
			AssetWithTexture continueButton = { Assets::CONTINUE_BUTTON, LoadTexture("res/images/continueButton.png") };
			AssetWithTexture mainMenuButton = { Assets::MAIN_MENU_BUTTON, LoadTexture("res/images/mainMenuButton.png") };


			AssetWithTexture auxTextures[ASSETS_COUNT] = {
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
				continueButton,
				mainMenuButton
			};

			for (int i = 0; i < ASSETS_COUNT; i++)
			{
				textures[i] = auxTextures[i];
			}
		}

		Texture2D getTexture(Assets asset)
		{
			for (int i = 0; i < ASSETS_COUNT; i++)
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
