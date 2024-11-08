#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>

LRESULT CALLBACK winProc(HWND winHandle, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(64);
        break;

    default:
        return DefWindowProc(winHandle, msg, wParam, lParam);
        break;
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    const wchar_t className[] = L"prefClass";

    WNDCLASSEX wc = {0};

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = winProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassEx(&wc);

    HWND winHandle = CreateWindowEx(0, className, L"Pref",
                                    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                                    CW_USEDEFAULT, CW_USEDEFAULT,
                                    CW_USEDEFAULT, NULL, NULL,
                                    hInstance, NULL);

    if (winHandle == NULL)
    {
        std::cout << GetLastError();
    }

    ShowWindow(winHandle, true);
    UpdateWindow(winHandle);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
