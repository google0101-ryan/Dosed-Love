#pragma once

#include <array>
#include <unordered_map>
#include <string>

#include <engine/EngineSystem.h>

#define MAX_ARGS 10

typedef std::array<const char*, MAX_ARGS> CmdArgs_t;

abstract_class Command
{
    friend class CmdSystem;
public:
    virtual void Execute(CmdArgs_t& cmd) = 0;
private:
    Command* m_next;
};

DEFINE_APPSYSTEM(CmdSystem)
public:
    virtual bool Init(Engine* engine);
    virtual void Shutdown();

    void RegisterCommand(const char* name, Command* cmd);

    void ExecuteCommand(std::string text);
private:
    std::unordered_map<std::string, Command*> m_cmds;
END_APPSYSTEM()