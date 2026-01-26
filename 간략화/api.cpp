#include "api.h"
#include "resource.h"

C_API* C_API::m_pApi = nullptr;

LRESULT CALLBACK C_API::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return m_pApi->apiProc(hWnd, message, wParam, lParam);
}

LRESULT C_API::apiProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    m_nDate = 0;
    switch(message)
    {
    case WM_LBUTTONDBLCLK:
    {
        break;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void C_API::releaseApi()
{
    if (m_pApi)
    {
        delete m_pApi;
        m_pApi = nullptr;
    }
}

void C_API::createApi()
{
    if (!m_pApi)
        m_pApi = new C_API{};
}

C_API* C_API::getApi()
{
    return nullptr;
}

bool C_API::init(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT12));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = L"className";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);


    HWND hWnd = CreateWindowW(L"className", nullptr, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
        return false;

    ShowWindow(hWnd, SW_SHOWDEFAULT);
    UpdateWindow(hWnd);

    return true;
}

void C_API::updateMsg()
{
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
