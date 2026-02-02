#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

class C_RENDER;

class C_DXUTIL
{
	friend C_RENDER;
private:
	C_DXUTIL() = default;
	static void init(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext);

private:
	static ID3D11Device* g_pd3dDevice;
	static ID3D11DeviceContext* g_pImmediateContext;

public:
	static ID3D11Device* getDevice();
	static ID3D11DeviceContext* getContext();
	static HRESULT CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	static HRESULT createBuffer(UINT byteWidth, UINT bindFlag, const void* pInitData, ID3D11Buffer** ppBuffer);
};
