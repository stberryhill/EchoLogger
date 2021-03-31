# EchoLogger
> Simple logger for C apps.

* Written in Ansi-C
* Logging calls use familiar printf syntax
* Create as many loggers as you want
* Ouput written to file and echoed to console

# Installation
EchoLogger uses the Autotools, providing a familiar way to install from source.

First, run the bootstrap script to generate the autotools infrastructure:
'''sh
./bootstrap.sh
'''

The rest is history:
./configure
make
make install
'''