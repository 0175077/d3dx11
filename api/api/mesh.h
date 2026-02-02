#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <xnamath.h>

class C_MESH
{
private:
    struct SimpleVertex
    {
        XMFLOAT3 Pos;
        XMFLOAT2 Tex;
    };

private:
    ID3D11Buffer* g_pVertexBuffer;
    ID3D11Buffer* g_pIndexBuffer;
    ID3D11ShaderResourceView* g_pTextureRV;



public:
    C_MESH() = default;
    HRESULT loadData(const char* strFileName);
    ID3D11Buffer* const* getVertexBuffer();
    ID3D11Buffer* getIndexBuffer();
    ID3D11ShaderResourceView* const* getTexture();
    void release();
};