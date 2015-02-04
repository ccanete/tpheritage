# Compilation binaries
CC = g++
CFLAGS = -DMAP -g -std=c++11 #-stdlib=libc++
LNFLAGS =
ARFLAGS =

# Sources
<<<<<<< Updated upstream
MODELS_SRC = Figure.cpp Circle.cpp Point.cpp Line.cpp Polyline.cpp Rectangle.cpp Selection.cpp
COMMAND_SRC = DrawController.cpp Command.cpp AddCommand.cpp RemoveCommand.cpp MoveCommand.cpp
=======
MODELS_SRC = Circle.cpp Figure.cpp Point.cpp Line.cpp Polyline.cpp Rectangle.cpp Selection.cpp
COMMAND_SRC = DrawController.cpp Command.cpp RemoveCommand.cpp MoveCommand.cpp
>>>>>>> Stashed changes
APPLICATION_SRC = Application.cpp

# Objects
MODELS_OBJECTS = $(MODELS_SRC:%.cpp=build/Models/%.o)
CONTROLLERS_OBJECTS = $(COMMAND_SRC:%.cpp=build/Command/%.o)
APPLICATION_OBJECT = $(APPLICATION_SRC:%.cpp=build/%.o)

# Make-specific rules
.PHONY: clean test ptest

# Rules
## Build Directory
build: build/tp-heritage

### Binary build
build/tp-heritage: $(APPLICATION_OBJECT) $(MODELS_OBJECTS) $(CONTROLLERS_OBJECTS)
	$(CC) $(LNFLAGS) -o build/tp-heritage $(APPLICATION_OBJECT) $(MODELS_OBJECTS) $(CONTROLLERS_OBJECTS)

## Run
run: build/tp-heritage
	build/tp-heritage


## Cleaner
clean:
	rm -r build

# Patterns
## C++ Compilation
build/%.o: src/%.cpp
	mkdir -p `dirname $@`
	$(CC) -c $(CFLAGS) -o $@ $<
