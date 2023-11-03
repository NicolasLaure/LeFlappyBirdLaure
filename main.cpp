#include "raylib.h"

int main() {
	InitWindow(500, 500, "ASD");

	while (!WindowShouldClose()) {
		BeginDrawing();

		EndDrawing();
	};

	CloseWindow();

	return 0;
}
