#include <windows.h>

#include "gui.h"
#include "mutex.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MULTIROBLOX_CLASS";

    RegisterClass(&wc);
  
    g_hwnd = CreateWindowEx(0, "MULTIROBLOX_CLASS", L"MultiRoblox", WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 200, 120, NULL, NULL, hInstance, NULL);
    g_title = CreateWindow(L"STATIC", L"MultiRoblox 0.0.4", WS_VISIBLE | WS_CHILD, 10, 10, 365, 20, g_hwnd, NULL, hInstance, NULL);
    g_textbox = CreateWindow(L"EDIT", L"Please Open Roblox.This\r\nApplies Automatically", WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_AUTOHSCROLL | ES_MULTILINE | ES_READONLY, 10, 40, 365, 365, g_hwnd, NULL, hInstance, NULL);
    if (g_hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(g_hwnd, nCmdShow);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
