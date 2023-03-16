#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"


int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    std::vector<Rectangle> rectangles;

    for (int i = 0, x = 20; i < 10 && x < screenWidth; i++, x += 70)
    {
        Rectangle aux_rect = {(float)x, screenHeight/2.0, 60, 60};
    }


    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - Drawing multiple squares");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // TODO: Update your variables here

        // if (IsKeyPressed(KEY_SPACE)) {

        // }

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // DrawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, BLACK);
            // DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, RAYWHITE);
            // DrawText(text.c_str(), screenWidth/2 - 25, screenHeight/2 - 25, 50, BLACK);

            DrawText("Press RETURN to continue.", 350, 370, 10, GRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
