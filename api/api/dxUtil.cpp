#include "dxUtil.h"

ID3D11Device* C_DXUTIL::g_pd3dDevice = NULL;
ID3D11DeviceContext* C_DXUTIL::g_pImmediateContect = NULL;

void C_DXUTIL::init(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContect)
{
    g_pd3dDevice = pd3dDevice;
    g_pImmediateContect = pImmediateContect;
}

ID3D11Device* C_DXUTIL::getDevice()
{
    return g_pd3dDevice;
}

ID3D11DeviceContext* C_DXUTIL::getContext()
{
    return g_pImmediateContect;
}
