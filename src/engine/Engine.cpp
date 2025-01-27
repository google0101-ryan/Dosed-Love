#include <engine/Engine.h>

bool Engine::Init()
{
    if (!m_cmdSystem.Init(this))
    {
        return false;
    }

    if (!m_cvarSystem.Init(this))
    {
        return false;
    }

    if (!m_fileSystem.Init(this))
    {
        return false;
    }

    if (!m_windowSystem.Init(this))
    {
        return false;
    }

    return true;
}

void Engine::Tick()
{
}

void Engine::Shutdown()
{
    m_windowSystem.Shutdown();
    m_fileSystem.Shutdown();
    m_cvarSystem.Shutdown();
    m_cmdSystem.Shutdown();
}

bool Engine::InitApp(Application *app)
{
    if (!app->Init())
    {
        return false;
    }

    while (app->IsRunning() && !m_windowSystem.ShouldWindowClose())
    {
        m_windowSystem.UpdateEvents();

        Tick();
        app->Tick();
    }

    app->Shutdown();

    return true;
}
