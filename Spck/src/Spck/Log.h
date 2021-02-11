#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace Spck 
{
	class SPCK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define SPCK_LOG_TRACE(...) ::Spck::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPCK_LOG_DEBUG(...) ::Spck::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define SPCK_LOG_INFO(...) ::Spck::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPCK_LOG_ERROR(...) ::Spck::Log::GetCoreLogger()->error(__VA_ARGS__)

#define SPCK_LOG_TRACE(...) ::Spck::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPCK_LOG_DEBUG(...) ::Spck::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define SPCK_LOG_INFO(...) ::Spck::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPCK_LOG_ERROR(...) ::Spck::Log::GetCoreLogger()->error(__VA_ARGS__)