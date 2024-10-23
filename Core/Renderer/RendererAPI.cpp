#include "pch.h"
#include "RendererAPI.h"
#include "Core/Assert.h"
#include "Core/Logger.h"
#include "Platforms/DirectX12/DX12RendererAPI.h"

RendererAPI::API RendererAPI::s_API = RendererAPI::API::Dirext12;

Scope<RendererAPI> RendererAPI::Create()
{
	switch (s_API)
	{
	case RendererAPI::API::None: CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
	case RendererAPI::API::Dirext12:  return CreateScope<DX12RendererAPI>();
	}

	CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}
