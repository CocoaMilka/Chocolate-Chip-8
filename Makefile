# Makefile for CHIP-8 Emulator

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = chocolate_chip8_emulator

# Source and object file directories
SRCDIR = src
OBJDIR = obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

.PHONY: all clean rebuild
