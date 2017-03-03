# http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
# http://www.puxan.com/web/howto-write-generic-makefiles/

# all: library.cpp main.cpp
# In this case:
# 	$@ evaluates to all
# 	$< evaluates to library.cpp
# 	$^ evaluates to library.cpp main.cpp


# complier options
CC = g++
CC_FLAGS = -w

# directory names
SRC_DIR = src
OBJ_DIR = obj
EXE_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(subst $(SRC_DIR), $(OBJ_DIR), $(_OBJECTS))

# build all
build: $(EXE_DIR)/base1 $(EXE_DIR)/base2

	@echo ====== Build Completed ======
# To remove generated files
clean:
	rm -f $(OBJECTS) $(EXE_DIR)/*
	@echo ======      Clean      ======

# build baseline 1
$(EXE_DIR)/base1: $(filter-out obj/acquireLinks.o , $(OBJECTS))
	mkdir -p $(EXE_DIR)
	$(CC) $^ -o $@

# build baseline 2
$(EXE_DIR)/base2: $(filter-out obj/functions.o , $(OBJECTS))
	mkdir -p $(EXE_DIR)
	$(CC) $^ -o $@

# build main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CC_FLAGS) $< -o $@

# build acquireLinks.o used in baseline 2
$(OBJ_DIR)/acquireLinks.o: $(SRC_DIR)/acquireLinks.cpp $(SRC_DIR)/functions.h
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CC_FLAGS) $< -o $@

# build all .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CC_FLAGS) $< -o $@