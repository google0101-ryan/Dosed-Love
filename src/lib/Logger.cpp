#include <lib/Logger.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int Logger::Info(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    printf(ANSI_COLOR_GREEN "[INFO]: " ANSI_COLOR_RESET);
    vprintf(fmt, ap);
    printf("\n");
}

int Logger::Error(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    printf(ANSI_COLOR_RED "[ERROR]: " ANSI_COLOR_RESET);
    vprintf(fmt, ap);
    printf("\n");
}

int Logger::Fatal(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    printf(ANSI_COLOR_RED "[FATAL]: " ANSI_COLOR_RESET);
    vprintf(fmt, ap);
    printf("\nShutting down...\n");

    exit(1);
}