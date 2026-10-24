#include "xserver/config_service.h"
#include "shared/protocol.h"
#include "shared/logger.h"
#include "xserver/crash_handler.h"
#include <csignal>
#include <unistd.h>
#include <atomic>

static std::atomic<bool> g_running{true};

static void signal_handler(int) {
    g_running = false;
}

int main() {
    fbx::shared::Logger::init("xconfig");
    fbx::xserver::installCrashHandler("xconfig");
    LOG_INFO("xconfig starting...");

    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    // Eagerly load configuration from disk so it is cached on first access.
    const std::string theme = fbx::xserver::ConfigService::get("ui.theme", "light");
    LOG_INFO("Configuration loaded. Active theme: {}", theme);

    LOG_INFO("ConfigService running. Waiting for SIGTERM/SIGINT.");

    while (g_running) {
        pause();
    }

    LOG_INFO("xconfig shutting down.");
    return 0;
}
