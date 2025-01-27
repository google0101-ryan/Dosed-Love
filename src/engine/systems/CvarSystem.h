#pragma once

#include <engine/EngineSystem.h>

#include <unordered_map>
#include <string>

enum CvarFlags
{
    FLAG_ROM = (1 << 0),
    FLAG_CHEAT = (1 << 1),
    FLAG_ARCHIVED = (1 << 2)
};

class Cvar
{
    friend class CvarSystem;
public:
    Cvar(const char* name, const char* value, const char* description, int flags);

    const char* GetValue() { return m_value; }
    int GetInt() { return m_iValue; }
    bool GetBool() { return m_bValue; }
private:
    static Cvar* head;
    Cvar* m_next;

    const char* m_name;
    const char* m_value;
    const char* m_initValue;
    const char* m_description;
    
    int m_iValue;
    bool m_bValue;
    float m_fValue;

    int m_flags;
};

DEFINE_APPSYSTEM(CvarSystem)
public:
    virtual bool Init(Engine* engine);
    virtual void Shutdown();
private:
    std::unordered_map<std::string, Cvar*> m_vars;
END_APPSYSTEM()