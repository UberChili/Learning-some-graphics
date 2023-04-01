#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "raylib.h"


int main(void)
{
    // Initialization
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    int n_squares;
    std::cout << "Input number of squares: ";
    std::cin >> n_squares;
    std::cout << "Squares: " << n_squares << "\n";

    float size_squares = floor(screenWidth / (n_squares + 1));
    float x_padding = (screenWidth - (size_squares * n_squares)) / (n_squares + 1);
    float y_padding = (screenHeight - (size_squares * n_squares)) / (n_squares + 1);

    Rectangle boxA = {
        x_padding,
        y_padding,
        size_squares,
        size_squares };

    float x_incr = boxA.width + x_padding;
    int y_incr = boxA.height + y_padding;

    // Main game loop
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - Drawing multiple squares");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // TODO: Update your variables here

        if (boxA.x + x_incr <= screenWidth - x_padding) {
            boxA.x += x_incr;
        }
        else {
            boxA.x = x_padding;

            if (boxA.y + y_padding + y_incr >= screenHeight - y_padding) {
                boxA.y = y_padding;
            }
            else {
                boxA.y += y_incr;
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // DrawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, BLACK);
            // DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, RAYWHITE);
            // DrawText(text.c_str(), screenWidth/2 - 25, screenHeight/2 - 25, 50, BLACK);
            DrawRectangleRec(boxA, GOLD);

            DrawText("Press SPACEBAR to continue.", 300, screenHeight - 20, 15, GRAY);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    return 0;
}
