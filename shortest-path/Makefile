# http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
# http://www.puxan.com/web/howto-write-generic-makefiles/

# complier options
CC = g++
CC_FLAGS = -w
 
# File names
SRC_DIR = src
OBJ_DIR = obj
EXEC = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(subst $(SRC_DIR), $(OBJ_DIR), $(_OBJECTS))

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To obtain object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)