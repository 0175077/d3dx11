// WindowsProject12.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject12.h"
#include "api.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);

    //C_API cApi{};

    //cApi.init(hInstance);
    //cApi.updateMsg();

    C_API::createApi();
    C_API::getApi()->init(hInstance);
    C_API::getApi()->createApi();

    return 0;
}

