SOURCES   := $(shell find . -name "*program.c")
INCLUDES  := $(shell find . -name "*.h")

MCU       := atmega32
F_CPU     := 8000000ul

CC        := avr-gcc
CFLAGS    := -std=c99 -Wall -Wextra -g -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
CPPFLAGS  := -I$(INCLUDES)



OBJS      := $(patsubst %.c, %.o, $(SOURCES))


module_name=


compile-all: $(OBJS)


all:
	$(CC) $(CFLAGS) $(OBJS)

%.o:%.c
	$(CC)  $(CFLAGS)  -c -o $@  $<


module:
	@test $(module_name) || \
	(echo "Enter the path followed by the module name. i.e MCAL/moduleX"; exit 1)

	@mkdir -p $(shell dirname ${module_name}) 
	@touch $(module_name)_config.h \
	$(module_name)_interface.h \
	$(module_name)_programg.c \
	$(module_name)_register.h \
	$(module_name)_private.h

test:
	@echo $(SOURCES)
	@echo $(OBJS)



clean:
	rm -rf $(OBJS)
