## Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([EchoLogger],[0.1],[sean.tyler.berryhill@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_TESTDIR([src/tests])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_AR

# Init libtool since we want to build shared lib
LT_INIT([dlopen shared])

# Checks for header files.
AC_CHECK_HEADERS([stdio.h stdarg.h stdlib.h])

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([atexit])

# Runs config.status in these makefiles to regenerate them from their templates if there are any changes.
AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
