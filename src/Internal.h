/*
 * License: Zlib
 * Copyright (c) Sean Tyler Berryhill (sean.tyler.berryhill@gmail.com)
 */

#ifndef _ECHO_LOGGER_INTERNAL_H
#define _ECHO_LOGGER_INTERNAL_H

#include <stdio.h>

struct Logger {
 FILE *filePtr;
 bool outputToTerminal;
};

#endif