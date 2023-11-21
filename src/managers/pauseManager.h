#pragma once


namespace LeFlappyBird
{
	namespace Pause
	{
		void init();
		void Update(bool& isPaused);
		void Draw(bool isGameOver, int score);
	}
}
