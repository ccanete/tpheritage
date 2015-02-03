#echo : "Command make is in execution"
# List variables
COMP = g++
CFLAGS = -ansi -v
ECHO = echo
OBJ = $(SRC:.cpp=.o)
SRC = $(wildcard *.cpp)
EXE = Main
EXEC = main

all: $(EXE)
# Rule to the main
$(EXE): $(OBJ)
	@$(ECHO) "Compliation of <$(EXE)>"
	$(COMP) -o $(EXEC) $(OBJ)
# Pattern Rule 
%.d: %.cpp
	@set -e; rm -f $@; \
	$(COMP) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
# Include
include $(SRC:.cpp=.d)
# Rule to clean
.PHONY: clean

clean:
	rm -rf *.o $(EXE) *.d