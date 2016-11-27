#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include "Engine.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Engine engine;

    if (engine.initialize(hInstance, nCmdShow) == false)
        return 1;

    engine.run();

    engine.shutdown();

    return 0;
}