# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./include/

# Directories
SRCDIR = src
INCLUDEDIR = include
BINDIR = bin

# Find all source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Replace the .cpp extension with .o to get object file names
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Executable name
TARGET = $(BINDIR)/robotic_arm_simulator

# Default target
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Linking complete. Executable is at $(TARGET)"

# Rule to compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@echo "Compiled $< into $@"

# Clean up build files
clean:
	@rm -rf $(BINDIR)
	@echo "Cleaned up build artifacts."

# Phony targets
.PHONY: all clean
