#include "math.h"

#include <math.h>

namespace LeFlappyBird 
{
	namespace MathUtils 
	{
		float clamp(float value, float min, float max)
		{
			return (value < min) ? min : value > max ? max : value;
		}

		float moduleOf(float value) {
			return value < 0 ? -value : value;
		}

		int roundUp(int numToRound, int multiple)
		{
			if (multiple == 0)
				return numToRound;

			int remainder = numToRound % multiple;
			if (remainder == 0)
				return numToRound;

			return numToRound + multiple - remainder;
		}

		bool checkRectangleCollision(Rectangle rectangle1, Rectangle rectangle2) {
			float rectangle1LeftEdge = rectangle1.x;
			float rectangle1RightEdge = rectangle1.x + rectangle1.width;

			float rectangle2LeftEdge = rectangle2.x;
			float rectangle2RightEdge = rectangle2.x + rectangle2.width;

			float rectangle1BottomEdge = rectangle1.y + rectangle1.height;
			float rectangle1TopEdge = rectangle1.y;

			float rectangle2BottomEdge = rectangle2.y + rectangle2.height;
			float rectangle2TopEdge = rectangle2.y;

			return rectangle1RightEdge >= rectangle2LeftEdge &&
				rectangle1LeftEdge <= rectangle2RightEdge &&
				rectangle1BottomEdge >= rectangle2TopEdge &&
				rectangle1TopEdge <= rectangle2BottomEdge;
		};

		bool checkCircleCollision(Circle circle1, Circle circle2) {
			double distX = static_cast<double>(circle1.position.x) - circle2.position.x;
			double distY = static_cast<double>(circle1.position.y) - circle2.position.y;

			float distance = static_cast<float>(sqrt(distX * distX + distY * distY));

			return distance <= circle1.radius + circle2.radius;
		}

		bool checkPointToRectangleCollision(Rectangle rectangle, Vector2 point) {
			float rectangleLeftEdge = rectangle.x;
			float rectangleRightEdge = rectangle.x + rectangle.width;
			float rectangleBottomEdge = rectangle.y + rectangle.height;
			float rectangleTopEdge = rectangle.y;

			return point.x >= rectangleLeftEdge &&
				point.x <= rectangleRightEdge &&
				point.y <= rectangleBottomEdge &&
				point.y >= rectangleTopEdge;
		}

		float getHalf(float size) {
			return size / 2.0f;
		}

		float getWithFrameTime(float value) {
			return value * GetFrameTime();
		}

		float getDistanceFromMiddle(Rectangle rectangle, Vector2 point) {
			float middle = rectangle.y + (rectangle.height / 2);

			return point.y - middle;
		}

		float getRandomNegativeOrPositive() {
			return GetRandomValue(0, 1) == 0 ? -1.0f : 1.0f;
		}
	}
}