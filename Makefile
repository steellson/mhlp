CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
FRAMEWORKS = -framework CoreFoundation -framework CoreGraphics
TARGET = mhlp

SOURCES = main.cpp \
          src/scroll/scroll.cpp \
          src/click/click.cpp \
          src/move/move.cpp \
		  src/sleep/tsleep.cpp \
		  src/screen/screen.cpp

HEADERS = src/scroll/scroll.h \
          src/click/click.h \
          src/move/move.h \
		  src/sleep/tsleep.h \
		  src/screen/screen.h

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(FRAMEWORKS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
