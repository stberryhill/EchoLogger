#ifndef _ECHO_LOGGER_INTERNAL_H
#define _ECHO_LOGGER_INTERNAL_H

#include <stdio.h>

struct Logger {
 FILE *filePtr;
 bool outputToTerminal;
};

#endif