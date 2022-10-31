#******************************************************************************
# Copyright (C) 2022 by Abdulrahman Aboghanima
#
# Redistribution and use in source and binary forms, with or without
# Modification, are permitted as long as there is no misuse of this
# software.
# Abdulrahman Aboghanima is not liable for any misuse of this Material
#
#******************************************************************************

include sources.mk 

#The Compiler Used
CC		:= avr-gcc
#Target MCU
MCU       	:= atmega32
#CPU Clock Frequency
F_CPU     	:= 8000000ul
#Linker
LD        	:= avr-ld
OBJCOPY   	:= avr-objcopy


CFLAGS    := -std=c99 -Wall -Wextra -g -Os -fdata-sections -ffunction-sections -fshort-enums -mmcu=$(MCU) -DF_CPU=$(F_CPU)
CPPFLAGS  := $(INCLUDES:%=-I%)
LDFLAGS   := -Xlinker --gc-sections -Xlinker --relax -Wl,-u,vfprintf -lprintf_flt -lm #-Xlinker --strip-all




module_name	:=
EXEC		:= $(EXEC)


#RULES
#######################################################################################################



#`make build-all` for building all the executable files 
.PHONY: build-all
build-all: 
	$(foreach HEX_FILE, $(HEX_FILES), make build EXEC=$(HEX_FILE:%.hex=%);)



#`make build` for build only 
.PHONY: build
build: 		$(EXEC).elf $(EXEC).lss $(EXEC).hex



#`make compile-all` for compiling all source files
.PHONY: compile-all
compile-all: 	$(ALLOBJS)



#`make preprocess-all` for preprocessing all source files
.PHONY: preprocess-all
preprocess-all: $(PREPROCESSED)



#`make assemble-all` for generating an assembly file for all source files
.PHONY: assemble-all
assemble-all:	$(ASSEMBLIES)



#`make flash` to flash the hex file to the micro-controller
.PHONY: flash
flash: $(EXEC).hex
	@echo Flashing to the $(MCU)..
	avrdude -p $(MCU) -c usbasp -U flash:w:$<:i -F -P usb




#`make EXECUTABLENAME.lss` for generating Extended listing
%.lss: %.elf
	@echo Invoking: Avr Extended listing 
	avr-objdump -S -h $< > $@




#`make EXECUTABLENAME.elf` for generating the elf file
%.elf: $(OBJS) %.o
	@echo Building Target: $@
	$(CC) $(CFLAGS) $(LDFLAGS) -Xlinker -Map=$@.map $^ -o $@
	@avr-size -C $@





#`make x.o` generate an object file, x.o from source file, x.c,.
bin/%.o:%.c
	@mkdir -p $(INCLUDES:%=bin/%)
	@echo Compiling ---------------------------------------- $@
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) -MMD -MP -MT$@ -MF$@.d $< -o $@



#`make x.asm` generate an assembly file, x.asm from source file, x.c,.
bin/%.asm:%.c
	@mkdir -p $(INCLUDES:%=bin/%)
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@



#`make x.i` generate a preprocessed file, x.i from source file, x.c,.
bin/%.i:%.c
	@mkdir -p $(INCLUDES:%=bin/%)
	$(CC) -E $(CFLAFS) $(CPPFLAGS) $< -o $@



#`make x.hex` generate an object file, x.hex from elf file, x.elf,.
%.hex:%.elf
	@echo Genrating hex file --------------------------------- $@
	@$(OBJCOPY) -j .text -j .data -O ihex $< $@


#`make docs` for generating documentation
.PHONY: docs
docs:
	@echo Generating Documentations
	@doxygen &> /dev/null



.PHONY: module
module:
	@test $(module_name) || \
	(echo "Enter the path followed by the module name. i.e MCAL/moduleX"; exit 1)
	@mkdir -p $(shell dirname ${module_name}) 
	@touch $(module_name)_config.h \
	$(module_name)_interface.h \
	$(module_name)_program.c \
	$(module_name)_register.h \
	$(module_name)_private.h


.PHONY: test
test:
	@echo The Sources  are :  $(SOURCES)
	@echo
	@echo The Includes are :  $(INCLUDES)
	@echo
	@echo The objects  are :  $(OBJS)
	@echo Test files   are :  $(TESTSOBJS)
	@echo Hex files    are :  $(HEX_FILES)

.PHONY: clean
clean:
	@rm -rf $(OBJS) $(PREPROCESSED) $(ASSEMBLIES) $(DEPENDENCIES) $(TESTSOBJS) \
	*.out *.map *.elf *.map *.hex *.s *.i *.d *.lss *.o *.obj bin
	@echo CLEANED!
