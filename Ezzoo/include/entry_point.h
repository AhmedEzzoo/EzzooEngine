#pragma once
#include "application.h"
#include "log.h"

extern Ref<Application> create_application();
#ifdef EZZOO_WINDOWS
int main(int argc, char **argv)
{
    Log::init();
    EZZOO_CORE_INFO("Plateform is Windows");

#if CONFIGURATION
    EZZOO_CORE_INFO("In Debug Mode");
#else
    EZZOO_CORE_INFO("In Release Mode");
#endif

    EZZOO_CORE_WARN("Logger has been initialized");
    int var{5};
    EZZOO_CLIENT_INFO("Client Logger has been initialized {0}", var);
    auto app = create_application();

    app->run();

    // delete app;
    return 0;
}
#endif