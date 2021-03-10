#pragma once

#include "Crossfire/Core/Base.h"
#include "spdlog/spdlog.h"

namespace Crossfire
{

	class Log
	{

	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
}
// Core log macros
#define CF_CORE_TRACE(...)  ::Crossfire::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CF_CORE_INFO(...)   ::Crossfire::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CF_CORE_WARN(...)   ::Crossfire::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CF_CORE_ERROR(...)  ::Crossfire::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CF_CORE_FATAL(...)  ::Crossfire::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CF_TRACE(...)		::Crossfire::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CF_INFO(...)		::Crossfire::Log::GetClientLogger()->info(__VA_ARGS__)
#define CF_WARN(...)		::Crossfire::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CF_ERROR(...)		::Crossfire::Log::GetClientLogger()->error(__VA_ARGS__)
#define CF_FATAL(...)		::Crossfire::Log::GetClientLogger()->fatal(__VA_ARGS__)