#pragma once

#include <stdio.h>

namespace Logger
{

int Info(const char*, ...);
int Warning(const char*, ...);
int Error(const char*, ...);
int Fatal(const char*, ...);

}