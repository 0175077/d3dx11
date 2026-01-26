#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "framework.h"

class C_API
{
private:
	static C_API* m_pApi;
	int m_nDate;

private:
	static LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	LRESULT apiProc(HWND, UINT, WPARAM, LPARAM);
	C_API() = default;

public:
	static void releaseApi();
	static void createApi();
	static C_API* getApi();

	bool init(HINSTANCE hInstance);
	void updateMsg();
};