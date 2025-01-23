//Copyright POW Game std
#pragma once
#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

namespace POW
{
	class POW_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr <spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}
//Core log macro:
#define PE_CORE_TRACE(...)		::POW::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define PE_CORE_INFO(...)		::POW::Log::GetCoreLogger()->info(__VA_ARGS__);
#define PE_CORE_WARN(...)		::POW::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define PE_CORE_ERR(...)		::POW::Log::GetCoreLogger()->error(__VA_ARGS__);
#define PE_CORE_CRIT(...)		::POW::Log::GetCoreLogger()->critical(__VA_ARGS__);

//Client log macro:
#define PE_TRACE(...)		::POW::Log::GetClientLogger()->trace(__VA_ARGS__);
#define PE_INFO(...)		::POW::Log::GetClientLogger()->info(__VA_ARGS__);
#define PE_WARN(...)		::POW::Log::GetClientLogger()->warn(__VA_ARGS__);
#define PE_ERR(...)			::POW::Log::GetClientLogger()->error(__VA_ARGS__);
#define PE_CRIT(...)		::POW::Log::GetClientLogger()->critical(__VA_ARGS__);