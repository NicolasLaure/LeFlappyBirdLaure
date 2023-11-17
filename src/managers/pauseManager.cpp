#include "managers/pauseManager.h"

#include "raylib.h"
namespace LeFlappyBird
{
	namespace Pause
	{
		void Update(bool& isPaused)
		{
			if (IsKeyPressed(KEY_ESCAPE) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
				isPaused = false;
		}
		void Draw()
		{
		}
	}
}