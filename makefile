CC = g++
FLAGS = -g -c

SOURCEDIR = src
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

EXECUTABLE = $(BUILDDIR)/main
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: dir $(EXECUTABLE)

dir:
	mkdir -p $(BUILDDIR) $(OBJDIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) $(FLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)
