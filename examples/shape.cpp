#include <iostream>
#include <string>

#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int n = 0;
    std::string text;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - raylib logo using shapes");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // TODO: Update your variables here

        if (IsKeyPressed(KEY_SPACE)) {
            text = std::to_string(n++);
        }

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, BLACK);
            DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, RAYWHITE);
            // DrawText(text.c_str(), screenWidth/2 - 44, screenHeight/2 + 48, 50, BLACK);
            DrawText(text.c_str(), screenWidth/2 - 25, screenHeight/2 - 25, 50, BLACK);

            DrawText("Press RETURN to continue.", 350, 370, 10, GRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
