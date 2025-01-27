#pragma once

#include <engine/EngineSystem.h>
#include <stddef.h>

enum SeekDir
{
    SEEK_DIR_SET,
    SEEK_DIR_CUR,
    SEEK_DIR_END  
};

abstract_class File
{
public:
    virtual void Close() = 0;
    virtual void Seek(size_t seek, SeekDir whence) = 0;
    virtual size_t Tell() = 0;
    virtual size_t Read(char* buf, size_t elemSize, size_t elemCount) = 0;
    virtual void Write(char* buf, size_t elemSize, size_t elemCount) = 0;
};

DEFINE_APPSYSTEM(FileSystem)
public:
    virtual bool Init(Engine* engine);
    virtual void Shutdown();

    File* OpenFile(const char* name);
private:

END_APPSYSTEM()