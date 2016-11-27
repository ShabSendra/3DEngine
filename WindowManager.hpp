#ifndef _WINDOWMANAGER_HPP_
#define _WINDOWMANAGER_HPP_

#include <windows.h>

namespace Manager
{

    class WindowManager
    {
    public:

        WindowManager(const WindowManager &other) = delete;
        WindowManager &operator=(const WindowManager &other) = delete;

        static WindowManager &getInstance()
        {
            return m_instance;
        }

        bool initialize(HINSTANCE hInstance, int nCmdShow);
        bool shutdown();
        HWND getMainWindow() const;
        HINSTANCE getAppInstance() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        ~WindowManager();

    private:
        WindowManager(unsigned int width = 800, unsigned int height = 600);
        
        static WindowManager m_instance;

        HINSTANCE m_appInstance;
        HWND m_mainWindow;
        LPCWSTR m_appName;
        unsigned int m_width;
        unsigned int m_height;
    };
}

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#endif // !_WINDOWMANAGER_HPP_
