CC := gcc
SRCDIR := src
BUILDDIR := build
TARGET := bin/run
TARGET_LIB := lib/libnyan.a
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -c
LIB := -L lib
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
#	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB) -O3
	@echo " ar -rcs $(TARGET_LIB) $^"; ar -rcs $(TARGET_LIB) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building..."
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $< -save-temps -O3

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TARGET_LIB)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TARGET_LIB)

# Tests
tester:
	$(CC) $(INC) $(LIB) -o bin/test test/test.c -lnyan

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean