#include "dxUtil.h"

ID3D11Device* C_DXUTIL::g_pd3dDevice = NULL;
ID3D11DeviceContext* C_DXUTIL::g_pImmediateContext = NULL;

void C_DXUTIL::init(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext)
{
	g_pd3dDevice = pd3dDevice;
	g_pImmediateContext = pImmediateContext;
}

ID3D11Device* C_DXUTIL::getDevice()
{
	return g_pd3dDevice;
}

ID3D11DeviceContext* C_DXUTIL::getContext()
{
	return g_pImmediateContext;
}

HRESULT C_DXUTIL::CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;
    hr = D3DX11CompileFromFile(szFileName, NULL, NULL, szEntryPoint, szShaderModel,
        dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
    if (FAILED(hr))
    {
        if (pErrorBlob != NULL)
            OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        if (pErrorBlob) pErrorBlob->Release();
        return hr;
    }
    if (pErrorBlob) pErrorBlob->Release();

    return S_OK;
}

HRESULT C_DXUTIL::createBuffer(UINT byteWidth, UINT bindFlag, const void* pInitData , ID3D11Buffer ** ppBuffer)
{
    D3D11_BUFFER_DESC bd{};

    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = byteWidth;
    bd.BindFlags = bindFlag;
    bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData{};
    InitData.pSysMem = pInitData;

    if(pInitData)
        return g_pd3dDevice->CreateBuffer(&bd, &InitData, ppBuffer);
    else
        return g_pd3dDevice->CreateBuffer(&bd, nullptr, ppBuffer);

    return S_FALSE;
}