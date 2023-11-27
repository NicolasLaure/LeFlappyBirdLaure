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

		struct AssetWithMusic
		{
			Musics asset;
			Music music;
		};

		static AssetWithTexture textures[TEXTURES_COUNT];
		static AssetWithSound sounds[SOUNDS_COUNT];
		static AssetWithMusic musics[MUSICS_COUNT];

		void init()
		{
			AssetWithTexture background = { Textures::PARALLAX_BACKGROUND, LoadTexture("res/images/parallax-mountain-bg.png") };
			AssetWithTexture backgroundTrees = { Textures::PARALLAX_BACKGROUND_TREES, LoadTexture("res/images/parallax-mountain-trees.png") };
			AssetWithTexture backgroundMountains = { Textures::PARALLAX_BACKGROUND_MOUNTAINS, LoadTexture("res/images/parallax-mountain-mountains.png") };
			AssetWithTexture cheesecake = { Textures::CHEESECAKE, LoadTexture("res/images/cheesecake.png") };
			AssetWithTexture flyingCheesecake = { Textures::CHEESECAKE_FLYING, LoadTexture("res/images/cheesecake-flying.png") };
			AssetWithTexture lemonPie = { Textures::LEMONPIE, LoadTexture("res/images/lemonPie.png") };
			AssetWithTexture flyingLemonPie = { Textures::LEMONPIE_FLYING, LoadTexture("res/images/lemonPie-flying.png") };
			AssetWithTexture upperPipe = { Textures::UPPER_PIPE, LoadTexture("res/images/upperPipe.png") };
			AssetWithTexture lowerPipe = { Textures::LOWER_PIPE, LoadTexture("res/images/lowerPipe.png") };
			AssetWithTexture credits = { Textures::CREDITS, LoadTexture("res/images/credits.png") };
			AssetWithTexture rulesPageChange = { Textures::RULES_CHANGE_PAGE, LoadTexture("res/images/changePageButton.png") };
			AssetWithTexture rulesPageOne = { Textures::RULES_PAGE_ONE, LoadTexture("res/images/rulesPage1.png") };
#if defined(PLATFORM_WEB)
			AssetWithTexture rulesPageTwo = { Textures::RULES_PAGE_TWO, LoadTexture("res/images/rulesPage2Web.png") };
#else
			AssetWithTexture rulesPageTwo = { Textures::RULES_PAGE_TWO, LoadTexture("res/images/rulesPage2.png") };
#endif
			AssetWithTexture rulesPageThree = { Textures::RULES_PAGE_THREE, LoadTexture("res/images/rulesPage3Web.png") };
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
				upperPipe,
				lowerPipe,
				credits,
				rulesPageChange,
				rulesPageOne,
				rulesPageTwo,
				rulesPageThree,
				pausePanel,
				gameOverPanel,
				continueButton,
				mainMenuButton
			};

			for (int i = 0; i < TEXTURES_COUNT; i++)
			{
				textures[i] = auxTextures[i];
			}

			AssetWithSound playerOneJump = { Sounds::PLAYER_ONE_JUMP, LoadSound("res/audio/sfx/drop_001.ogg") };
			AssetWithSound playerTwoJump = { Sounds::PLAYER_TWO_JUMP, LoadSound("res/audio/sfx/footstep_concrete_002.ogg") };
			AssetWithSound wallHit = { Sounds::WALL_HIT, LoadSound("res/audio/sfx/impactBell_heavy_004.ogg") };
			AssetWithSound groundHit = { Sounds::GROUND_HIT, LoadSound("res/audio/sfx/footstep_grass_003.ogg") };
			AssetWithSound buttonClickPressed = { Sounds::BUTTON_PRESSED, LoadSound("res/audio/ui/click_001.ogg") };
			AssetWithSound buttonClickReleased = { Sounds::BUTTON_RELEASED, LoadSound("res/audio/ui/click_003.ogg") };

			AssetWithSound auxSounds[SOUNDS_COUNT] = {
				playerOneJump,
				playerTwoJump,
				wallHit,
				groundHit,
				buttonClickPressed,
				buttonClickReleased
			};

			for (int i = 0; i < SOUNDS_COUNT; i++)
			{
				sounds[i] = auxSounds[i];
				SetSoundVolume(sounds[i].sound, 0.3f);
			}

			AssetWithMusic menuMusic = { Musics::MENU_MUSIC, LoadMusicStream("res/audio/music/LeFlappyBirdMenu.wav") };
			AssetWithMusic gameplayMusic = { Musics::GAMEPLAY_MUSIC, LoadMusicStream("res/audio/music/LeFlappyBirdGamePlay.wav") };

			AssetWithMusic auxMusics[MUSICS_COUNT] = {
				menuMusic,
				gameplayMusic
			};

			for (int i = 0; i < MUSICS_COUNT; i++)
			{
				musics[i] = auxMusics[i];
				SetMusicVolume(musics[i].music, 0.2f);
			}
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

			for (int i = 0; i < MUSICS_COUNT; i++)
			{
				UnloadMusicStream(musics[i].music);
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

		Sound getSound(Sounds asset)
		{
			for (int i = 0; i < SOUNDS_COUNT; i++)
			{
				if (asset == sounds[i].asset)
				{
					return sounds[i].sound;
				}
			}
			return {};
		}

		Music getMusic(Musics asset)
		{
			for (int i = 0; i < MUSICS_COUNT; i++)
			{
				if (asset == musics[i].asset)
				{
					return musics[i].music;
				}
			}
			return {};
		}

	}
}
