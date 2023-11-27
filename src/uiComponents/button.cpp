#include "button.h"

#include "raylib.h"

#include "utils/math.h"
#include "utils/screen.h"
#include "constants/dimensions.h"
#include "constants/colors.h"
#include "assets/fontManager.h"
#include "assets/assetManager.h"

namespace LeFlappyBird
{
	namespace Buttons
	{
		static const float BUTTON_TEXT_FONT_SIZE = 40.0f;
		static const float BUTTON_TEXT_SPACING = 3.0f;

		static Rectangle getInsideRectangle(Rectangle rectangle)
		{
			return {
				rectangle.x + Dimensions::BOX_BORDER_WIDTH,
				rectangle.y + Dimensions::BOX_BORDER_WIDTH,
				rectangle.width - Dimensions::BOX_BORDER_WIDTH * 2,
				rectangle.height - Dimensions::BOX_BORDER_WIDTH * 2,
			};
		}

		void drawButton(Button button)
		{
			if (button.isHovered)
			{
				DrawRectangleRec(button.outsideRectangle, button.outsideColor);

				DrawRectangleRec(button.insideRectangle, IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? button.focusColor : button.insideColor);
			}
			else
			{
				DrawRectangleRec(button.outsideRectangle, button.insideColor);
			}
		}

		void drawCenteredTextInButton(Button button, const char* text)
		{
			Vector2 textSize = FontManager::measureText(text, BUTTON_TEXT_FONT_SIZE, BUTTON_TEXT_SPACING);
			float optionTextPosX = button.outsideRectangle.x + MathUtils::getHalf(button.outsideRectangle.width) - MathUtils::getHalf(textSize.x);
			float optionTextPosY = button.outsideRectangle.y + MathUtils::getHalf(button.outsideRectangle.height) - MathUtils::getHalf(BUTTON_TEXT_FONT_SIZE);

			FontManager::drawText(
				text,
				{ optionTextPosX, optionTextPosY },
				BUTTON_TEXT_FONT_SIZE,
				BUTTON_TEXT_SPACING,
				WHITE
			);
		}

		void drawTextureInButton(Button button, Texture2D texture)
		{
			float textureScale = button.insideRectangle.width / texture.width;
			if (button.isHovered)
			{
				DrawTextureEx(texture, { button.outsideRectangle.x, button.outsideRectangle.y }, 0, textureScale, IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? button.focusColor : button.insideColor);
			}
			else
			{
				DrawTextureEx(texture, { button.outsideRectangle.x, button.outsideRectangle.y }, 0, textureScale, button.insideColor);
			}

		}

		void updateButton(Button& button)
		{
			Vector2 mousePosition = GetMousePosition();

			Vector2 fingerPosition = GetTouchPosition(0);
			bool isMouseCollisioningWithButton = MathUtils::checkPointToRectangleCollision(button.outsideRectangle, mousePosition);

			bool isFingerCollidingWithButton = MathUtils::checkPointToRectangleCollision(button.outsideRectangle, fingerPosition);

			bool isClicking = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsGestureDetected(GESTURE_HOLD);
			bool isJustReleased = IsMouseButtonReleased(MOUSE_BUTTON_LEFT) || isClicking == true && !GetGestureDetected();
			

			if (isMouseCollisioningWithButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !isClicking) return;

			if (isMouseCollisioningWithButton || isFingerCollidingWithButton)
			{

				if (isClicking && !IsSoundPlaying(AssetManager::getSound(AssetManager::Sounds::BUTTON_PRESSED)))
					PlaySound(AssetManager::getSound(AssetManager::Sounds::BUTTON_PRESSED));

				if (isJustReleased && button.isHovered)
				{
					button.isClicked = true;
					if (!IsSoundPlaying(AssetManager::getSound(AssetManager::Sounds::BUTTON_RELEASED)))
						PlaySound(AssetManager::getSound(AssetManager::Sounds::BUTTON_RELEASED));
				}
				else if (!isJustReleased)
					button.isClicked = false;

				button.isHovered = true;
			}
			else
			{
				button.isClicked = false;
				button.isHovered = false;
			}
		}

		Button createButton(Rectangle rectangle)
		{
			return {
				getInsideRectangle(rectangle),
				rectangle,
				RED,
				Colors::FOCUS_COLOR,
				PINK
			};
		}

		Button createButtonWithColors(Rectangle rectangle, Color insideColor, Color outsideColor, Color focusColor)
		{
			return {
				getInsideRectangle(rectangle),
				rectangle,
				insideColor,
				outsideColor,
				focusColor
			};
		}
	}
}