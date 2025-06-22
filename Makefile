.POSIX:
.SUFFIXES:
#Toolchain
CC         = cc
CFLAGS     = -W -O
LDLIBS     = -lm

# Debugging tools
all:
	.c .o

