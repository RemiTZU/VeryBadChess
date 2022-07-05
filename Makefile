#my general makefile template
CXX = gcc.exe #Path to the C Compiler executable
CFLAGS = -Wall -Werror -pedantic -fpic -g #C Compiler options used from compilation
LIBSDIR = -L.  #List of direcotries containing libraries
INCLUDEDIR = -I. #List of direcotries containing headers


#Library-related macros
LIBCORENAME = VeryBadChess #Core name of the library that must be generated
LIBTARGET :=$(LIBCORENAME:=.dll) #adding the "lib" prefix and the .so extension to LIBCORENAME
LIBSOURCE = affichage echiquier jeu sauvegarde #list of .c files composing the library without extension
LIBSOURCECFILE = $(LIBSOURCE:=.c) #adding .c extensions to all files listed in LIBSOURCE variable
LIBSOURCEOFILE = $(LIBSOURCE:=.o) #adding .o extensions to all files listed in LIBSOURCE variable

#Application-related macros
EXESOURCE = main #name of source files containing the main function
TARGET = $(EXESOURCE:=.exe) #Name of the final executable
EXESOURCECFILE = $(EXESOURCE:=.c) #adding .c extensions to all files listed in EXESOURCE variable
EXESOURCEOFILE = $(EXESOURCE:=.o) #adding .o extensions to all files listed in EXESOURCE variable

#Color settings for text messages according to terminal color table: black=0, red=1, green=2, yellow=3, blue=4, magenta=5, cyan=6, white=7     

#Notice: To override the content of the LD_LIBRARY_PATH environment variable use
# export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
#or the script exportLD.sh provided with this makefile

#############################################################################################################
############################### TARGETS #####################################################################
#############################################################################################################

#Running the program, default target
run: $(TARGET)
	
	@echo "\n Running the executable " $(TARGET)
	export.bat $(TARGET)

#Compiling everything to generate the executable and the library
all: $(TARGET) 

#Generating the executable
$(TARGET): $(EXESOURCEOFILE) $(LIBTARGET)
	
	@echo "\n Generating the executable " $@ "from " $<
	$(CXX) $(EXESOURCEOFILE) -l$(LIBCORENAME) $(LIBSDIR) -o $(TARGET) -lm

#Generating the library binary code
$(LIBTARGET): $(LIBSOURCEOFILE)
	
	@echo "\n Generating the library binary code (shared lib .dll on Windows or .so on Linux) from object files (.o) " $@
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o $(LIBTARGET)

#Generating an object file from a C file having the same name
.c.o:
	
	@echo "\n Generating object file (.o)" $@ " from c source file (.c)" $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

#Cleaning the content of the current directory
clean:
	@del /q /s *.o *.dll *.exe
	@echo CLEAN

	

