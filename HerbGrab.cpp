#include <Windows.h>
#include <random>

int GetRandom(int min, int max);

int main()
{
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
    while (1) // Main loop
    {
        Sleep(1);
        while (GetAsyncKeyState(0x70) != 0) // Loop while F1 is Pressed
        {
            SendInput(1, down, sizeof(down)); // Right Click Down
            Sleep(GetRandom(35, 95)); // Randomized keydown delay
            SendInput(1, up, sizeof(up)); // Right Click Up
        }
    }
}

int GetRandom(int min, int max) // Returns a random integer within the range supplied
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}