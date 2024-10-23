#include "pch.h"
#include "GraphicsContext.h"
#include "Core/Assert.h"
#include "Renderer.h"
#include "RendererAPI.h"
#include "Platforms/DirectX12/DX12Context.h"

Scope<GraphicsContext> GraphicsContext::Create(void* window)
{
	switch (Renderer::GetAPI())
	{
	case RendererAPI::API::None:    CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
	case RendererAPI::API::Dirext12:  return CreateScope<DX12Context>();
	}

	CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}