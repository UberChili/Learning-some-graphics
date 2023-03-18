#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"


int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    int n_squares;

    Rectangle boxA = {
    20,
    screenHeight - ((float)screenHeight / 2),
    40,
    40 };

    std::cout << "Input number of squares: ";
    std::cin >> n_squares;
    std::cout << "Squares: " << n_squares << "\n";


    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - Drawing multiple squares");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    int x_incr = boxA.width + 20;
    int y_incr = boxA.height + 20;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // TODO: Update your variables here

        if (IsKeyPressed(KEY_SPACE)) {
            if (boxA.x + x_incr <= screenWidth - 20) {
                boxA.x += x_incr;
            }
            else {
                boxA.x = 20;
            }
        }

        // Draw
        BeginDrawing();

            // ClearBackground(RAYWHITE);

            // DrawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, BLACK);
            // DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, RAYWHITE);
            // DrawText(text.c_str(), screenWidth/2 - 25, screenHeight/2 - 25, 50, BLACK);
            DrawRectangleRec(boxA, GOLD);

            DrawText("Press SPACEBAR to continue.", 350, 370, 10, GRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
