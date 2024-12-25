# ---------------------------------------------------------
# Makefile for a simple multi-file C++ project
# with separate src/ and include/ directories,
# storing object files in build/ directory.
# ---------------------------------------------------------

# 1) Compiler and flags
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# 2) Project structure
SRCDIR   = src
INCDIR   = include
BUILDDIR = build

# 3) Gather all .cpp files in src/
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)

# Convert each .cpp in src/ to a corresponding .o in build/
OBJECTS  = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# 4) Final executable name
TARGET   = project

# ---------------------------------------------------------
# Default rule (build the program by default)
all: $(TARGET)

# Link step: create the executable from object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Compile step: .cpp -> .o
# We store .o in the build/ folder
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the build/ directory exists before compiling
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# ---------------------------------------------------------
# Clean rule to remove build artifacts
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
# Jeśli chcesz usuwać cały katalog build/:
#   rm -rf $(BUILDDIR)

# Optional: declare phony targets
.PHONY: all clean
