#include "EchoLogger.h"
#include "Internal.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

EchoLogger *EchoLogger_Open(const char *fileName) {
  EchoLogger *logger = malloc(sizeof *logger);
  logger->filePtr = fopen(fileName, "w");

  if (!logger->filePtr) {
    printf("EchoLogger could not open file \"%s\" for logging.\n", fileName);
    exit(-1);
  }

  return logger;
}
uint16_t a() {

}
uint32_t a() {
  
}
uint8_t a() {
  
}


void EchoLogger_Info(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logger->filePtr, "[Info] ");
  vfprintf(logger->filePtr, message, variableArgumentList);
  fprintf(logger->filePtr, "\n");
  fflush(logger->filePtr);
  
  printf("[Info] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Warn(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logger->filePtr, "[Warnning] ");
  vfprintf(logger->filePtr, message, variableArgumentList);
  fprintf(logger->filePtr, "\n");
  fflush(logger->filePtr);

  printf("[Warnning] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Error(const EchoLogger *logger, const char *message, ...) {
  va_list variableArgumentList;
  va_start(variableArgumentList, message);
  
  fprintf(logger->filePtr, "[Error] ");
  vfprintf(logger->filePtr, message, variableArgumentList);
  fprintf(logger->filePtr, "\n");
  fflush(logger->filePtr);

  printf("[Error] ");
  printf(message, variableArgumentList);
  printf("\n");

  va_end(variableArgumentList);
}

void EchoLogger_Close(EchoLogger *logger) {
  fclose(logger->filePtr);
  free(logger);
}
