#include <engine/Engine.h>
#include <lib/Logger.h>

int main(int argc, char** argv)
{
    // Setup core engine functions before calling the user-defined Application
    Engine engine;
    
    if (!engine.Init())
    {
        Logger::Fatal("Failed to initialize engine");
    }

    // Call user-defined entrypoint
    engine.InitApp(GetApp());

    // Exit
    engine.Shutdown();

    return 0;
}