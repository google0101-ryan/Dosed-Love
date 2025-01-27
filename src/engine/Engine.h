#pragma once

#include <engine/systems/CvarSystem.h>
#include <engine/systems/CmdSystem.h>
#include <engine/systems/FileSystem.h>
#include <engine/systems/WindowSystem.h>

#include <engine/common/app.h>

class Engine
{
public:
    bool Init();
    void Tick();
    void Shutdown();

    bool InitApp(Application* app);

    CmdSystem* GetCmdSystem() { return &m_cmdSystem; }
    WindowSystem* GetWindowSystem() { return &m_windowSystem; }
private:
    CmdSystem m_cmdSystem;
    CvarSystem m_cvarSystem;
    FileSystem m_fileSystem;
    WindowSystem m_windowSystem;
};