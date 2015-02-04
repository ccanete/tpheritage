# Compilation binaries
CC = g++
CFLAGS = -DDEBUG -g -std=c++11 #-stdlib=libc++
LNFLAGS =
ARFLAGS =

# Sources
MODELS_SRC = Circle.cpp Figure.cpp Point.cpp Line.cpp Polyline.cpp Rectangle.cpp Selection.cpp
COMMAND_SRC = DrawController.cpp Command.cpp AddCommand.cpp RemoveCommand.cpp MoveCommand.cpp
APPLICATION_SRC = Application.cpp

# Objects
MODELS_OBJECTS = $(MODELS_SRC:%.cpp=build/models/%.o)
CONTROLLERS_OBJECTS = $(COMMAND_SRC:%.cpp=build/controllers/%.o)
APPLICATION_OBJECT = $(APPLICATION_SRC:%.cpp=build/%.o)

# Make-specific rules
.PHONY: clean test ptest

# Rules
## Build Directory
build: build/cmd-draw

### Binary build
build/cmd-draw: $(APPLICATION_OBJECT) $(MODELS_OBJECTS) $(CONTROLLERS_OBJECTS)
	$(CC) $(LNFLAGS) -o build/cmd-draw $(APPLICATION_OBJECT) $(MODELS_OBJECTS) $(CONTROLLERS_OBJECTS)

## Run
run: build/cmd-draw
	build/cmd-draw


## Cleaner
clean:
	rm -r build

# Patterns
## C++ Compilation
build/%.o: src/%.cpp
	mkdir -p `dirname $@`
	$(CC) -c $(CFLAGS) -o $@ $<
