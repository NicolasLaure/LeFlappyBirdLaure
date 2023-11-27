#include "game.h"

#include "raylib.h"

#include "managers/screenManager.h"
#include "assets/assetManager.h"
#include "assets/fontManager.h"
#include "constants/dimensions.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace LeFlappyBird
{
	namespace Game
	{
		void UpdateDrawFrame();

		static void close()
		{
			AssetManager::unload();
			FontManager::unload();
			CloseAudioDevice();
			CloseWindow();
		}

		static void init()
		{
			InitWindow(static_cast<int>(Dimensions::SCREEN_DIMENSIONS.x), static_cast<int>(Dimensions::SCREEN_DIMENSIONS.y), "LeFlappyBird");
			InitAudioDevice();

			AssetManager::init();
			ScreensManager::initManager();
			FontManager::init();
		}

		static void update(bool& shouldClose)
		{
			ScreensManager::updateScreen(shouldClose);
		}

		static void draw()
		{
			BeginDrawing();
			GetFontDefault();
			ClearBackground(BLACK);

			ScreensManager::drawScreen();

			EndDrawing();
		}

		void startGame()
		{
			init();
			bool shouldClose = false;

			SetExitKey(0);
#if defined(PLATFORM_WEB)
			emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
			while (!shouldClose)
			{
				update(shouldClose);
				draw();
			}
#endif

			close();
		}

		void UpdateDrawFrame()
		{
			bool shouldClose = false;
			update(shouldClose);
			draw();
		}
	}

}