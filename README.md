# Structure

- I used layer architecture for developing the drivers and the HALs of the atmega32 microcontroller.

## Module Structure

- Every folder in the `MCAL` or `HAL` folders is considered as a module.
- Every module contains 5 files:
	1. `MODULE_interface.h `: Contains the interface of the module like functions prototypes 
		and structure types. 
	2. `MODULE_program.c   `: Contains the implementations and details of the module.
	3. `MODULE_register.h  `: A register definition file that contains registers names and their map
		either in the microcontroller or in an external device.
	4. `MODULE_config.h    `: Contains the pre-build configurations of the module.
	5. `MODULE_private.h   `: Contains definitions private to the module.
	6. `MODULE_test.c      `: Contains tests for the module only. *(Note: It has a main function.)*

# How to use
	
	This Project has multiple main functions. We can compile source files, but can link only with one 
	source file that has a main function.
	
## Options for compiling, linking, building, and flashing.

1. `make compile-all` : 

   Compiles all source file that has no `main` function. 
   *(It only compiles the `_program.c` source files)*


2. `make build-all`   : 
   1. Compiles all source files that has no `main` function.
   2. For every source file that has the `main` function, Compile it and Link it with other object files.
	  Then Generate its corresponding executable. *(Usually `.elf` and `.hex` format)* 


3. `make flash EXEC=*flash_name*`:
   
   Flashes the `.hex` file to the microcontroller.
   The `EXEC` variable must be specified because we have multiple executables.
   > (**Note**:*`flash_name` must be without any suffixes*)
   
   
4. `make clean`: Cleans all the generated files.
5. `make docs` : Generate documentation files.


## Examples
To build all the executables and flash the `MPU6050_test.hex`, just do as the following:

```
$ make build-all && make all EXEC=MPU6050_test
```
