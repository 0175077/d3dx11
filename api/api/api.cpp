#include "api.h"
#include "resource.h"

C_API* C_API::m_pApi = nullptr;

LRESULT C_API::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return m_pApi->m_cMsg.apiProc(hWnd, message, wParam, lParam);
}

void C_API::registerWindow(HINSTANCE hInstance)
{
	m_hInstance = hInstance;
	WNDCLASSEXW wcex{ sizeof(WNDCLASSEX) , CS_HREDRAW | CS_VREDRAW ,  WndProc , 0 ,0 , m_hInstance ,LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_API))
		, LoadCursor(nullptr, IDC_ARROW) , (HBRUSH)(COLOR_WINDOW + 1) , 0 , L"name" , LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)) };
	RegisterClassExW(&wcex);
}

bool C_API::createWindow()
{
	m_hWnd = CreateWindowW(L"name", L"", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInstance, nullptr);

	if (!m_hWnd)
		return FALSE;

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);
	return true;
}

void C_API::createApi()
{
	if (!m_pApi)
		m_pApi = new C_API();
}

C_API* C_API::getApi()
{
	return m_pApi;
}

void C_API::releaseApi()
{
	if (m_pApi)
	{
		delete m_pApi;
		m_pApi = nullptr;
	}
}

bool C_API::init(HINSTANCE hInstance)
{
	registerWindow(hInstance);
	createWindow();
	m_cMsg.init();

	m_cRender.InitDevice(m_hWnd);

	return true;
}

void C_API::updateMsg()
{
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			m_cRender.Render();
		}
	}

	m_cRender.CleanupDevice();
}
