#Makefile

CXX = g++
CXXFLAGS = -std=c++17 -I/usr/include
#LDFLAGS = -lpthread -lboost_system

TARGET = calculator
SRC = app.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = /home/ruh/web_calculator/test.cpp
TEST_EXEC = test

all: test $(TARGET)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(BOOST_LIBS) -o $(TEST_EXEC) $^ $(LDFLAGS)
	./$(TEST_EXEC)
	@echo "no problemo"

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
