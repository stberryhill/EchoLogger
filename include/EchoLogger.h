#ifndef _ECHO_LOGGER_H
#define _ECHO_LOGGER_H

#include "EchoAPIMacro.h"
#include <stdbool.h>

typedef struct Logger Logger;

ECHO_API Logger *Logger_OpenFileLogger(const char *fileName, bool outputToTerminal);
ECHO_API Logger *Logger_OpenConsoleLogger();
ECHO_API void Logger_Info(const Logger *logger, const char *message, ...);
ECHO_API void Logger_Warn(const Logger *logger, const char *message, ...);
ECHO_API void Logger_Error(const Logger *logger, const char *message, ...);
ECHO_API void Logger_Close(Logger *logger);

#endif