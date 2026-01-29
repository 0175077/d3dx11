#include "msg.h"


LRESULT C_MSG::OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	EndPaint(hWnd, &ps);
	return 0;
}

LRESULT C_MSG::Ondestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

void C_MSG::init()
{
	for (int i = 0; i < WM_USER; i++)
	{
		m_arFunc[i] = nullptr;
	}

	m_arFunc[WM_PAINT] = &C_MSG::OnPaint;
	m_arFunc[WM_DESTROY] = &C_MSG::Ondestroy;
}

LRESULT C_MSG::apiProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message >= WM_USER || !m_arFunc[message])
		return DefWindowProc(hWnd, message, wParam, lParam);

	return (this->*m_arFunc[message])(hWnd, message, wParam, lParam);
}
