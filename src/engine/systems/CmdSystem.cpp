#include <engine/systems/CmdSystem.h>

bool CmdSystem::Init(Engine* engine)
{
    m_cmds.clear();

    return true;
}

void CmdSystem::Shutdown()
{
    m_cmds.clear();
}

void CmdSystem::RegisterCommand(const char *name, Command *cmd)
{
    m_cmds[name] = cmd;
}

void ExecuteCommand(std::string text)
{
    // TODO: parse the command text, and execute the corresponding commands
}
