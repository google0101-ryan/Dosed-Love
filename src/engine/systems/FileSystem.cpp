#include <engine/systems/FileSystem.h>
#include <engine/Engine.h>
#include <lib/Logger.h>

#include <filesystem>
#include <stdio.h>

class StdioFile : public File
{
public:
    StdioFile(const char* path)
    {
        m_handle = fopen(path, "rb");
    }

    virtual void Close()
    {
        fclose(m_handle);
    }

    virtual void Seek(size_t seek, SeekDir whence)
    {
        fseek(m_handle, seek, whence);
    }

    virtual size_t Tell()
    {
        return ftell(m_handle);
    }
    
    virtual size_t Read(char* buf, size_t elemSize, size_t elemCount)
    {
        return fread(buf, elemSize, elemCount, m_handle);
    }
    
    virtual void Write(char* buf, size_t elemSize, size_t elemCount) {}
private:
    FILE* m_handle;
};

Cvar fs_basePath("fs_basepath", "Assets", "Sets the root folder to be appended to the executable folder for accessing assets", FLAG_ARCHIVED);

#define MAX_SEARCHPATHS 10

struct searchpath_t
{
    std::string basepath;
    std::string installdir; // Where the .exe is located
};

std::array<searchpath_t, MAX_SEARCHPATHS> g_searchpaths;
int g_searchPathCount;

bool FileSystem::Init(Engine* engine)
{
    // Search for .asset files, which contain concatenated game assets
    // TODO: Actually implement stuff here

    auto exeDir = std::filesystem::current_path();

    g_searchpaths[g_searchPathCount].installdir = exeDir;
    g_searchpaths[g_searchPathCount++].basepath = fs_basePath.GetValue();

    if (!std::filesystem::exists(exeDir / fs_basePath.GetValue()))
    {
        Logger::Error("Failed to find path to game assets (Is your game installed correctly?)");
        return false;
    }

    File* f = OpenFile("rootdiag.txt");

    if (!f)
    {
        Logger::Fatal("Required file 'rootdiag.txt' missing (Is your game installed correctly?)");
    }

    f->Close();

    Logger::Info("Filesystem initialized (assets at '%s')", (exeDir / fs_basePath.GetValue()).c_str());

    return true;
}

void FileSystem::Shutdown()
{
}

File *FileSystem::OpenFile(const char *name)
{
    File* ret = nullptr;

    // Check each searchpath
    for (int i = 0; i < g_searchPathCount; i++)
    {
        auto& sp = g_searchpaths[i];

        auto fullPath = std::filesystem::path(sp.installdir) / sp.basepath / name;

        if (std::filesystem::exists(fullPath))
        {
            Logger::Info("File '%s' found at '%s'", name, fullPath.c_str());
            ret = new StdioFile(fullPath.c_str());
            return ret;
        }
    }

    // TODO: Check inside .asset files
    Logger::Error("Failed to find file '%s'", name);
    return nullptr;
}
