#include <engine/systems/WindowSystem.h>
#include <engine/systems/CvarSystem.h>

#include <engine/Engine.h>
#include <lib/Logger.h>

#include <SDL3/SDL.h>

Cvar g_windowWidth("g_width", "1280", "The width of the main window", FLAG_ARCHIVED);
Cvar g_windowHeight("g_height", "720", "The height of the main window", FLAG_ARCHIVED);
// TODO: Find a better way to do this
Cvar g_gameName("g_gameName", "Dosed Love", "The title of the main window", FLAG_ROM);

Cvar g_fullscreen("g_fullscreen", "0", "Toggles fullscreen mode", FLAG_ARCHIVED);

bool WindowSystem::Init(Engine* engine)
{
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
    {
        Logger::Error("Failed to initialize SDL3!");
        return false;
    }

    m_windowHandle = SDL_CreateWindow(g_gameName.GetValue(), 
                                        g_windowWidth.GetInt(), 
                                        g_windowHeight.GetInt(), 
                                        g_fullscreen.GetBool() ? SDL_WINDOW_FULLSCREEN : 0);
    
    if (!m_windowHandle)
    {
        Logger::Error("Failed to create SDL3 window: %s", SDL_GetError());
        return false;
    }

    Logger::Info("Window initialized with a resolution of %dx%d\n", g_windowWidth.GetInt(), g_windowHeight.GetInt());

    return true;
}

void WindowSystem::Shutdown()
{
    SDL_DestroyWindow((SDL_Window*)m_windowHandle);
    SDL_Quit();
}

bool WindowSystem::ShouldWindowClose()
{
    return m_closeRequested;
}

void WindowSystem::UpdateEvents()
{
    SDL_Event event;


    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            m_closeRequested = true;
            break;
        }
    }
}
