# Compilation settings
CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
OUT_DIR = output
OBJ = main.o animal.o fichier.o search.o
OBJS = $(addprefix $(OUT_DIR)/, $(OBJ))
EXE = $(OUT_DIR)/refuge

# Default target
all: $(OUT_DIR) $(EXE)

# Create output directory if it doesn't exist
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Link object files to create executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

# Compilation rules
$(OUT_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $@

$(OUT_DIR)/animal.o: $(SRC_DIR)/animal.c $(SRC_DIR)/animal.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/animal.c -o $@

$(OUT_DIR)/fichier.o: $(SRC_DIR)/fichier.c $(SRC_DIR)/fichier.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fichier.c -o $@

$(OUT_DIR)/search.o: $(SRC_DIR)/search.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/search.c -o $@

# Clean rule
clean:
	rm -f $(OUT_DIR)/*.o $(EXE)