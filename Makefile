CXX = g++
CXXFLAGS = -std=c++17 -I./crow -I.
LDFLAGS = -lpthread -lboost_system -lboost_unit_test_framework

TARGET = calculator
SRC = app.cpp
TEST_SRC = test.cpp calc.cpp
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: test $(TARGET)

$(TARGET): $(OBJ)
	@echo "Building main application..."
	$(CXX) -o $@ $^ $(LDFLAGS)

test: $(TEST_OBJ)
	@echo "Running tests..."
	$(CXX) -o test_runner $^ $(LDFLAGS)
	./test_runner

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean test

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) test_runner
