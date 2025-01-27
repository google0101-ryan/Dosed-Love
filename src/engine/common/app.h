#pragma once

#include <engine/common/type.h>

abstract_class Application
{
public:
    virtual bool Init() = 0;
    virtual void Tick() = 0;
    virtual void Shutdown() = 0;

    virtual bool IsRunning() = 0;
};

#define DEFINE_ENTRYPOINT(appName) \
    static appName g_##appName; \
    Application* GetApp() \
    { \
        return &g_##appName; \
    }

Application* GetApp();