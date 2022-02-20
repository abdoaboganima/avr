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

CC		:= avr-gcc		#The Compiler Used                            
MCU       	:= atmega32		#Target MCU
F_CPU     	:= 8000000ul		#CPU Clock Frequency
LD        	:= avr-ld		#Linker
OBJCOPY   	:= avr-objcopy


CFLAGS    := -std=c99 -Wall -Wextra -g -Os -fdata-sections -ffunction-sections -mmcu=$(MCU) -DF_CPU=$(F_CPU)
CPPFLAGS  := $(INCLUDES:%=-I%)
LDFLAGS   := -Xlinker --gc-sections -Xlinker -Map=$(EXEC).map -Xlinker --relax #-Xlinker --strip-all



OBJS	      	:= $(SOURCES:.c=.o) #For every .c file associate a .o (object)       file
PREPROCESSED	:= $(SOURCES:.c=.i) #For every .c file associate a .i (preprocessed) file
ASSEMBLIES	:= $(SOURCES:.c=.s) #For every .c file associate a .s (Assembly)     file
DEPENDENCIES	:= $(SOURCES:.c=.o.d)
TESTSOBJS	:= $(TESTS:.c=.o)


module_name	:=
EXEC		:= out
MAINFUNC	:=


#RULES
#######################################################################################################


#`make all` for build and flash
.PHONY: all
all: $(EXEC).hex
	make flash



#`make build-all` for building all the executable files 
.PHONY: build-all
build-all:
	make compile-all
	$(foreach i, $(TESTS), make build EXEC=$(shell basename -s .c $(i)) MAINFUNC=$(i);)



#`make build` for build only 
.PHONY: build
build: 		$(EXEC).elf $(EXEC).lss $(EXEC).hex



#`make hex`  for generating hex file only
.PHONY: hex
hex:   		$(EXEC).hex



#`make compile-all` for compiling all source files
.PHONY: compile-all
compile-all: 	$(OBJS) $(TESTSOBJS)



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
	avrdude -p $(MCU) -c usbasp -U flash:w:$(EXEC).hex:i -F -P usb




#`make EXECUTABLENAME.lss` for generating Extended listing
$(EXEC).lss: $(EXEC).elf
	@echo Invoking: Avr Extended listing 
	avr-objdump -S -h $< > $@




#`make EXECUTABLENAME.elf` for generating the elf file
$(EXEC).elf: $(OBJS)
	@echo Building Target: $@
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(MAINFUNC) -o $(EXEC).elf
	avr-size -C $(EXEC).elf





#`make x.o` generate an object file, x.o from source file, x.c,.
%.o:%.c
	@echo Compiling ---------------------------------------- $@
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) -MMD -MP -MT$@ -MF$@.d $< -o $@



#`make x.asm` generate an assembly file, x.asm from source file, x.c,.
%.asm:%.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@



#`make x.i` generate a preprocessed file, x.i from source file, x.c,.
%.i:%.c
	$(CC) -E $(CFLAFS) $(CPPFLAGS) $< -o $@



#`make x.hex` generate an object file, x.hex from elf file, x.elf,.
%.hex:%.elf
	@echo Genrating hex file --------------------------------- $@
	$(OBJCOPY) -j .text -j .data -O ihex $< $@


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
	$(module_name)_programg.c \
	$(module_name)_register.h \
	$(module_name)_private.h


.PHONY: test
test:
	@echo The Sources  are:  $(SOURCES)
	@echo
	@echo The Includes are:  $(INCLUDES)
	@echo
	@echo The objects  are:  $(OBJS)
	@echo Test files are: $(TESTSOBJS)


.PHONY: clean
clean:
	rm -rf $(OBJS) $(PREPROCESSED) $(ASSEMBLIES) $(DEPENDENCIES) \
	*.out *.map *.elf *.map *.hex *.s *.i *.d *.lss *.o *.obj
