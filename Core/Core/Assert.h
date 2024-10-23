#pragma once
#include "Core/Base.h"
#include "Core/Logger.h"
#include <filesystem>

#ifdef CORE_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define CORE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CORE##type##ERROR(msg, __VA_ARGS__); CORE_DEBUGBREAK(); } }
#define CORE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CORE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define CORE_INTERNAL_ASSERT_NO_MSG(type, check) CORE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CORE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define CORE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define CORE_INTERNAL_ASSERT_GET_MACRO(...) CORE_EXPAND_MACRO( CORE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CORE_INTERNAL_ASSERT_WITH_MSG, CORE_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define CORE_ASSERT(...) CORE_EXPAND_MACRO( CORE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define CORE_CORE_ASSERT(...) CORE_EXPAND_MACRO( CORE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define CORE_ASSERT(...)
#define CORE_CORE_ASSERT(...)
#endif