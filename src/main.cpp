#include <raylib.h>
#include <system.h>

int main(int argc, char **argv) {
	System system;

	InitWindow(800, 600, "Fluid Sim");
	SetTargetFPS(1000);
	float gap = 50.0f;
	for(int rows = 0 ; rows < 5; ++rows){
		for(int columns = 0 ; columns < 5; ++columns){
			system.AddParticle({50+(rows*gap), 50+(columns*gap)});
		}
	}
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		system.Update();
		system.handleUserInput();
		system.Render();
		EndDrawing();
	}
    return 0;
}
