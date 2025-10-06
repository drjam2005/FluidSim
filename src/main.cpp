#include <raylib.h>
#include <system.h>

int main(int argc, char **argv) {
	System system;

	InitWindow(800, 600, "Fluid Sim");
	float gap = 50.0f;
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		system.Update();
		system.handleUserInput();
		system.Render();
		DrawFPS(20,20);
		EndDrawing();
	}
    return 0;
}
