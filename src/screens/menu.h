#pragma once
#include <string>

#include "raylib.h"

#include "uiComponents/button.h"

namespace LeFlappyBird {
	namespace Menu {
		enum Option {
			SINGLEPLAYER,
			MULTIPLAYER,
			READ_RULES,
			READ_CREDITS,
			EXIT,
			OPTIONS_QUANTITY
		};

		struct MenuOption {
			Option option;
			std::string text;
			Buttons::Button optionButton;
		};

		void initMenu();
		void update(bool& shouldClose);
		void drawMenu();
		void checkMenuInputAndCollision(bool& shouldClose);
	}
}
