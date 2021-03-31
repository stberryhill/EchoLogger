#!/bin/sh

# Running this script generates the autotools infrastructure needed to build the project.
autoreconf --install
automake --add-missing --copy >/dev/null 2>&1
libtoolize
