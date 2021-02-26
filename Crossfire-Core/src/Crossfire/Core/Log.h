#pragma once

#include "Base.h"
#include "spdlog/spdlog.h"

namespace Crossfire
{

	class CF_API Log
	{
	public:
		static void Initialize();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
		static Ref<spdlog::logger> s_Logger;
	};

}
// Core log macros
#define CF_CORE_TRACE(...)  ::Crossfire::Log::GetLogger()->trace(__VA_ARGS__)
#define CF_CORE_INFO(...)   ::Crossfire::Log::GetLogger()->info(__VA_ARGS__)
#define CF_CORE_WARN(...)   ::Crossfire::Log::GetLogger()->warn(__VA_ARGS__)
#define CF_CORE_ERROR(...)  ::Crossfire::Log::GetLogger()->error(__VA_ARGS__)
#define CF_CORE_FATAL(...)  ::Crossfire::Log::GetLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CF_TRACE(...)		::Crossfire::Log::GetLogger()->trace("CLIENT: {0}", __VA_ARGS__)
#define CF_INFO(...)		::Crossfire::Log::GetLogger()->info("CLIENT: {0}",__VA_ARGS__)
#define CF_WARN(...)		::Crossfire::Log::GetLogger()->warn("CLIENT: {0}",__VA_ARGS__)
#define CF_ERROR(...)		::Crossfire::Log::GetLogger()->error("CLIENT: {0}",__VA_ARGS__)
#define CF_FATAL(...)		::Crossfire::Log::GetLogger()->fatal("CLIENT: {0}",__VA_ARGS__)