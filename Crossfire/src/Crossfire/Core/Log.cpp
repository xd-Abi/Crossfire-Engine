#include "cfpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Crossfire
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Initialize()
	{
		spdlog::set_pattern("[%H:%M:%S] %^%n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Crossfire");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("Client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}