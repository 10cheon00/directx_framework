#pragma once
#include "..//ErrorLogger.h"

#pragma comment(lib,"D3DCompiler.lib")
#include <d3d11.h>
#include <wrl/client.h>
#include <d3dcompiler.h>

class VertexShader {
public:
	bool Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderpath, D3D11_INPUT_ELEMENT_DESC *layoutDesc, UINT numElements);
	ID3D11VertexShader* GetShader();
	ID3D10Blob* GetBuffer();
	ID3D11InputLayout* GetInputlayout();
private:
	Microsoft::WRL::ComPtr<ID3D11VertexShader> shader = nullptr;
	//ID3D10Blob is a generic chunk of memory. Must be cast appropriate memory type.
	Microsoft::WRL::ComPtr<ID3D10Blob> shader_buffer = nullptr;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
};


class PixelShader {
public:
	bool Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderpath);
	ID3D11PixelShader* GetShader();
	ID3D10Blob* GetBuffer();
private:
	Microsoft::WRL::ComPtr<ID3D11PixelShader> shader;
	Microsoft::WRL::ComPtr<ID3D10Blob> shader_buffer;
};