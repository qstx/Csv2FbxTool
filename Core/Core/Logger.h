#pragma once

#include "Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

class Logger
{
public:
	static void Init();

	static Ref<spdlog::logger>& GetLogger() { return s_CoreLogger; }
private:
	static Ref<spdlog::logger> s_CoreLogger;
};

// Core log macros
#define CORE_TRACE(...)    ::Logger::GetLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::Logger::GetLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::Logger::GetLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::Logger::GetLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::Logger::GetLogger()->critical(__VA_ARGS__)
