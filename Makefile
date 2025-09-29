CXX = gcc

CXXFLAGS = -W -Wall -std=c++23 -O2

LIBS = -Iinclude -Llib -lncurses -ltinfo -lm -lstdc++
SOURCES = ./src/main.cpp ./src/constants.cpp ./src/vector/vector.cpp ./src/window/window.cpp ./src/xyz/xyz.cpp ./src/customization/customization.cpp

TARGET = main

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
