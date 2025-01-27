#pragma once

#include <engine/common/type.h>

class Engine;

abstract_class System
{
public:
    virtual const char* GetName() const = 0;

    virtual bool Init(Engine* engine) = 0;
    virtual void Shutdown() = 0;
};

#define DEFINE_APPSYSTEM(name) \
    class name : public System \
    { \
    public: \
        virtual const char* GetName() const { return #name; } \
    private:

#define END_APPSYSTEM() \
    };