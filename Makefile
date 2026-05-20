# Makefile pour le Mod Menu ADF PS3

CC = ppu-gcc
CXX = ppu-g++
OBJCOPY = ppu-objcopy

CFLAGS = -O2 -ffunction-sections -fdata-sections -fno-builtin-printf -fno-exceptions -fno-rtti -std=c++11
LDFLAGS = -shared -Wl,--no-undefined -Wl,--gc-sections

# Liste de tes fichiers sources
SOURCES = main.cpp menu.cpp menufuncs.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = ADF_Menu.sprx

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)
