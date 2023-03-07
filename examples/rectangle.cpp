// C++ libraries
#include <iostream>
#include <vector>
#include <utility>

#include <raylib.h>


int main(void) {
    std::cout << "Example drawing a rectangle\n";

    const int screenwidth = 800;
    const int screenheight = 600;
    std::vector<std::pair<int, int>> ranges;
    std::pair<int, int> a_pair = std::make_pair(250, 250);

    std::cout << "Pair0: " << a_pair.first << " Pair1: " << a_pair.second << "\n";

    InitWindow(screenwidth, screenheight, "Example");

    int lineThick = 1;

    Rectangle boxA = {
    a_pair.first/2.0f,
    a_pair.second/2.0f,
    50,
    50 };


    int boxASpeedX = 8;
    int boxASpeedY = 8;

    bool pause = false;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (!pause)
        {
            boxA.x += boxASpeedX;
            boxA.y += boxASpeedY;
        }

        if ((boxA.x + boxA.width) >= GetScreenWidth() || boxA.x <= 0) {
            boxASpeedX *= -1;
        }
        else if ((boxA.y + boxA.height) >= GetScreenHeight() || boxA.y <= 0)
        {
            boxASpeedY *= -1;
        }

        if (IsKeyDown(KEY_SPACE))
        {
            boxA.y -= boxASpeedY;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawPixel(50, 50, GOLD);
            DrawRectangleRec(boxA, GOLD);
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
