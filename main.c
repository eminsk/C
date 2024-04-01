#include <windows.h>

#define ID_FILE_OPEN 1
#define ID_FILE_EXIT 2

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

HMENU hMenu;
HMENU hSubMenu;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ��������� ����� ����
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // �������� ����
    HWND hwnd = CreateWindow("MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW, 100, 400, 640, 480, NULL, NULL, hInstance, NULL);

    // �������� ����
    hMenu = CreateMenu();
    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_OPEN, "Open");
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "Exit");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu, "File");

    // ��⠭���� ���� � ����
    SetMenu(hwnd, hMenu);

    // �⮡ࠦ���� ����
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // ���� ��ࠡ�⪨ ᮮ�饭��
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case ID_FILE_OPEN:
                    // ��ࠡ�⪠ ������� "Open"
                    break;
                case ID_FILE_EXIT:
                    // ��ࠡ�⪠ ������� "Exit"
                    PostQuitMessage(0);
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}
