#ifndef LOG_H
#define LOG_H
#include "facilities.h"

class Log
{

public:
    static void init();
    static std::shared_ptr<spdlog::logger> &get_core_logger() { return s_core_logger; }
    static std::shared_ptr<spdlog::logger> &get_client_logger() { return s_client_logger; }

private:
    static std::shared_ptr<spdlog::logger> s_core_logger;
    static std::shared_ptr<spdlog::logger> s_client_logger;
};

#define EZZOO_CORE_WARN(...) ::Log::get_core_logger()->warn(__VA_ARGS__)
#define EZZOO_CORE_INFO(...) ::Log::get_core_logger()->info(__VA_ARGS__)
#define EZZOO_CORE_ERROR(...) ::Log::get_core_logger()->error(__VA_ARGS__)
#define EZZOO_CORE_TRACE(...) ::Log::get_core_logger()->trace(__VA_ARGS__)

#define EZZOO_CLIENT_WARN(...) ::Log::get_client_logger()->warn(__VA_ARGS__)
#define EZZOO_CLIENT_INFO(...) ::Log::get_client_logger()->info(__VA_ARGS__)
#define EZZOO_CLIENT_ERROR(...) ::Log::get_client_logger()->error(__VA_ARGS__)
#define EZZOO_CLIENT_TRACE(...) ::Log::get_client_logger()->trace(__VA_ARGS__)
#endif
