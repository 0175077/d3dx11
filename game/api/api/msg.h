#pragma once

#include<windows.h>

class C_MSG
{
private:
	LRESULT(C_MSG::* m_arFunc[WM_USER])(HWND, UINT, WPARAM, LPARAM);

private:
	LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT Ondestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	C_MSG() = default;
	void init();
	LRESULT apiProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
