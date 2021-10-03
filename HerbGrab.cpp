#include <Windows.h>
#include <random>
#include <iostream>

int main()
{
    // Setup random number generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(20, 50); // define the range
    // Define structs
    INPUT down[1] = {};
    down[0].type = INPUT_MOUSE;
    down[0].mi.dx = 0;
    down[0].mi.dy = 0;
    down[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    INPUT up[1] = {};
    up[0].type = INPUT_MOUSE;
    up[0].mi.dx = 0;
    up[0].mi.dy = 0;
    up[0].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    std::cout << "Ready! Press & Hold F1 to activate..." << std::endl;
    while (1) // Main loop
    {
        Sleep(1);
        while (GetAsyncKeyState(VK_F1) != 0) // Loop while F1 is Pressed
        {
            SendInput(1, down, sizeof(down)); // Right Click Down
            Sleep(distr(gen)); // Randomized keydown delay
            SendInput(1, up, sizeof(up)); // Right Click Up
            Sleep(distr(gen)); // Randomized keyup delay
        }
    }
}