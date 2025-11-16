CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
FRAMEWORKS = -framework CoreFoundation -framework CoreGraphics
TARGET = mhlp

SOURCES = main.cpp \
		  src/process/process.cpp \
          src/tools/scroll/scroll.cpp \
          src/tools/click/click.cpp \
          src/tools/move/move.cpp \
		  src/tools/sleep/tsleep.cpp \
		  src/tools/screen/screen.cpp

HEADERS = src/process/process.h \
		  src/tools/scroll/scroll.h \
          src/tools/click/click.h \
          src/tools/move/move.h \
		  src/tools/sleep/tsleep.h \
		  src/tools/screen/screen.h

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
