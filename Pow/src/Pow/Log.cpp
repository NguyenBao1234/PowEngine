#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace POW
{
	std::shared_ptr<spdlog::logger>Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger>Log::s_ClientLogger;
}

void POW::Log::Init()
{
	spdlog::set_pattern("%^[%T] [%n]: %v%$");
	s_CoreLogger = spdlog::stdout_color_mt("PowEngine");
	s_ClientLogger = spdlog::stdout_color_st("Client");

	s_CoreLogger->set_level(spdlog::level::info);
	s_ClientLogger->set_level(spdlog::level::info);
}
