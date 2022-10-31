#******************************************************************************
# Copyright (C) 2022 by Abdulrahman Aboghanima
#
# Redistribution and use in source and binary forms, with or without
# Modification, are permitted as long as there is no misuse of this
# software.
# Abdulrahman Aboghanima is not liable for any misuse of this Material
#
#******************************************************************************


SOURCES   	:= $(shell find . -name "*program.c")
TESTS		:= $(shell find . -name "*test.c")
INCLUDES  	:= $(sort $(shell dirname $(shell find . -name "*.h")))  tests/


#For every .c file associate a .o (object) file
OBJS	      	:= $(SOURCES:%.c=bin/%.o)
TESTSOBJS	:= $(TESTS:%.c=bin/%.o) #objects that has main function
ALLOBJS		:= $(OBJS) $(TESTSOBJS)

#For every .c file associate a .i (preprocessed) file
PREPROCESSED	:= $(ALLOBJS:%.o=%.i)

#For every .c file associate a .s (Assembly) file
ASSEMBLIES	:= $(ALLOBJS:%.o=%.asm)
DEPENDENCIES	:= $(ALLOBJS:%.o=%.o.d)


HEX_FILES	:= $(TESTS:%.c=bin/%.hex)



