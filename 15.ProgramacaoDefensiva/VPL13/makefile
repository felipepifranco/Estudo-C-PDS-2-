TARGET = main

CC = g++
FLAGS = -std=c++11 -Wall -Wextra -g -I.


OBJ_DIR = objetos
DEP_DIR = dependencias


SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(patsubst %.cpp, $(DEP_DIR)/%.d, $(SRCS))


DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

# criar as pastas objetos e dependencias caso elas não existam
$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

# Incluindo dependencias
-include $(DEPS)


clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR) $(TARGET)

.PHONY: all clean