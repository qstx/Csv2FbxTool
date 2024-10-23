#pragma once
#include <memory>

#if defined(DEBUG) || defined(_DEBUG) 
#if defined(_WIN32)
#define CORE_DEBUGBREAK() __debugbreak()
#elif defined(_LINUX)
#include <signal.h>
#define CORE_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define CORE_ENABLE_ASSERTS
#else
#define CORE_DEBUGBREAK()
#endif

#define CORE_EXPAND_MACRO(x) x
#define CORE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}