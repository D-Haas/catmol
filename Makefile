CXX = gcc

CXXFLAGS = -W -Wall -std=c++23 -O2 -march=native -ffast-math

LIBS = -Iinclude -Llib -lncurses -ltinfo -lm -lstdc++
SOURCES = ./src/main.cpp ./src/constants.cpp ./src/vector/vector.cpp ./src/window/window.cpp ./src/xyz/xyz.cpp ./src/customization/customization.cpp

TARGET = catmol

PREFIX = /usr/local/bin

# catmol: main.cpp constants.cpp ...
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

install: $(TARGET) # Needs sudo
	install -d $(PREFIX)
	install -m 755 $(TARGET) $(PREFIX)

uninstall: # Needs sudo
	rm -f $(PREFIX)/$(TARGET)

.PHONY: clean install uninstall
