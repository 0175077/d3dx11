#pragma once

#include<Windows.h>
#include "msg.h"

class C_API
{
private:
	static C_API* m_pApi;
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
	C_MSG		m_cMsg;

private:
	C_API() = default;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void registerWindow(HINSTANCE hInstance);
	bool createWindow();

public:
	static void createApi();
	static C_API* getApi();
	static void releaseApi();

	bool init(HINSTANCE hInstance);
	void updateMsg();
};
