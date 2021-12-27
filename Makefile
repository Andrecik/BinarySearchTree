################################### Makefile ###################################
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

#name the executable
EXE := Binarysearchtree


#Creates a list of source files
SRC := $(wildcard $(SRC_DIR)/*.cc)

#Creates a list of objectfiles from souce files
OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

#Compiler Settings
CC = g++
INCLUDES := -I/src/include
CXXFLAGS := -Wall -Wextra -std=c++17
LDFLAGS :=#Linker settings
LDLIBS :=#for thirdpart library 
DEBUG := -D DEBUG

#we tell makefile that alla nad clean are not real tagets
.PHONY: all debug clean

all: clean no_debug $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)	
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)


debug: clean debug_compile $(EXE)

debug_compile:
    $(eval CXXFLAGS += $(DEBUG))

no_debug:
	$(eval CXXFLAGS := -Wall -Wextra -std=c++17)

-include $(OBJ:.o=.d)
