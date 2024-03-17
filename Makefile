CC := g++
CFLAGS := -Wall -Wextra -Iinclude 
SRCDIR := src
OBJDIR := obj
SRCS := $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET := maze

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
