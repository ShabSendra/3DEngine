#include <tchar.h>

#include "WindowManager.hpp"

using Manager::WindowManager;

WindowManager WindowManager::m_instance;

WindowManager::WindowManager(unsigned int width, unsigned int height) : m_appInstance(), m_mainWindow(), m_appName(), m_width(width), m_height(height)
{
}

bool WindowManager::initialize(HINSTANCE hInstance, int nCmdShow)
{
    m_width = 800;
    m_height = 600;
    // The main window class name.
    static TCHAR szWindowClass[] = _T("3DEngine");

    // The string that appears in the application's title bar.
    static TCHAR szTitle[] = _T("3D Engine");

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return false;
    }


    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    m_mainWindow = CreateWindowEx(
        NULL,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        m_width, m_height,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!m_mainWindow)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return false;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(m_mainWindow,
        nCmdShow);
    UpdateWindow(m_mainWindow);
}

bool WindowManager::shutdown()
{
    DestroyWindow(m_mainWindow);
    m_mainWindow = NULL;

    // Remove the application instance.
    UnregisterClass(m_appName, m_appInstance);
    m_appInstance = NULL;
    return true;
}

HWND WindowManager::getMainWindow() const
{
    return m_mainWindow;
}

HINSTANCE WindowManager::getAppInstance() const
{
    return m_appInstance;
}

unsigned int WindowManager::getWidth() const
{
    return m_width;
}

unsigned int WindowManager::getHeight() const
{
    return m_height;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            if (MessageBox(0, L"Are you sure you want to exit?",
                L"Really?", MB_YESNO | MB_ICONQUESTION) == IDYES)
                DestroyWindow(hWnd);
        }
    case WM_DESTROY:
        PostQuitMessage(0);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

WindowManager::~WindowManager()
{
}