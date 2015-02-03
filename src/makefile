#echo : "Command make is in execution"
# List variables
COMP = g++
CFLAGS = -ansi -v
ECHO = echo
OBJ1 = $(SRC:.cpp=.o)
OBJ2 = $(COM:.cpp=.o)
SRC = $(wildcard Models/*.cpp)
COM = $(wildcard Command/*.cpp)
EXE = Application
EXEC = main

all: $(EXE)
# Rule to the main
$(EXE): $(OBJ1) $(OBJ2) $(EXE).cpp
	@$(ECHO) "Compliation of <$(EXE)>"
	$(COMP) $(CFLAGS) -o $(EXEC) $(EXE).cpp $(OBJ1) $(OBJ2)
# Pattern Rule 
%.d: %.cpp
	@set -e; rm -f $@; \
	$(COMP) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
# Include
include $(SRC:.cpp=.d)
include $(COM:.cpp=.d)
# Rule to clean
.PHONY: clean

clean:
	rm -rf *.o Command/*.o Command/*.d Models/*.o Models/*.d $(EXEC) *.d