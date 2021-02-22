#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Core.h"

namespace Spck 
{
	class SPCK_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetLogger()
		{
			return s_Logger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define SPCK_LOG_TRACE(...) ::Spck::Log::GetLogger()->trace(__VA_ARGS__)
#define SPCK_LOG_DEBUG(...) ::Spck::Log::GetLogger()->debug(__VA_ARGS__)
#define SPCK_LOG_INFO(...) ::Spck::Log::GetLogger()->info(__VA_ARGS__)
#define SPCK_LOG_ERROR(...) ::Spck::Log::GetLogger()->error(__VA_ARGS__)
