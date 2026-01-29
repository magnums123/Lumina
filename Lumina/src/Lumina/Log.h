#pragma once

#include <Lumina/Core.h>
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Lumina
{

class LUMINA_API Logger
{
  public:
    static void Init()
    {
        coreLogger = spdlog::stderr_color_mt("CORE");
        clientLogger = spdlog::stderr_color_mt("LUMINA");
    };

    static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
    static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

  private:
    inline static std::shared_ptr<spdlog::logger> coreLogger = nullptr;
    inline static std::shared_ptr<spdlog::logger> clientLogger = nullptr;
};

} // namespace Lumina

#define LM_CORE_INFO(...) Lumina::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define LM_CORE_WARNING(...) Lumina::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define LM_CORE_ERROR(...) Lumina::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define LM_CORE_CRITICAL(...) Lumina::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define LM_INFO(...) Lumina::Logger::GetClientLogger()->info(__VA_ARGS__)
#define LM_WARNING(...) Lumina::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define LM_ERROR(...) Lumina::Logger::GetClientLogger()->error(__VA_ARGS__)
#define LM_CRITICAL(...) Lumina::Logger::GetClientLogger()->critical(__VA_ARGS__)
