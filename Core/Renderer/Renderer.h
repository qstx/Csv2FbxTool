#pragma once
#include "Core/Base.h"
#include "Renderer/RendererAPI.h"

class Renderer
{
public:
	static void  Init();
	static void  Destroy();
	static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
};