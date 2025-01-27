#pragma once

#include <engine/common/app.h>

class DosedLoveApp : public Application
{
public:
    virtual bool Init();
    virtual void Tick();
    virtual void Shutdown();

    virtual bool IsRunning() { return true; }
};