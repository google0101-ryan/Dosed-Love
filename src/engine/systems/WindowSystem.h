#pragma once

#include <engine/EngineSystem.h>

DEFINE_APPSYSTEM(WindowSystem)
public:
    virtual bool Init(Engine* engine);
    virtual void Shutdown();

    void UpdateEvents();

    bool ShouldWindowClose();
private:
    void* m_windowHandle;

    bool m_closeRequested = false;
END_APPSYSTEM()