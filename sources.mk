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
INCLUDES  	:= $(sort $(shell dirname $(shell find . -name "*.h")))

TESTS		:= $(shell find . -name "*test.c")
