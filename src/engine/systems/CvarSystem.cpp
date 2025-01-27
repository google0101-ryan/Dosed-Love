#include <engine/systems/CvarSystem.h>
#include <engine/Engine.h>
#include <lib/Logger.h>

#include <stdlib.h>

Cvar g_cheats("cheats", "0", "Enables/disables cheats. Can only be changed in source code", FLAG_ROM);

Cvar* Cvar::head = nullptr;

class CvarSetCommand : public Command
{
public:
    virtual void Execute(CmdArgs_t& args)
    {
    }
};

static CvarSetCommand g_setCommand;

bool CvarSystem::Init(Engine* engine)
{
    auto var = Cvar::head;
    for (; var; var = var->m_next)
    {
        m_vars[var->m_name] = var;
    }

    Logger::Info("Done registering cvars (%d registered)", m_vars.size());

    engine->GetCmdSystem()->RegisterCommand("set", &g_setCommand);

    return true;
}

void CvarSystem::Shutdown()
{
    m_vars.clear();
}

Cvar::Cvar(const char *name, const char *value, const char *description, int flags)
{
    m_name = name;
    m_value = value;
    m_description = description;

    m_flags = flags;

    m_initValue = m_value;

    m_iValue = atoi(value);
    m_fValue = atof(value);
    m_bValue = (m_iValue > 0);

    m_next = head;
    head = this;
}
