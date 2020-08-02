# @file - makefile_template
# @author - Trinity Lundgren <lundgret@oregonstate.edu>, adapted from
#           intermediate_make_sample by Harlan James <waldroha@oregonstate.edu>
# @description - Template for general-pupose Makefile to use for CS162 projects

# Project name
project = FinalProject

# Compiler
CXX = g++

# Source files
sources = main.cpp menu.cpp inputValidation.cpp Game.cpp Player.cpp Zebes.cpp \
		  Space.cpp Ceres.cpp Crateria.cpp Brinstar.cpp Norfair.cpp \
		  WreckedShip.cpp Maridia.cpp Tourian.cpp

# Create objects from source files
objects = $(sources:.cpp=.o)

# Output executable
EXE = $(project)

# Compiler flags
CFLAGS = -Wall -pedantic -std=gnu++11

#Valgrind options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Phony targets
.PHONY: default debug clean zip

# Default behavior: clean, compile, pass through valgrind
default: clean $(EXE) #debug # Debug is toggled off for submission

# Debug: pass to valgrind to check for memory leaks
debug: $(EXE)
	valgrind $(VOPT) ./$(EXE)

# '$@' refers to tag, '$^' to dependency
$(EXE) : $(objects)
	$(CXX) $(CFLAGS) $^ -o $@

# Create .o files from corresponding .cpp files
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^

# Create a zip archive of the project files for submission
zip:
	zip $(project)_Lundgren_Trinity.zip *.cpp *.hpp Makefile *pdf

clean:
	rm -f *.o *.zip $(EXE)
