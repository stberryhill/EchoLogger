#ifndef _ECHO_LOGGER_H
#define _ECHO_LOGGER_H

typedef struct EchoLogger EchoLogger;

EchoLogger *EchoLogger_Open(const char *fileName);
void EchoLogger_Info(const EchoLogger *logger, const char *message, ...);
void EchoLogger_Warn(const EchoLogger *logger, const char *message, ...);
void EchoLogger_Error(const EchoLogger *logger, const char *message, ...);
void EchoLogger_Close(EchoLogger *logger);

#endif