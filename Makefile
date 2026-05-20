# Makefile universel - Ne change rien ici
CXX = ppu-g++
LDFLAGS = -shared -Wl,--no-undefined -Wl,--gc-sections
CFLAGS = -O2 -fno-builtin-printf -fno-exceptions -fno-rtti -std=c++11

# Cette ligne trouve automatiquement tous tes fichiers .cpp
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

TARGET = ParishedSPRX.sprx

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
