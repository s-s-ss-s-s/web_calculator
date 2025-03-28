# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -I/path/to/boost/include
LDFLAGS = -lpthread -lboost_system

TARGET = calculator
SRC = calculator.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean                                                                                                                                                                                                                                  CXX = g++                                                                                                               CXXFLAGS = -std=c++17 -I/usr/include/boost                                                                              LDFLAGS = -lpthread -lboost_system                                                                                                                                                                                                              TARGET = calculator                                                                                                     SRC = calculator.cpp                                                                                                    OBJ = $(SRC:.cpp=.o)                                                                                                                                                                                                                            all: $(TARGET)                                                                                                                                                                                                                                  $(TARGET): $(OBJ)                                                                                                               $(CXX) -o $@ $^ $(LDFLAGS)                                                                                                                                                                                                              %.o: %.cpp                                                                                                                      $(CXX) $(CXXFLAGS) -c $< -o $@                                                                                                                                                                                                          clean:                                                                                                                          rm -f $(OBJ) $(TARGET)                                                                                                                                                                                                                  .PHONY: all clean   
