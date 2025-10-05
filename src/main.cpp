#include <raylib.h>

int main(int argc, char **argv) {
	InitWindow(800, 600, "Fluid Sim");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}
    return 0;
}
