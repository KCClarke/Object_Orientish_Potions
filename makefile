CC      = gcc
CFLAGS  = -std=c99 -g -I. -Wall -MMD -MP
TARGET  = potions

SRC     = $(wildcard *.c)
OBJ     = $(SRC:.c=.o)
DEPDIR  = .deps
DEP     = $(OBJ:%.o=$(DEPDIR)/%.d)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

# Build object files and move dependency files into .deps/
%.o: %.c | $(DEPDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	mv $*.d $(DEPDIR)/

$(DEPDIR):
	mkdir -p $@

-include $(DEP)

.PHONY: clean
clean:
	rm -rf $(OBJ) $(DEPDIR) $(TARGET)
