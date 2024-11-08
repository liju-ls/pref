#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    const wchar_t className[] = L"prefClass";

    WNDCLASS wc = {};

    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;

    RegisterClass(&wc);

    HWND winHandle = CreateWindowEx(0, className, L"Pref",
                                    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                                    CW_USEDEFAULT, CW_USEDEFAULT,
                                    CW_USEDEFAULT, NULL, NULL,
                                    hInstance, NULL);

    if (winHandle == NULL)
    {
        return 1;
    }

    ShowWindow(winHandle, true);

    while (true)
    {
    }

    return 0;
}
