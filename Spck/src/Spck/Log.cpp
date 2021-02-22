#include "Log.h"

namespace Spck 
{
	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%l][Thread-%t] %c [%n] - %v%$");
		s_Logger = spdlog::stdout_color_mt("SPCK");
		s_Logger->set_level(spdlog::level::trace);
	}
}
