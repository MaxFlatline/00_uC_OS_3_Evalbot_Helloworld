# Hi! I'am default build script for uC-OS3!
# My responsibility is to make sure that uC-OS3 sources will be built,
# even if no other makefiles are invoked. To achieve this, we will need the following:
# * Make sure that i know where are the sources stored
# * Default objects storage directory
# * Default compiler toolchain

# Get the default sources directory

#Compiler set
ifeq "$(CC)", "arm-none-eabi-gcc"

else

endif

#Objects directory
WORKDIR=../Middleware/uC-OS2

