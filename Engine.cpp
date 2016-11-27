#include "Engine.hpp"
#include "WindowManager.hpp"
#include "RendererManager.hpp"

Engine::Engine()
{
}

bool Engine::initialize(HINSTANCE hInstance, int nCmdShow)
{
    // Initialize the window
    if (!Manager::WindowManager::getInstance().initialize(hInstance, nCmdShow))
        return false;

    // Initialize the DirectX 11 context
    HWND window = Manager::WindowManager::getInstance().getMainWindow();

    if (!Manager::RendererManager::getInstance().initialize())
    {
        MessageBox(window, L"Could not initialize Direct3D", L"Error", MB_OK);
        return false;
    }

    // Initialize the scene
    if (!m_scene.initialize())
    {
        MessageBox(window, L"Could not initialize the scene", L"Error", MB_OK);
        return false;
    }

    return true;
}

bool Engine::run()
{
    bool done = false;
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));

    while (!done)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // If windows signals to end the application then exit out.
        if (msg.message == WM_QUIT)
        {
            done = true;
        }
        else
        {
            // Update object in the scene
            m_scene.update();
            // Draw objects in the scene
            m_scene.draw();
        }
    }
    return done;
}

bool Engine::shutdown()
{
    Manager::WindowManager::getInstance().shutdown();
    return true;
}


Engine::~Engine()
{
}
