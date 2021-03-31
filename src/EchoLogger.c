#include "EchoLogger.h"
#include "Internal.h"

#include <stdio.h>
#include <stdlib.h>

EchoLogger *EchoLogger_Open(const char *fileName) {
  EchoLogger *logger = malloc(sizeof *logger);
  logger->filePtr = fopen(fileName, "w");

  if (!logger->filePtr) {
    printf("EchoLogger could not open file \"%s\" for logging.\n", fileName);
    exit(-1);
  }
}

void EchoLogger_Info(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logFile, "[Info] ");
  vfprintf(logFile, message, variableArgumentList);
  fprintf(logFile, "\n");
  fflush(logFile);
  
  printf("[Info] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Warn(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logFile, "[Warnning] ");
  vfprintf(logFile, message, variableArgumentList);
  fprintf(logFile, "\n");
  fflush(logFile);

  printf("[Warnning] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Error(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logFile, "[Error] ");
  vfprintf(logFile, message, variableArgumentList);
  fprintf(logFile, "\n");
  fflush(logFile);

  printf("[Error] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Close(const EchoLogger *logger) {
  fclose(logger->filePtr);
  free(logger);
}
