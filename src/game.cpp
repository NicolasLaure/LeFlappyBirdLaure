#include "game.h"

#include "raylib.h"

#include "managers/screenManager.h"
#include "constants/dimensions.h"

namespace LeFlappyBird {
    namespace Game {
        static void close() {
            CloseAudioDevice();

            CloseWindow();
        }

        static void init() {
            InitWindow(static_cast<int>(Dimensions::SCREEN_DIMENSIONS.x), static_cast<int>(Dimensions::SCREEN_DIMENSIONS.y), "Ashhteroids");

            InitAudioDevice();
        }

        static void update(bool& shouldClose) {
            ScreensManager::updateScreen(shouldClose);
        }

        static void draw() {
            BeginDrawing();
                GetFontDefault();
                ClearBackground(BLACK);

                ScreensManager::drawScreen();

            EndDrawing();
        }

        void startGame() {
            init();
            bool shouldClose = false;

            SetExitKey(0);

            while (!shouldClose)
            {
                update(shouldClose);

                draw();
            }

            close();
        }
    }

}
