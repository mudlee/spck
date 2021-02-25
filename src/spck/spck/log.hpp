#pragma once

#include <spck/api.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace spck {
class SPCK_API log {
public:
    static std::shared_ptr<spdlog::logger> get() {
        static std::shared_ptr<spdlog::logger> logger = make_logger();
        return logger;
    }

private:
    static std::shared_ptr<spdlog::logger> make_logger() {
        spdlog::set_pattern("%^[%l][Thread-%t] %c [%n] - %v%$");
        auto retval = spdlog::stdout_color_mt("SPCK");
        retval->set_level(spdlog::level::trace);
        return retval;
    }
};
} // namespace spck

#define SPCK_LOG_TRACE(...) ::spck::log::get()->trace(__VA_ARGS__)
#define SPCK_LOG_DEBUG(...) ::spck::log::get()->debug(__VA_ARGS__)
#define SPCK_LOG_INFO(...) ::spck::log::get()->info(__VA_ARGS__)
#define SPCK_LOG_ERROR(...) ::spck::log::get()->error(__VA_ARGS__)
