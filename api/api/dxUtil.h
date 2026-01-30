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
	static void Init();
	static void init(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContect);

private:
	static ID3D11Device* g_pd3dDevice = NULL;
	static ID3D11DeviceContext* g_pImmediateContect = NULL;

public:
	static ID3D11Device* getDevice();
	static ID3D11DeviceContext* getContext();



};